/**
 *  @file gwrbClass.h
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
 * 1.0.0 | 06/05/2014 | The guWhiteboardROSbridge's interfacing to the
 * Whiteboard is based on the guWhiteboardMonitor<br />
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
 * *whiteboard_watcher* object issues a callback to
 * *GUWHITEBOARDROSBRIDGE::callback*.  The callback prepares the necessary
 * information and uses a custom queue named "net.mipal.guwhiteboardrosbridge"
 * to synchroniously dispatch the *rosPostMsg()* function.
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
#ifndef GWRBCLASS_H
#define GWRBCLASS_H

#define _FROM_WHITEBOARD_CC_    // shut up the whiteboard warning, I know what I'm doing

#include <ros/ros.h>
#include "std_msgs/String.h"

#include "gu_util.h"
#include "guwhiteboardwatcher.h"
#include "guwhiteboardgetter.h"
#include "guwhiteboardposter.h"
#include "rosCallback.h"

class GUWHITEBOARDROSBRIDGE
{

	// Data structure passed to dispatch_sync_f on receipt of WB callback
        /**
        * Data structure used to communicate state information to the method which
        * actually processes the incoming Whiteboard message.
        *
        * The *postMsgROS()* method is executed on the
        * "net.mipal.guwhiteboardrosbridge" dispatch queue.
        *
        */
	struct wbMsgDataStruct {
	  rosCallback* thisROScallback;
	  ros::Publisher* thisPublisher;
	  int* echoCancelledROS;   // reports number of echos cancelled whose origin were in ROS
	  int* receivedMsgsWB; 	   // reports number of messages received from WB publishers
	  int* wbWatcherTooSlowWB; // reports number of messages not forwarded because the
                             // Whiteboard event counter has advanced before this
                             // callback was received.
	  guWhiteboard::WBTypes msgtype;
	  int intMsgType;
	  uint16_t wb_event_count; // when the callback was received
    bool printMessages;
	  gu_simple_message* msg;
	};


public:

	// Constructor
	GUWHITEBOARDROSBRIDGE(char **subscription_list, int subListSize, bool verboseMode);

	// Destructor
	virtual ~GUWHITEBOARDROSBRIDGE();

	// reports whether the guWhiteboardROSbridge is running or not
	bool isROSRunning();

	// reports the number times WB counter has advanced before message was processed
	int getWB_WatcherTooSlowWB(int msgType);
        // reports the number times that the next ROS callback is called before the WB has finished processing the present one.
	int getWB_WatcherTooSlowROS(int msgType);

	// reports number of messages received from WB publishers
	int getReceivedMessagesWB(int msgType);
	// reports number of echos cancelled whose origin were in WB
	int getEchoCancelledWB(int msgType);

	// reports number of messages received from ROS publishers
	int getReceivedMessagesROS(int msgType);
	// reports number of echos cancelled whose origin were in ROS
	int getEchoCancelledROS(int msgType);

private:

	// Callback the whiteboard_watcher uses for subscribed messages
	void callback(guWhiteboard::WBTypes t, gu_simple_message *msg);

        /**
         * Processes the current message on the Whiteboard side.<br />
         * If it is a new Whiteboard message, forward it to ROS, otherwise its either
         * an Echo or **could be** an Echo because the counter has advanced and should
         * not be forwarded back to ROS.
         *
         * If 'printMessages = true' then print the corresponding message data.
         * Note that all messages are printed here.  The ROS callback does not print
         * message data.
         *
         * @param[in] struct wbMsgDataStruct *<br />
         * Structure that contains all the information required to decide what to do
         * with the current message.
         *
         */
	static void postMsgROS (void *param) {

		std_msgs::String rosMsg;
		struct wbMsgDataStruct* msgData;

//		std::cerr << "^+" << pthread_self() << std::endl;
		msgData = (wbMsgDataStruct*) param;
		if (msgData->intMsgType >= 0 && msgData->intMsgType < GSW_NUM_TYPES_DEFINED) {
			int frwdFlag = 0; // Assume message came from ROS
			uint16_t rosEvents = 1 + msgData->thisROScallback->getROSeventNo(); // Make a local copy of the WB event counter
			// Extract the message string from the Whiteboard object
			rosMsg.data = getmsg(msgData->msgtype, msgData->msg); //guwhiteboardgetter.cpp
			// If its a Whiteboard Echo ignore it, otherwise forward it to ROS.
			// Then clear the Whiteboard Echo Cancellation Variables from the
			// last message in the rosCallback object.
			if (msgData->thisROScallback->getrosMsgFlag()) {
			        // ROS callback indicates this is a ROS message
				msgData->thisROScallback->clearROSMessage(); // clear ROS Echo Cancellation variables
				if(rosEvents == msgData->wb_event_count) { // Check the WB event counter against the message
				        // Whiteboard event counter indicates this is an echo
					(*msgData->echoCancelledROS)++;
					frwdFlag = 0; // Set the forward flag to indicate ROS Echo
				} else {
				        // Whiteboard event counter has advanced since the ROS callback posted to the WB
				        // therefore it can't be determined if this message is an echo or not.
					(*msgData->wbWatcherTooSlowWB)++;
					frwdFlag = 2; // Set the forward flag to indicate WB callback took too long
//					std::cerr << "^" << std::endl;
				}
			} else {
			        // This is a new Whiteboard message
				(*msgData->receivedMsgsWB)++;
				frwdFlag = 1; // Set the forward flag to indicate a new WB callback
				// Publish a Whiteboard message to ROS according to the WB message type 't'
				msgData->thisPublisher->publish(rosMsg); // So send it to ROS
			}
			if (msgData->printMessages) {
                                // print the message
				printf("Type:%d   \t%d\t\tValue:\t%s\t%d:%d\n", frwdFlag, msgData->intMsgType, rosMsg.data.c_str(), msgData->wb_event_count,rosEvents);
			}
//			std::cerr << "^-" << pthread_self() << std::endl;
		}
	}


	whiteboard_watcher *watcher;    /** new whiteboard object */
//#ifdef USE_OLD_WHITEBOARD
//        guWhiteboard::Whiteboard *wb;	/**< Whiteboard object. */
//        guWhiteboard::Whiteboard::WBResult r; /**< Return message from wb methods. */
//
//#endif
	/**
	 * Keep things thread safe, don't want two callbacks running at the same time.
	 */
	pthread_mutex_t  sMutex;

        /**
         * Determines if message are printed or not.
         *
         * True = print messages
         * False = silent mode (default)
         */
	bool printMessages = false;	// By default, operate in silent mode.

        /**
         * Pointer Array to rosCallback objects
         */
	rosCallback *rosCallbackList[GSW_NUM_TYPES_DEFINED]; // Array for ROS Callback objects

        /**
         * Array for publishing NodeHandles
         */
	ros::NodeHandle *pNodeHandles[GSW_NUM_TYPES_DEFINED]; // Array for publishing NodeHandles

        /**
         * Array for Subscribing NodeHandless
         */
	ros::NodeHandle *sNodeHandles[GSW_NUM_TYPES_DEFINED]; // Array for Subscribing NodeHandles

        /**
         * Array for ROS Publisher objects
         */
	ros::Publisher  pubList[GSW_NUM_TYPES_DEFINED]; // Array for publishers

        /**
         * Array for ROS Subscriber objects
         */
	ros::Subscriber subList[GSW_NUM_TYPES_DEFINED]; // Array for subscribers

};

#endif // GWRBCLASS_H
