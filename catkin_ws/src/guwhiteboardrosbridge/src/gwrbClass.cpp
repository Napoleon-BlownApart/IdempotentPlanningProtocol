/**
 *  @file gwrbClass.cpp
 *
 *  ./GUNao/posix/guWhiteboardROSbridge
 *
 *  Created by
 *  @author   Dimitri Joukoff
 *
 *  @version  1.0.0
 *  @date     2014/06/05
 *
 *  Version History<br />
 *  1.0.0 | 06/05/2014 | The guWhiteboardROSbridge's interfacing to the
 *                        Whiteboard is based on the guWhiteboardMonitor<br />
 *
 *
 * ============================================================================
 *
 * The purpose of the guWhiteboardROSbridge ("Bridge") is to enable full-duplex
 * exchange of Whiteboard Class messages between the GU Whiteboard and ROS.<br />
 *
 * The **Bridge** is able to broker messages of all the Whiteboard's Classes
 * included in the *guwhiteboardtypelist.tsl* file.<br />
 *
 * **Whiteboard => ROS**
 * By default, the **Bridge** establishes a global Whiteboard subscription to
 * all Whiteboard message types using *kwb_reserved_SubscribeToAllTypes_v*.<br />
 * When a Whiteboard Class message is posted to the Whiteboard, the
 * *whiteboard_watcher* object issues a callback to the subscriber callback
 * *GUWHITEBOARDROSBRIDGE::callback*.  The callback prepares the necessary
 * information and uses a custom queue named "net.mipal.guwhiteboardrosbridge"
 * to synchroniously dispatch the *postMsgROS()* function.
 * The *rosPostMsg()* function, after checking if the current message needs to
 * be forwarded to ROS, serialises the object using it's *description()* method
 * and forwards the resulting string to to ROS by publishing to a ROS TOPIC
 * named after the class.  Each ROS TOPIC uses the *<std_msgs::String>* message
 * type.
 *
 * **Whiteboard <= ROS**
 * By default, the **Bridge** subscribes to an array of ROS TOPICs which cover
 * all the Whiteboard Classes.  The name of each Topic matches the name of the
 * Whiteboard Class and they all use the *<std_msgs::String>* message type.
 * Each Whiteboard Class' ROS TOPIC has its own callback instantiated within an
 * instance of the *rosCallback* class.  Each rosCallback object <ul>
 * <li>is aware of the message type it handles,</li>
 * <li>maintains a small set of Echo Cancellation state variables,</li>
 * <li>performes it own echo cancellation on the ROS side of the **Bridge**,</li>
 * <li>Posts incoming messages to the Whiteboard using the
 * *guWhiteboard::postmsg()* method, and</li>
 * <li>maintains usage statistics.</li></ul>
 * The callback prepares the necessary information and uses a custom queue named
 * "net.mipal.guwhiteboardrosbridge" to synchroniously dispatch the *postMsgWB()*
 * function.
 *
 *=============================================================================
 */

/*
 *  Copyright 2014 Dimitri Joukoff, Griffith University
 *  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgement:
 *
 *        This product includes software developed by Rene Hexel.
 *
 * 4. Neither the name of the author nor the names of contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * -----------------------------------------------------------------------
 * This program is free software; you can redistribute it and/or
 * modify it under the above terms or under the terms of the GNU
 * General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see http://www.gnu.org/licenses/
 * or write to the Free Software Foundation, Inc., 51 Franklin Street,
 * Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif //_GNU_SOURCE

#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <functional>   // std::bind
#include <ros/ros.h>
#include "std_msgs/String.h"

#include <signal.h>
#include <time.h> // time_t

#include "gwrbClass.h"
#include "guwhiteboardtypelist_c_generated.h"


using namespace std;
using namespace guWhiteboard;
//using namespace ros;

/**
 * Counter Array that tracks the number of messages forwarded to ROS from the
 * Whiteboard by Message Type, thus Echos are not included in this count.
 *
 */
static int receivedMsgsWB[GSW_NUM_TYPES_DEFINED]; // reports number of messages received from WB publishers

