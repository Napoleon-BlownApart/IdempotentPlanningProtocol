/*
 *  clfsm_visitors.cc
 *  clfsm
 *
 *  Created by Jeremy Cade on 10/09/2014.
 *  Copyright (c) 2014 Jeremy Cade. All rights reserved.
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
#include <algorithm>    // std::find_if

#include "clfsm_visitors.h"
#include "clfsm_visitorsupport.h"

#include "gu_util.h"
#include "FSMState.h"
#include "FSMSuspensibleMachine.h"
#include "FSMachineVector.h"
#include "CLMachine.h"
#include "clfsm_machine.h"
#include "clfsm_wb_vector_factory.h"
#include "gugenericwhiteboardobject.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wexit-time-destructors"

using namespace FSM;

/* Execution Time Visitor */
bool CLFSMVisitorsExecution::time_state_execution(void *ctx,
                                                  SuspensibleMachine *machine,
                                                  int machine_number)
{
    std::string stateName = machine->currentState()->name();
    
    if (machine->previousState() != machine->currentState())
    {
        CLFSMTimer timer;
        machine->executeOnce();
        double t = timer.elapsed();
        insertTime(stateName, t);
    }

    return true;
}

/* Writes results to standard err */
void CLFSMVisitorsExecution::print_results_stderr()
{
    std::cerr << "#####   START EXECUTION RESULTS   ##### " << std::endl;
    std::cerr << "StateName BestCase WorstCase AverageCase Iterations"
        << std::endl;
    for (std::vector<CLFSMStateExecutionTimeContainer>::const_iterator it =
            execution_results.begin(); it != execution_results.end(); it++)
    {
        CLFSMStateExecutionTimeContainer t = *it;
        std::cerr << t.getResults() << std::endl;
    }
    std::cerr << "#####   END EXECUTION RESULTS     ##### " << std::endl;
}

/* Insert State Execution Time
 * If the the state is already in the set, it adds an additional timing.
 * Otherwise it adds a new CLFSMStateExecutionTime object into the set, 
 * along with an initial timing. 
 * @param name of the State for which a execution time is recorded.
 * @param execution time in seconds. 
 */
void CLFSMVisitorsExecution::insertTime(std::string stateName, double time)
{
    // find_if lambda YAY!
    std::vector<CLFSMStateExecutionTimeContainer>::iterator it =
        find_if(execution_results.begin(), execution_results.end(),
                [&stateName](const CLFSMStateExecutionTimeContainer &t)
    {
        return t.getStateName() == stateName;
    });
    
    if (it != execution_results.end())
    {
        it->insertExecutionTime(time);
    }
    else
    {
        CLFSMStateExecutionTimeContainer t = CLFSMStateExecutionTimeContainer(stateName);
        t.insertExecutionTime(time);
        execution_results.push_back(t);
    }
}

/* Init Static Collection */
std::vector<CLFSMStateExecutionTimeContainer> CLFSMVisitorsExecution::execution_results;

#pragma clang diagnostic pop
