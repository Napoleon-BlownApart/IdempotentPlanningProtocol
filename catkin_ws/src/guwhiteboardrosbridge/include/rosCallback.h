/**
 *  @file rosCallback.h
 *
 *  ./GUNao/posix/guWhiteboardROSbridge
 *
 *  Created by
 *  @author   Dimitri Joukoff
 *
 *  @version  1.0.0
 *  @date     2014/06/05
 *
 * Version History<br />
 * 1.0.0 | 06/05/2014 | The ROS Callback class handles ROS callbacks including
 * Echo Cancellation and statistics<br />
 *
 *
 * ============================================================================
 *
 * The purpose of the rosCallback class is to provide a generic means of
 * handling everything required to handle ROS callbacks for Whiteboard message
 * types, including Echo Cancellation.
 *
 * The callback prepares the necessary information and uses a custom queue named
 * "net.mipal.guwhiteboardrosbridge" to synchroniously dispatch the
 * *postMsgWB()* function.
 *
 *=============================================================================
 */

/*
 *  Copyright 2014 Dimitri Joukoff, Griffith University
 *	All rights reserved.
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
#ifndef ROSCALLBACK_H
#define ROSCALLBACK_H

#include <iostream>
#include <cstdlib>
#include <ros/ros.h>
#include "std_msgs/String.h"

#include <pthread.h>
#include <dispatch/dispatch.h>
#include "guwhiteboardposter.h"

#define handle_error_en(en, msg) \
        do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)
#define handle_error(msg) \
        do { perror(msg); exit(EXIT_FAILURE); } while (0)

/**
 * <strong>CLASS rosCallback</strong>
 * The primary purpose of the rosCallback class is to provide a factory for
 * creating the callback function required by each ROS Topic to which the
 * guWhiteboardROSbridge subscribes.
 * <em>(For further information about the workings of the guWhiteboardROSbridge,
 * please refer to the explanation in gwrbclass.h.)</em><br />
 *
 * Due to the design of the Whiteboard, a secondary, but equally important,
 * purpose of the rosCallback class is to provide the necessary Whiteboard
 * state information to the GUWHITEBOARDROSBRIDGE::callback function in order
 * to cancel Whiteboard Echos.
 *
 * <strong>guWhiteboardROSbridge Echo Cancellation</strong>
 *
 * Echo cancellation is required on both sides of the bridge (Whiteboard and
 * ROS):
 * <strong>ROS Echos</strong><br />
 * <em>(Occurs when Whiteboard Publishers post messages)</em>
 * The guWhiteboardROSbridge publishes messages received from the Whiteboard
 * to the ROS Topic that corresponds to the Whiteboard message type.
 * Since the guWhiteboardROSbridge also subscribes to these same topics, an
 * echo of the afore mentioned message is always received.
 * To eliminate this echo, the publisher's name of each received message is
 * checked.
 * If the publisher's name is "/guWhiteboardROSbridge" (the
 * guWhiteboardROSbridge's ROS node name) the message is NOT forwarded BACK
 * into the Whiteboard because the message originated there.
 *
 * Otherwise, the message is forwarded to the Whiteboard.
 *
 * <strong>Whiteboard Echos</strong></br />
 * <em>(Occurs when ROS Publishers post messages)</em>
 * The guWhiteboardROSbridge subscribes to ROS Topics that correspond to the
 * Whiteboard message types and forwards messages received to the appropriate
 * Whiteboard message store.
 * Since the guWhiteboardROSbridge also subscribes to Whiteboard messages,
 * an echo of the afore mentioned message is always received.
 * Elimination of the Whiteboard Echo is a little more complicated than ROS
 * Echos because Whiteboard messages do not provide any information about
 * their source.  Therefore it is not possible to employ the same method used
 * to cancel ROS echos.  Coordination between the ROS and Whiteboard
 * subscriber callback functions is required to cancel the Whiteboard Echo.
 *
 * Just before the guWhiteboardROSbridge posts a message to the Whiteboard,
 * the rosCallback[message type] instance method generic_ros_callback()
 * records:
 * * The message content and
 * * The whiteboard event counter for that message type.
 * And sets the rosMsg flag TRUE to indicate a ROS message being forwarded.
 *
 * The message is then posted.
 *
 * When the Whiteboard raises the GUWHITEBOARDROSMONITOR::callback to process
 * the received message, the callback checks these state variables to
 * determine if the message originated from ROS, in which case the message is
 * not forwarded.
 *
 * These state variables are immediately reset after the
 * GUWHITEBOARDROSMONITOR::callback has checked them.
 *
 *
 * These state variables are also reset if a forwarding error has occured due
 * to a missed message.
 *
 */

  // pointer to the Whiteboard shared memory. (gusimplewhiteobard.h)
  extern gu_simple_whiteboard* wb;
  // the dispatch queue used to sequence callback processing of messages received both in the Whiteboard and ROS
  extern dispatch_queue_t* wrbCallbackQueue_ptr;