/**
 * Counter Array that tracks the number of times the Whiteboard Callback is
 * received per message type with the Echo Cancellation Variables indicating
 * this callback is an Echo but the Whiteboard event counter has already
 * advanced.
 *
 * Since the integrity of these messages is in question, they are not sent
 * back into ROS.
 *
 */
static int wbWatcherTooSlowWB[GSW_NUM_TYPES_DEFINED]; // reports how many times this message type wasn't forwarded

/**
 * Counter Array that tracks the number of Whiteboard Echos of ROS messages that
 * are cancelled on the Whiteboard side of the **Bridge** per message type.
 *
 */
static int echoCancelledROS[GSW_NUM_TYPES_DEFINED]; // reports number of echos cancelled whose origin were in ROS

/**
 * pointer to gu_simple_whiteboard_descriptor structure (gusimplewhiteboard.h)
 * which manages the Whiteboard.
 *
 */
gu_simple_whiteboard_descriptor* _wbd;

/**
 * pointer to the actual Whiteboard shared memory.
 *
 */
gu_simple_whiteboard* wb;

/**
 * The dispatch queue used to sequence callback processing of messages received
 * both in the Whiteboard and ROS
 *
 * wrbCallbackQueue_ptr makes the queue available to other modules.
 */
dispatch_queue_t wrbCallbackQueue;
dispatch_queue_t* wrbCallbackQueue_ptr;

/**
 * Flag that indicates whether the guWhiteboardROSbridge is running or not
 *
 */
bool rosRunning; // set true when ros is initialised successfully.


/**
 * Reports whether ROS is running or not.
 *
 */
bool GUWHITEBOARDROSBRIDGE::isROSRunning() {
  return rosRunning;
}


// ONLY USED DURING DEVELOPMENT
//int GUWHITEBOARDROSBRIDGE::getWBMissedMessages(int msgType) {
//	//Production watcher does not have this function
//	return watcher->getMissedMessages(msgType);
//}


/**
 * Reports how many new messages of this type were received in the **Bridge** on
 * the Whiteboard side of the **Bridge** from a Whiteboard publisher.
 *
 * @param[in] int msgType<br />
 * The (int) guWhiteboard::WBTypes of the message type to report on.
 *
 */
int GUWHITEBOARDROSBRIDGE::getReceivedMessagesWB(int msgType) { // From WB in WB
  return receivedMsgsWB[msgType];
}


/**
 * Reports how many Echos were cancelled for this message type on the ROS side
 * of the **Bridge**. (IE a message that originated from a Whiteboard publisher
 * has been forwarded to ROS, but, since the **Bridge** also subscribes to the
 * same ROS Topic, we don't want to inject the same message back into the
 * Whiteboard side of the **Bridge**.
 *
 * At the end of a run, this should equal the number of new messages received
 * from the Whiteboard.
 *
 * @param[in] int msgType<br />
 * The (int) guWhiteboard::WBTypes of the message type to report on.
 *
 */
int GUWHITEBOARDROSBRIDGE::getEchoCancelledWB(int msgType) { // From WB in ROS
  if (rosCallbackList[msgType]) {
    return rosCallbackList[msgType]->getEchosCancelledWB();
  } else {
    return 0;
  }
}


/**
 * Reports how many new messages of this type were received on the ROS side of
 * the **Bridge** from a ROS publisher.
 *
 * @param[in] int msgType<br />
 * The (int) guWhiteboard::WBTypes of the message type to report on.
 *
 */
int GUWHITEBOARDROSBRIDGE::getReceivedMessagesROS(int msgType) { // From ROS in ROS
  if (rosCallbackList[msgType]) {
    return rosCallbackList[msgType]->getReceivedMsgsROS();
  } else {
    return 0;
  }
}


/**
 * Reports how many Echos were cancelled for this message type on the Whiteboard
 * side of the **Bridge**. (IE a message that originated from a ROS publisher
 * has been forwarded to the Whiteboard, but, since the **Bridge** also
 * subscribes to the same Whiteboard message type, we don't want to inject the
 * same message back into the ROS side of the **Bridge**.
 *
 * At the end of a run, this should equal the number of new messages received
 * from the ROS.  Any discrepancies should be accounted for by
 * *getWB_WatcherTooSlowWB()* and/or *getWB_WatcherTooSlowROS()*
 *
 * @param[in] int msgType<br />
 * The (int) guWhiteboard::WBTypes of the message type to report on.
 *
 */
