/*
 *  clfsm_wb_vector_factory.cc
 *  clfsm
 *
 *  Created by Rene Hexel on 25/03/13.
 *  Copyright (c) 2013 Rene Hexel. All rights reserved.
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
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
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
#include "FSMAsynchronousSuspensibleMachine.h"
#include "FSMachineVector.h"
#include "CLMachine.h"
#include "clfsm_wb_vector_factory.h"
#include "gugenericwhiteboardobject.h"

using namespace FSM;
using namespace guWhiteboard;
using namespace std;

CLFSMWBVectorFactory::CLFSMWBVectorFactory(Context *context, bool deleteOnDestruction): CLFSMVectorFactory(context, deleteOnDestruction), _watcher(),  _wbstatus()
{
        SUBSCRIBE(&watcher(), FSM_Control, FSM::CLFSMWBVectorFactory, FSM::CLFSMWBVectorFactory::whiteboard_fsm_control);
        SUBSCRIBE(&watcher(), FSM_Names, FSM::CLFSMWBVectorFactory, FSM::CLFSMWBVectorFactory::whiteboard_fsm_names);
}


void CLFSMWBVectorFactory::whiteboard_fsm_control(WBTypes, FSMControlStatus &controlMsg)
{
        FSMControlType command = controlMsg.command();

        switch (command)
        {
                case guWhiteboard::FSMStatus:
                        postMachineStatus();
                        break;
                // TODO
                case guWhiteboard::FSMSuspend:
                        suspendMachines(controlMsg);
                        break;
                case guWhiteboard::FSMResume:
                        resumeMachines(controlMsg);
                        break;
                case guWhiteboard::FSMRestart:
                        restartMachines(controlMsg);
                        break;
        }
}


void CLFSMWBVectorFactory::postMachineStatus()
{
        FSMControlStatus status;

        status.reset();

        int i = 0;
        for (MachineVector::const_iterator it = fsms()->machines().begin(); it != fsms()->machines().end(); it++, i++)
        {
                if (i >= int(CONTROLSTATUS_NUM_FSMS-1))
                        break;
                const SuspensibleMachine *machine = *it;
                status.set(i, machine->isSuspended());
        }
        status.set(i);                  // set the high bit to 1

        wbstatus().set(status);         // post to whiteboard
}


void CLFSMWBVectorFactory::suspendMachines(guWhiteboard::FSMControlStatus &suspendControl)
{
        FSMControlStatus status;

        status.reset();
        status.set_command(FSMControlType::FSMSuspend);

        int i = 0;
        for (MachineVector::iterator it = fsms()->machines().begin(); it != fsms()->machines().end(); it++, i++)
        {
                if (i >= int(CONTROLSTATUS_NUM_FSMS-1))
                        break;
                AsynchronousSuspensibleMachine *machine = static_cast<AsynchronousSuspensibleMachine *>(*it);
                if (suspendControl.get(i))
                {
                        machine->scheduleSuspend();
                        status.set(i);
                }
                else status.set(i, machine->isSuspended());
        }
        status.set(i);                  // set the high bit to 1

        wbstatus().set(status);         // post to whiteboard
}


void CLFSMWBVectorFactory::resumeMachines(guWhiteboard::FSMControlStatus &resumeControl)
{
        FSMControlStatus status;

        status.reset();
        status.set_command(FSMControlType::FSMSuspend);

        int i = 0;
        for (MachineVector::iterator it = fsms()->machines().begin(); it != fsms()->machines().end(); it++, i++)
        {
                if (i >= int(CONTROLSTATUS_NUM_FSMS-1))
                        break;
                AsynchronousSuspensibleMachine *machine = static_cast<AsynchronousSuspensibleMachine *>(*it);
                if (resumeControl.get(i))
                {
                        machine->scheduleResume();
                        status.clr(i);
                }
                else status.set(i, machine->isSuspended());
        }
        status.set(i);                  // set the high bit to 1

        wbstatus().set(status);         // post to whiteboard
}


void CLFSMWBVectorFactory::restartMachines(guWhiteboard::FSMControlStatus &resumeControl)
{
        FSMControlStatus status;

        status.reset();
        status.set_command(FSMControlType::FSMSuspend);

        int i = 0;
        for (MachineVector::iterator it = fsms()->machines().begin(); it != fsms()->machines().end(); it++, i++)
        {
                if (i >= int(CONTROLSTATUS_NUM_FSMS-1))
                        break;
                AsynchronousSuspensibleMachine *machine = static_cast<AsynchronousSuspensibleMachine *>(*it);
                if (resumeControl.get(i))
                {
                        machine->scheduleRestart();
                        status.clr(i);
                }
                else status.set(i, machine->isSuspended());
        }
        status.set(i);                  // set the high bit to 1

        wbstatus().set(status);         // post to whiteboard
}


void CLFSMWBVectorFactory::whiteboard_fsm_names(WBTypes, FSMNames &namesReq)
{
        postMachineNamesFromIndex(namesReq);
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"

void CLFSMWBVectorFactory::postMachineNames()
{
        int n = int(fsms()->machines().size());
        int postCount = 0;
        FSMNames name_info;
        name_info.set_startoffs(0);
        while ( name_info.startoffs() < n)
        {
                postMachineNamesFromIndex(name_info);
                *name_info.names()='\0';
                if (postCount) protected_msleep(20);
                if ((++postCount % GU_SIMPLE_WHITEBOARD_GENERATIONS) == 0)
                        protected_msleep(80);
        }
}


FSMNames* CLFSMWBVectorFactory::postMachineNamesFromIndex(FSMNames &namesReq)
{
        char *currentName = namesReq.names();
        if (*currentName == 0) {

                uint16_t index = namesReq.startoffs();

                int n = int(_clmachines.size());
                if (index >= n) {
                        namesReq.set_startoffs(static_cast<uint16_t> (n-1));
                        index = namesReq.startoffs();
                }
                while (index < n)
                {
                        CLMachine *machine = _clmachines[index];
                        const char *machine_name = machine->machineName();
                        int len = int(strlen(machine_name));
                        if (!machine_name || len >= namesReq.available_space(currentName))
                                break;
                        strcpy(currentName, machine_name);
                        currentName += len;
                        *currentName++ = '\0';
                        index++;
                }
                if (namesReq.available_space(currentName)) *currentName = '\0';

                wbfsmnames().set(namesReq);

                namesReq.set_startoffs(index);
        }

        return &namesReq;
}


bool CLFSMWBVectorFactory::executeOnce(visitor_f should_execute_machine, void *context = NULL)
{
        bool needToSend = false;
        uint8_t machineID = 0;
        for (MachineVector::iterator it = fsms()->machines().begin(); it != fsms()->machines().end(); it++) {
                SuspensibleMachine *m = *it;
                uint8_t stateIndex = static_cast<uint8_t>(m->indexOfState());
                uint8_t prevState = fsmCurrStates.getStateForMachineID(machineID);
                if (stateIndex != prevState)
                {
                        fsmCurrStates.setStateForMachineID(machineID, stateIndex);
                        needToSend = true;
                }
                machineID++;
        }
        if (needToSend)
        {
                wbfsmstates().set(fsmCurrStates);
        }
        return fsms()->executeOnce(should_execute_machine, context);
}
