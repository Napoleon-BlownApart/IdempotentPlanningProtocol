/*
 *  clfsm_visitorsupport.cc
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
#include <numeric>      // Accumlate
#include <algorithm>    // std::sort
#include <string>       // std::to_string

#include "clfsm_visitorsupport.h"

using namespace FSM;

/* Constructor */
CLFSMStateExecutionTimeContainer::CLFSMStateExecutionTimeContainer(std::string stateName) {
    _sorted = false;
    _stateName = stateName;
}

/* Returns a string in the following format:
 * StateName BestTime WorstTime AverageTime Iterations
 * Values are white-space seperated.
 */
std::string CLFSMStateExecutionTimeContainer::getResults()
{
    // C++ really needs a string.format. This is just stupid!
    return this->getStateName() + " " + std::to_string(this->getBestTime())
        + " " + std::to_string(this->getWorstTime()) + " "
        + std::to_string(this->getAverageTime()) + " "
        + std::to_string(this->_executionTimes.size());
}

/* Query executionTimes for Best Execution Time */
double CLFSMStateExecutionTimeContainer::getBestTime() {
    if (!this->_sorted) {
        sortExecutionTimes();
    }

    return this->_executionTimes.front();
}

/* Query executionTimes for Worst Execution Time */
double CLFSMStateExecutionTimeContainer::getWorstTime() {
    if (!this->_sorted) {
        sortExecutionTimes();
    }
    
    return this->_executionTimes.back();
}

/* Average out Execution Times */
double CLFSMStateExecutionTimeContainer::getAverageTime() {
    return std::accumulate(this->_executionTimes.begin(),
                           this->_executionTimes.end(), 0.0)
                            / static_cast<double>(this->_executionTimes.size());
}

/* Insert execution time into Collection */
void CLFSMStateExecutionTimeContainer::insertExecutionTime(double time) {
    // Debug
    // std::cerr << this->getStateName() << ": " << time << std::endl;
    
    this->_executionTimes.push_back(time);
    this->_sorted = false;
    
//    fprintf(stderr, "State: %s Addr: %p Size:%lu\n", this->getStateName().c_str(), this, this->_executionTimes.size());
    
}

/* Sort internal execution time vector. Sets sorted flag. */
void CLFSMStateExecutionTimeContainer::sortExecutionTimes() {
    
    // Use the standard sort comparer.
    // Can repalce with faster sorting alg, at a later date (if needed).
    std::sort(this->_executionTimes.begin(), this->_executionTimes.end());
    this->_sorted = true;
}