// From ROS in WB
int GUWHITEBOARDROSBRIDGE::getEchoCancelledROS(int msgType) {
  return echoCancelledROS[msgType];
}


/**
 * Reports how many times this message type wasn't forwarded into ROS by the
 * **Bridge** because the **Bridge** was expecting the message to have originated
 * on the ROS side.  (IE *rosMsg* flag was true when this message was being
 * processed, but the WB_EVENT_COUNTER had advanced since the message was posted
 * by the ROS side of the **Bridge**.)
 *
 * Since the integrity of the message is in question, don't send it.
 *
 * @param[in] int msgType<br />
 * The (int) guWhiteboard::WBTypes of the message type to report on.
 *
 */
int GUWHITEBOARDROSBRIDGE::getWB_WatcherTooSlowWB(int msgType) {
  return wbWatcherTooSlowWB[msgType];
}


/**
 * Reports how many times this message type's Echo Cancellation state variables
 * weren't reset in time by the WB Callback.  Unlike the above case, the message
 * is still forwarded if it did not originate from the WB.
 *
 * In ROS, the identity of the publisher is available, so it's safe to forward.
 *
 * @param[in] int msgType<br />
 * The (int) guWhiteboard::WBTypes of the message type to report on.
 *
 */
int GUWHITEBOARDROSBRIDGE::getWB_WatcherTooSlowROS(int msgType) {
  if (rosCallbackList[msgType]) {
    return rosCallbackList[msgType]->getwbWatcherTooSlowROS();
  } else {
    return 0;
  }
}


/**
 * ROS, by default, installs a SIGINT handler.  This custom SIGINT handler is
 * used to enable graceful exit from the **Bridge** when Ctrl-C is pressed.
 *
 */
static void sigSIGINThandler(int sigNum, siginfo_t *siginfo, void *context) {

  if ( (rosRunning) || ros::ok()) {
    rosRunning = false;
    cerr << endl << "Shutting Down ROS" << endl;
    ros::shutdown();
  }
}


/**
 * The GUWHITEBOARDROSBRIDGE constructor sets up the GUWHITEBOARDROSBRIDGE
 * object.<br />
 *
 * It locks *sMutex* to ensure that Callbacks generated by the
 * whiteboard_watcher object do not pre-empt its completion (if the whiteboard
 * is already running).
 *
 * The initialisation sequence is as follows:<ul>
 * <li>Creates a new whiteboard_watcher object and gets a pointer to it,</li>
 * <li>Sets the silent/verbose mode flag,</li>
 * <li>Initialises ROS and sets up the custom SIGINT handler,</li>
 * <li>Initialises the Whiteboard subscription(s),</li>
 * <li>Initialises the ROS publishers and subscribers for each ROS Topic and
 *  creates a *rosCallback* object for each Topic,</li></ul>
 * *sMutex* is unlocked once the above has been completed and the
 * GUWHITEBOARDROSBRIDGE object enters a loop that services ROS callbacks while
 * ROS is running (IE *ros::ok()* == true).
 *
 * @param[in] char **subscription_list = NULL<br />
 * Space separated list of Whiteboard message types to subscribe to using string
 * names found in *guwhiteboardposter.cpp* *whiteboard_types_map()*.<br />
 * Not supplying this parameter will make the **Bridge** subscribe to all types.
 * @param[in] int subListSize = 0<br />
 * The number of subscription_list entries being passed.
 * @param[in] bool verboseMode = false<br />
 * true  = print messages when they arrive through the Whiteboard.<br />
 * false = do not print messages. (Better performance)<br />
 * **NOTE**  Printing is only occurs when messages arrive via the Whiteboard
 * side of the **Bridge**, since all messages pass through both interfaces.
 *
 */