class rosCallback {


  // Data structure passed to dispatch_sync_f on receipt of WB callback
  /**
   * Data structure used to communicate state information to the method which
   * actually processes the incoming ROS message.
   *
   * The *postMsgWB()* method is executed on the
   * "net.mipal.guwhiteboardrosbridge" dispatch queue.
   *
   */
  struct rosMsgDataStruct {
        guWhiteboard::WBTypes msgtype;
        int intMsgType;
        bool* rosMsg;
        uint16_t* wb_event_count;
        int* receivedMsgsROS;
        int* echosCancelledWB;
        int* wbWatcherTooSlowROS;
        const ros::MessageEvent<std_msgs::String const>* event;
  };

  // INSTANCE VARIABLES (Static during the objects life)
  /**
   * Whiteboard message type being serviced by this instance.
   *
   * This does not change over the life of the object.
   *
   */
  guWhiteboard::WBTypes msgtype; // WB message type of this object

  /**
   * Whiteboard (INT) message type being serviced by this instance.
   *
   * This does not change over the life of the object.
   *
   */
  int intMsgType; // WB message type of this object


  // INSTANCE VARIABLES (Dynamic)
  /**
   * Whiteboard Echo Cancellation Variable
   *
   * Each time a message is received from a ROS Topic, this is a record of the
   * Whiteboard event counter just before posting.
   *
   */
  uint16_t wb_event_count = 0;  // snapshot of wb event counter for this message type.

  /**
   * Whiteboard Echo Cancellation Variable
   *
   * Each time a message is received from a ROS Topic, this is set TRUE to
   * indicate the need for GUWHITEBOARDROSMONITOR::callback to check before
   * forwarding to ROS.
   *
   */
  bool rosMsg = false;

  // Statistics
  /**
   * Counter Array that tracks the number of times the ROS Callback is
   * received per message type with the Echo Cancellation Variables indicating
   * that the Whiteboard callback didn't process the previous message
   *
   */
  int wbWatcherTooSlowROS = 0;

  /**
   * Counter Array that tracks the number of messages forwarded to ROS from the
   * Whiteboard by Message Type.
   *
   * Echos are not included in this count.
   *
   */
  int receivedMsgsROS = 0;

  /**
   * Counter Array that tracks the number of ROS Echos of Whiteboard messages
   * that are cancelled on the ROS side of the **Bridge**.
   *
   */
  int echosCancelledWB = 0;


  // PRIVATE CLASS MEMBERS
  /**
   * Processes the current message on the ROS side.<br />
   * If it is a new ROS message, forward it to the Whiteboard, otherwise its
   * an Echo and should not be forwarded back into the Whiteboard.
   *
   * @param[in] struct rosMsgDataStruct *<br />
   * Structure that contains all the information required to decide what to do
   * with the current message.
   *
   */
  static void postMsgWB (void *param) {

        struct rosMsgDataStruct* msgData = (rosMsgDataStruct*) param;

//	    std::cerr << "#+" << /*getpid() << "|" << */pthread_self() << std::endl;

        // Check if I was the publisher of the message that generated the callback
        if (msgData->event->getPublisherName().compare("/guWhiteboardROSbridge") != 0 ) {
            // No, this is a new message from a ROS Publisher
            if ((*msgData->rosMsg)) {
              // rosMsg is still true, therefore the WB Callback took too long.
              // This occurres when the BRIDGE is running faster than it's designed to
              std::cerr << "WARNING:: WB Watcher Callback took too long" <<std::endl;
              (*msgData->wbWatcherTooSlowROS)++;
            }
            (*msgData->rosMsg) = true;
//            (*msgData->wb_event_count) = rosCallback::wb->event_counters[msgData->intMsgType];
            (*msgData->wb_event_count) = wb->event_counters[msgData->intMsgType];
           guWhiteboard::postmsg(msgData->msgtype, msgData->event->getMessage()->data.c_str());
            (*msgData->receivedMsgsROS)++;
        } else {
          // The message was an Echo
          (*msgData->echosCancelledWB)++;
        }
//	    std::cerr << "#-" << pthread_self() << std::endl;
  }


public:

