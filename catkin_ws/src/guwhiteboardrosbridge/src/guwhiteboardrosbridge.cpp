/**
 *  @file guwhiteboardrosbridge.cpp
 *
 *  ./GUNao/posix/guWhiteboardROSbridge/
 *
 *  Created by
 *  @author   Dimitri Joukoff
 *
 *  @version  1.0.0
 *  @date     2014/06/05
 *
 *  Version History<br />
 *  1.0.0 | 06/05/2014 | Wrapper for the guWhiteboardROSbridge allowing it to
 *                       be run as a separate process<br />
 *
 *
 * ============================================================================
 *
 * The purpose of the guWhiteboardROSbridge ("Bridge") is to enable full-duplex
 * exchange of Whiteboard Class messages between the GU Whiteboard and ROS.<br />
 *
 * This wrapper allow the **Bridge** to be run standalone, similar to how the
 * guWhiteboardMonitor is used.<br />
 *
 * Usage:
 * rosrun guwhiteboardrosbridge guwhiteboardrosbridge_node <-v>
 * -v switch turns on Verbose mode which prints incoming messages.
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
#include <unistd.h>

#include "gwrbClass.h"



using namespace std;
//using namespace guWhiteboard;
//using namespace ros;

int main(int argc, char **argv)
{
	//Get passed in values
	//-----------------------------------
	int op;
	bool verboseMode = false; // By default, run the bridge silently

	while((op = getopt(argc, argv, "hv")) != -1)
	{
		switch(op)
		{
			case 'v':
				verboseMode = true; // we want messages printed
				break;
			case '?':
			case 'h':
				fprintf(stderr, "\n\nUsage: rosrun guwhiteboardrosbridge guwhiteboardrosbridge_node [OPTIONS] <subscriptions>\n");
				fprintf(stderr, "-h, View this help information.\n");
				fprintf(stderr, "-v, Verbose Mode (Messages printed to StdOut).\n");
				fprintf(stderr, "(ensure ROSCORE is running and accessible)\n");
				return EXIT_FAILURE;
			default:
				break;
		}
	}
	//-----------------------------------

	argv += optind;
	argc -= optind;

	char **subs = NULL;
	if (argc) subs = argv;
	fprintf(stderr, "\n**** GU WHITEBOARD<=>ROS BRIDGE MODULE ****\n         Dimitri Joukoff (c) 2014\n\n");
	GUWHITEBOARDROSBRIDGE* bridge = new GUWHITEBOARDROSBRIDGE(subs, argc, verboseMode); // hello
	while (bridge && bridge->isROSRunning() ) {
		sleep(1);
	}

// ONLY USED DURING DEVELOPMENT
//	if (bridge->getWBMissedMessages(37) !=0) {
//		cerr << "Whiteboard Missed " << bridge->getWBMissedMessages(37) << " Messages (37)" << endl;
//	} else {
//		cerr << "Whiteboard DID NOT Miss any messages (37)" << endl;
//	}

	// Print traffic statistics
	for (int i=1; i<GSW_NUM_TYPES_DEFINED; i++) {
		if (bridge->getReceivedMessagesROS(i)>0) {
			cerr << "TOPIC[" << i << "] WRB received " << bridge->getReceivedMessagesROS(i) << " message(s) from ROS Publishers (Blue 2b)" << endl;
		}
		if (bridge->getEchoCancelledROS(i)>0) {
			cerr << "TOPIC[" << i << "] WRB cancelled " << bridge->getEchoCancelledROS(i) << " ROS Echo(es) (Blue 4b)" << endl;
		}
		if (bridge->getReceivedMessagesWB(i)>0) {
			cerr << "TOPIC[" << i << "] WRB received " << bridge->getReceivedMessagesWB(i) << " message(s) from WB Publishers (Red 2b)" << endl;
		}
		if (bridge->getEchoCancelledWB(i)>0) {
			cerr << "TOPIC[" << i << "] cancelled " << bridge->getEchoCancelledWB(i) << " WB Echo(es) (Red 4b)" << endl;
		}

		if (bridge->getWB_WatcherTooSlowWB(i)>0) {
			cerr << "TOPIC[" << i << "] missed " << bridge->getWB_WatcherTooSlowWB(i) << " message(s) from ROS due to event counter (Blue)" << endl;
		}
		if (bridge->getWB_WatcherTooSlowROS(i)>0) {
			cerr << "TOPIC[" << i << "] missed " << bridge->getWB_WatcherTooSlowROS(i) << " message(s) from ROS due to record not reset (Blue)" << endl;
		}
	}


	delete bridge;
	cerr << "Shutting Down guWhiteboardROSbridge" << endl;
	return EXIT_FAILURE;
}