GUWHITEBOARDROSBRIDGE::GUWHITEBOARDROSBRIDGE(char **subscription_list = NULL, int subListSize = 0, bool verboseMode = false) {

  pthread_mutex_init(&sMutex, NULL);

  // Lock Mutex during Bridge Setup in case an instance of the Whiteboard is already running.
  pthread_mutex_lock(&sMutex);

  // Create a new whiteboard_watcher object
  watcher = new whiteboard_watcher();
  _wbd =get_local_singleton_whiteboard();
  wb = _wbd->wb;

  wrbCallbackQueue = dispatch_queue_create("net.mipal.guwhiteboardrosbridge", 0);
  wrbCallbackQueue_ptr = &wrbCallbackQueue;

  // Set verbose mode according to parameter
  printMessages = verboseMode;

  // Initialise ROS
  int argc=0;
  char **argv = NULL;
  ros::init( argc, argv, "guWhiteboardROSbridge",ros::init_options::NoSigintHandler);

  // Setup a custom signal handler to enable graceful exit via ctrl-c
  errno = 0;
  struct sigaction ourSIGINTrecord, oldSIGINTrecord;
  if (memset(&ourSIGINTrecord,'\0',sizeof(ourSIGINTrecord)) == NULL) {
    exit(ENOMEM);
  }
  if (memset(&oldSIGINTrecord,'\0',sizeof(oldSIGINTrecord)) == NULL) {
    exit(ENOMEM);
  }
  sigset_t blockMask;
  sigemptyset(&blockMask);
  sigaddset(&blockMask,SIGINT);
  ourSIGINTrecord.sa_mask = blockMask;
  ourSIGINTrecord.sa_flags = SA_NODEFER;
  ourSIGINTrecord.sa_sigaction = &sigSIGINThandler;
  sigaction(SIGINT, NULL, &oldSIGINTrecord); // Read original setting
  if (oldSIGINTrecord.sa_handler != SIG_IGN) {
    sigaction(SIGINT, &ourSIGINTrecord, NULL);
  }
  if (errno != 0) {
    perror("Failed to initialise Signal Handler");
  }

  // Initialise the WB subscription and setup the corresponding ROS callbacks
  int i = 0;
  if (subscription_list) { // if subscription list supplied, subscribe to the message types requested
    while (subListSize--) {
      const char *type_name = *subscription_list++;
      guWhiteboard::WBTypes type = guWhiteboard::types_map[type_name];
      if (!type) {
        cerr << "Cannot subscribe to unknown type " << type_name << endl;
        continue;
      }
      // subscribe to the Whiteboard callback for this message type
      watcher->subscribe(createWBFunctor<GUWHITEBOARDROSBRIDGE>(this, &GUWHITEBOARDROSBRIDGE::callback, type));
      const char *dataName = type_name;
      // setup a ROS NodeHandle for Publishing this message type
      pNodeHandles[type] = new ros::NodeHandle;
      // Advertise the ROS Topic for this message type
      pubList[type] = (pNodeHandles[type])->advertise<std_msgs::String>(dataName,100);
      // setup a ROS NodeHandle for Subscribing to this message type
      sNodeHandles[type] = new ros::NodeHandle;
      // Instantiate a new 'rosCallback' object to handle arrivals of this message type in ROS
      rosCallbackList[type] = new rosCallback(whiteboard_type_for_message_named(dataName));
      // Subscribe to the ROS Topic for this message type
      subList[type] = (sNodeHandles[type])->subscribe(dataName, 100, &rosCallback::generic_ros_callback,rosCallbackList[type]);
      ++i;
    }
    if (!i) exit(EXIT_FAILURE); // exit is something went wrong
    DBG(cout << "Subscribed to " << i << " types" << endl);
    if (printMessages) {
      cerr << "guWhiteboardROSbridge (Dispatch) running with " << i <<" Message Types defined" << endl;
    }
  } else {
    // subscribe to the Whiteboard callback using the global message type
    watcher->subscribe(createWBFunctor<GUWHITEBOARDROSBRIDGE>(this, &GUWHITEBOARDROSBRIDGE::callback, guWhiteboard::kwb_reserved_SubscribeToAllTypes_v));
    // create ROS Topics for all the Whiteboard Message Types
    for (int j=1; j<GSW_NUM_TYPES_DEFINED; j++) { // loop through all the Whiteboard messages types
      const char *dataName = guWhiteboard::WBTypes_stringValues[j];
      // setup a ROS NodeHandle for Publishing this message type
      pNodeHandles[j] = new ros::NodeHandle;
      // Advertise the ROS Topic for this message type
      pubList[j] = (pNodeHandles[j])->advertise<std_msgs::String>(dataName,100);
      // setup a ROS NodeHandle for Subscribing to this message type
      sNodeHandles[j] = new ros::NodeHandle;
      // Instantiate a new 'rosCallback' object to handle arrivals of this message type in ROS
      rosCallbackList[j] = new rosCallback(whiteboard_type_for_message_named(dataName));
      // Subscribe to the ROS Topic for this message type
      subList[j] = (sNodeHandles[j])->subscribe(dataName, 100, &rosCallback::generic_ros_callback,rosCallbackList[j]);
    }
    if (printMessages) {
      cerr << "guWhiteboardROSbridge (Dispatch) running with " << GSW_NUM_TYPES_DEFINED <<" Message Types defined" << endl;
    }
  }
  // Done setting up the Whiteboard ROS Bridge
  rosRunning = true;
  pthread_mutex_unlock(&sMutex);

  int loopRate = (int) (1000000/WHITEBOARD_POLL_PERIOD); // Synchronises the guWhiteboardROSbridge poll time with the guSimpleWhiteboard.
  ros::Rate	loop_rate(loopRate); // 100 Hz = 10mSec
  while (ros::ok()) { // loop while servicing ROS Callbacks
    loop_rate.sleep(); // Sleeps for the remaining time left in the 100Hz loop.
    ros::spinOnce();
  }
}