  // PUBLIC CLASS VARIABLES
  static dispatch_queue_t wrbCallbackQueue;

  // PUBLIC CLASS MEMBERS
  /**
   * rosCallback - constructor.
   * Creates an instance of the rosCallback class that will service a
   * particular Whiteboard message type.
   *
   * @param[in] guWhiteboard::WBTypes msgType
   * Defines the Whiteboard message type to be serviced by this instance.
   *
   */
  rosCallback(guWhiteboard::WBTypes msgType) : msgtype(msgType), intMsgType ((int) msgType)  {}

  // Class Destructor
  ~rosCallback() {}


  //INSTANCE MEMBERS
  /**
   * generic_ros_callback
   *
   * This is the callback that takes a serialised Whiteboard object received
   * from a ROS Topic and posts it to the Whiteboard.  It also prepares the
   * Whiteboard Echo Cancellation Variables needed by the
   * GUWHITEBOARDROSMONITOR::callback.
   *
   * @param const ros::MessageEvent<std_msgs::String const>& event
   * This is a ROS object which provides message information in addition to the
   * message content.
   *
   * ROS is thread safe, so no need for mutex here.
   */
  void generic_ros_callback(const ros::MessageEvent<std_msgs::String const>& event) {
		struct rosMsgDataStruct msgData;
                // collect state variables needed to decide what to do with this message
		msgData.msgtype = msgtype;
		msgData.intMsgType = intMsgType;
		msgData.rosMsg = &rosMsg;
		msgData.wb_event_count = &wb_event_count;
		msgData.receivedMsgsROS = &receivedMsgsROS;
		msgData.wbWatcherTooSlowROS = &wbWatcherTooSlowROS;
		msgData.echosCancelledWB = &echosCancelledWB;
		msgData.event = &event;
		// dispatch the message to a synchronious queue for processing
		dispatch_sync_f((*wrbCallbackQueue_ptr), &msgData, postMsgWB);
		ros::spinOnce(); // Give ROS a kick-along to increase responsiveness
  }

  /**
   * Returns the rosMsg flag status.
   * rosMsg is only true when the current message being processed originated
   * from a ROS Publisher and is reset to false when the Whiteboard has
   * processed the callback.
   *
   * @return true if this message type was posted to the Whiteboard by the
   * guWhiteboardROSbridge.<br />
   * Set false by the Whiteboard Callback.
   *
   */
  bool getrosMsgFlag() {
    return rosMsg;	// return TRUE if this message came from the bridge
  }

  /**
   * Returns what the Whiteboard message type event counter state was before
   * the guWhiteboardROSbridge posted the last message.
   *
   * @return uint16_t<br />Whiteboard Event Counter state for the message type
   * being serviced by this rosCallback instance
   *
   */
  uint16_t getROSeventNo() {
    return wb_event_count;
  }


  /**
   * Used to resets the Echo Cancellation state variables once the current
   * message has been processed by the GUWHITEBOARDROSMONITOR::callback.
   *
   * Also used to reset the state variables when a forwarding warning has
   * occurred.
   *
   */
  void clearROSMessage() {
    rosMsg = false;
    wb_event_count = 0;
  }

  /**
   * Returns the number of times the callback was called before the Whiteboard
   * had finished processing the previous callback.
   *
   * @return int
   *
   */
  int getwbWatcherTooSlowROS() {
    return wbWatcherTooSlowROS;
  }

  /**
   * Returns the number of messages received by <strong>this</strong> instance.
   * (ie this message type).
   *
   * Does not include Echoes.
   *
   * @return int corresponding to the number of messages received.
   *
   */
  int getReceivedMsgsROS() {
    return receivedMsgsROS;
  }

  /**
   * Returns the number of Echos Cancelled by <strong>this</strong> instance.
   * (ie this message type).
   *
   * @return int corresponding to the number of Echoes Cancelled
   *
   */
  int getEchosCancelledWB() {
    return echosCancelledWB;
  }

};
#endif // ROSCALLBACK_H
