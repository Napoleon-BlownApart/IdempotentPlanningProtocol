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

#ifndef __gufsm__clfsm_visitorsupport__
#define __gufsm__clfsm_visitorsupport__

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"

#include <iostream>
#include <chrono>
#include <vector>

namespace FSM
{
    /* Container class for Execution Time Vector and State Information.
     * Used as part of ClFSMExecutionVisitor funcationality. 
     */
    class CLFSMStateExecutionTimeContainer
    {
        std::vector<double> _executionTimes;
        std::string _stateName;
        bool _sorted;
    public:
        /* Constructor */
        CLFSMStateExecutionTimeContainer(std::string stateName);
        
        /* Getter for stateName */
        std::string getStateName() const { return _stateName; }
        
        /* Returns a string in the following format:
         * StateName BestTime WorstTime AverageTime Iterations
         * Values are white-space seperated.
         */
        std::string getResults();
        
        /* Best Execution Time */
        double getBestTime();
        
        /* Worst Execution Time */
        double getWorstTime();
        
        /* Average out Execution Times */
        double getAverageTime();
        
        /* Insert execution time into Execution Times */
        void insertExecutionTime(double time);
        
        /* Relational operators for Execution Time Object */
        bool operator==(const CLFSMStateExecutionTimeContainer &rhs) const
        {
            return this->getStateName() == rhs.getStateName();
        }
        
        bool operator<(const CLFSMStateExecutionTimeContainer &rhs) const
        {
            return this->getStateName() < rhs.getStateName();
        }
        
        bool operator>(const CLFSMStateExecutionTimeContainer &rhs) const
        {
            return this->getStateName() > rhs.getStateName();
        }
        
    private:
        /* Sort _executionTimes */
        void sortExecutionTimes();
    };
    
    
    /* CLFSMTimer is a simple high-resolution timing class. 
     * For original implementation see reference:
     * @ref https://gist.github.com/gongzhitaao/7062087#file-timer-c-11-cpp
     */
    class CLFSMTimer
    {
    public:
        CLFSMTimer() : _beg(clock_::now()) {}
        void reset() { _beg = clock_::now(); }
        double elapsed() const
        {
            return std::chrono::duration_cast<_second>
            (clock_::now() - _beg).count();
        }
        
    private:
        typedef std::chrono::high_resolution_clock clock_;
        typedef std::chrono::duration<double, std::ratio<1> > _second;
        std::chrono::time_point<clock_> _beg;
    };
}

#pragma clang diagnostic pop

#endif /* defined(__gufsm__clfsm_visitorsupport__) */