/**
 * GUWHITEBOARDROSBRIDGE destructor.
 *
 * Shuts down ROS before exiting if its running.
 *
 */
GUWHITEBOARDROSBRIDGE::~GUWHITEBOARDROSBRIDGE() {
  if (ros::ok()) {
    ros::shutdown();
  }
}


/**
 * The GUWHITEBOARDROSBRIDGE::callback gathers various state variables and
 * dispatches the *rosPostMsg()* function on the custom queue named
 * "net.mipal.guwhiteboardrosbridge".<br />
 *
 * *sMutex* is only locked if the constructor has not finished yet.
 * This gaurantees that the callback isn't executed before all the ROS Topics
 * have been setup, which can happen if the Whiteboard is already running.
 *
 * The follows state information is gathered before dispatching:<ul>
 * <li>The Whiteboard message object itself,<\li>
 * <li>WB Type, and it's int equivalent, that initiated the callback,<\li>
 * <li>Pointer to the associated *rosCallback* object for this type,<\li>
 * <li>Pointer to the ROS publisher object for this type,<\li>
 * <li>Whiteboard event count for this message type,<\li>
 * <li>Pointers to the statistics variables<\li>
 * <li>Whether to print messages or not,<\li><\ul>
 *
 * @param[in] guWhiteboard::WBTypes t<br />
 * The message type this callback is for.
 * @param[in] gu_simple_message *msg<br />
 * Pointer to the message type object itself
 *
 */
void GUWHITEBOARDROSBRIDGE::callback(guWhiteboard::WBTypes t, gu_simple_message *msg) {

  struct wbMsgDataStruct msgData;

  // Lock Mutex so that Callback pauses for the Bridge Setup phase to complete
  // in case an instance of the Whiteboard is already running.
  // Also ensures thread safe operation
  pthread_mutex_lock(&sMutex);
  // collect state variables needed to decide what to do with this message
  msgData.printMessages = printMessages;
  msgData.msgtype = t;
  msgData.intMsgType = (int) t;
  msgData.wb_event_count = wb->event_counters[msgData.intMsgType];
  msgData.thisROScallback = rosCallbackList[msgData.intMsgType];
  msgData.thisPublisher = &pubList[msgData.intMsgType];
  msgData.echoCancelledROS = &echoCancelledROS[msgData.intMsgType];
  msgData.receivedMsgsWB = &receivedMsgsWB[msgData.intMsgType];
  msgData.wbWatcherTooSlowWB = &wbWatcherTooSlowWB[msgData.intMsgType];
  msgData.msg = msg;
  // dispatch the message to a synchronious queue for processing
  dispatch_sync_f(wrbCallbackQueue, &msgData, postMsgROS);
  pthread_mutex_unlock(&sMutex);
  ros::spinOnce(); // Give ROS a kick-along to increase responsiveness

}
