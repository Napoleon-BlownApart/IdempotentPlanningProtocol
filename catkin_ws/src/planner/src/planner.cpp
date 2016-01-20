/**
 *  file: planner.cpp
 *
 *  Planning module for the Idempotent Planning Protocol Demonstration
 *  Interfaces with the Subsumption Architecture ensemble; epuck...ByGSM.machine
 *
 *  Created by Dimitri Joukoff on 17/7/2015.
 *  Copyright (c) 2015 Dimitri Joukoff. All rights reserved.
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
 *        This product includes software developed by Dimitri Joukoff.
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



#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "planner.h"

//using	aptk::STRIPS_Problem;
//using	aptk::agnostic::Fwd_Search_Problem;

/** Enumeration that facilitates a switch statement based on strings
  *
  * To add further Planning Engines, be sure to increase the number
  * of entries here to accomodate the number of engines you intend to
  * use.
  *
  * Set to TEN different engines at this stage.
  */
enum EngineIndex {
  eNotDefined,
  eP1,
  eP2,
  eP3,
  eP4,
  eP5,
  eP6,
  eP7,
  eP8,
  eP9,
  eP10
};

/** Map to associate the Planning Engine string names with their enum values */
static std::map<std::string, EngineIndex> mapEngineIndex;


/** Initialise mapEngineIndex with Planning Engine names we recognise.
  * Note:   This is case sensative, and upper case has been used.
  *         In order to make this case insensitive, a comparator needs
  *         to be implemented.
  *
  */
void initialise_mapEngineIndex() {
  mapEngineIndex["BFS_HMAX"] = eP1;
  mapEngineIndex["BRFS"] = eP2;
  mapEngineIndex["DAS"] = eP3;
}

uint16_t getEventCounterForMessageType(guWhiteboard::WBTypes thisMsg) {
  gu_simple_whiteboard_descriptor* wbd = get_local_singleton_whiteboard();
  return wbd->wb->event_counters[thisMsg];
}

PlNode* new_PlNode(Connective c) {

  PlNode *result = ( PlNode * ) calloc( 1, sizeof( PlNode ) );
  CHECK_PTR(result);

  result->connective = c;
  result->atom = NULL;

  result->comp = COMP_NONE;
  result->neft = NET_NONE;
  result->lh = NULL;
  result->rh = NULL;

  result->sons = NULL;
  result->next = NULL;

  return result;

}

char *new_Token( char* identifier )

{

  char *tok = ( char * ) calloc( strlen(identifier), sizeof( char ) );
  CHECK_PTR(tok);

  return identifier;

}

TokenList *new_TokenList( void )

{

  TokenList *result = ( TokenList * ) calloc( 1, sizeof( TokenList ) );
  CHECK_PTR(result);

  result->item = NULL;
  result->next = NULL;

  return result;

}


int FF_alter_problem() {


	if (gorig_initial_facts) {                     /* Action* */
    if (obstacleList.size() != 0) {
      uint32_t numObstacles = obstacleList.size();
      for (uint32_t i=0; i< numObstacles; i++ ) {

        guWhiteboard::Plan_Obstacle thisObstacle = obstacleList[i];
        PlNode* newFact = new_PlNode(ATOM);
        TokenList*data1 = new_TokenList();
        TokenList*data2 = new_TokenList();
        TokenList*data3 = new_TokenList();

        data1->item = new_Token("BLOCKED");
        data1->next = data2;
        std::string strTokenA;
        {
          std::ostringstream ss;
          ss << "X";
          ss << static_cast<int>(thisObstacle.intersectionA().x());
          ss << static_cast<int>(thisObstacle.intersectionA().y());
          printf("Token1A is %s\n", ss.str().c_str());
          strTokenA = ss.str();
        }
        char * writableA = new char[strTokenA.size() + 1];
        std::copy(strTokenA.begin(), strTokenA.end(), writableA);
        writableA[strTokenA.size()] = '\0';
        printf("Token1B is %s\n", writableA);
        data2->item = new_Token(writableA);
        data2->next = data3;
        std::string strTokenB;
        {
          std::ostringstream ss;
          ss << "X";
          ss << static_cast<int>(thisObstacle.intersectionB().x());
          ss << static_cast<int>(thisObstacle.intersectionB().y());
          printf("Token2A is %s\n", ss.str().c_str());
          strTokenB = ss.str();
        }
        char * writableB = new char[strTokenB.size() + 1];
        std::copy(strTokenB.begin(), strTokenB.end(), writableB);
        writableB[strTokenB.size()] = '\0';
        printf("Token2B is %s\n", writableB);
        data3->item = new_Token(writableB);

        newFact->atom = data1;

        PlNode* thisFact = gorig_initial_facts->sons;
        PlNode* lastFact = gorig_initial_facts->sons;
        for (thisFact = gorig_initial_facts->sons; thisFact->next; thisFact = thisFact->next);
        thisFact->next = newFact;
      }
      std::cout << "Obstacles Added" << '\n';
    }

    // Update INITAIL position to CURRENT position.
    std::string strTokenC;
    {
      std::ostringstream ss;
      ss << "X";
      ss << static_cast<int>(wbcGoal_Status.curPosition().x());
      ss << static_cast<int>(wbcGoal_Status.curPosition().y());
      printf("strTokenC is %s\n", ss.str().c_str());
      strTokenC = ss.str();
    }
    char * writableC = new char[strTokenC.size() + 1];
    std::copy(strTokenC.begin(), strTokenC.end(), writableC);
    writableC[strTokenC.size()] = '\0';
    gorig_initial_facts->sons->atom->next->next->item = new_Token(writableC);
    std::cout << "Initial Location Updated" << '\n';
  }

}

//void output_Plan(*(search_prob.task().actions()),plan.size() );

void output_Plan (const aptk::Action& action) {

  std::stringstream ss(action.signature());
  std::string token;
  int counter = 0;
  while (ss >> token) {
    if (counter++ == 2) {
      std::cout << token << std::endl;
      std::string xPos(token,1,1);
      std::string yPos(token,2,1);
      guWhiteboard::GOAL_Control thisIntersection;
      thisIntersection.goal().set_x(atoi(xPos.c_str()));
      thisIntersection.goal().set_y(atoi(yPos.c_str()));
      pathList.push_back(thisIntersection);
    }
  }
}

void do_reset() {
// do anything that needs to be done for a reset.

}


void loadSettings() {
  //  Get the DOMAIN File Name
  wbcDomain_Filename = wbhDomain_Filename.get();
  std::cout << "Domain file: " << wbcDomain_Filename.filename() << std::endl;
  {
    std::ifstream domainFile(wbcDomain_Filename.filename());
    if (domainFile.good()) {
      myDomain = wbcDomain_Filename.filename();
      validDomainFile = true;
      std::cout << "Domain file Found." << std::endl;
    } else {
      std::cout << "THE DOMAIN FILE COULD NOT BE FOUND, please check the path." << std::endl;
      validDomainFile = false;
    }
  }
  //  Get the PROBLEM File Name
  wbcProblem_Filename = wbhProblem_Filename.get();
  std::cout << "Problem file: " << wbcProblem_Filename.filename() << std::endl;
  {
    std::ifstream problemFile(wbcProblem_Filename.filename());
    if (problemFile.good()) {
      myProblem = wbcProblem_Filename.filename();
      validProblemFile = true;
      std::cout << "Problem file Found." << std::endl;
    } else {
      std::cout << "THE PROBLEM FILE COULD NOT BE FOUND, please check the path." << std::endl;
      validProblemFile = false;
    }
  }
  // Get the current planner settings being requested
  wbcPlanner_Settings = wbhPlanner_Settings.get();
  max_novelty = wbcPlanner_Settings.max_novelty();
  cost = wbcPlanner_Settings.cost();
  bound = wbcPlanner_Settings.bound();
  budget = wbcPlanner_Settings.budget();
  heuristic = wbcPlanner_Settings.heuristic();
  anytime = wbcPlanner_Settings.anytime();
  delayed = wbcPlanner_Settings.delayed();
  greedy = wbcPlanner_Settings.greedy();
  engine = wbcPlanner_Settings.engine();  /// The search engine to use
  // Get Current Location
  wbcGoal_Status = wbhGoal_Status.get();  /// We need to know the current position of the robot.
}


void loadObstacles() {
  const char PROPERTY_SEPARATOR = ':';

  wbcObstacles_Filename = wbhObstacles_Filename.get();
  std::cout << "Obstacle file: " << wbcObstacles_Filename.filename() << std::endl;
  std::ifstream obstaclesFile(wbcObstacles_Filename.filename());
  if (obstaclesFile.good()) {
    std::cout << "Loading known obstacles." << std::endl;
    std::string aLine;
    while(std::getline(obstaclesFile,aLine)) {
      std::string key(aLine);
      guWhiteboard::Plan_Obstacle thisObstacle(key);

      obstacleList.push_back(thisObstacle);
    }
    obstaclesFile.close();
    std::cout << obstacleList.size() << " Obstacle(s) have been loaded." << std::endl;
  } else {
    std::cout << "Obstacle file could not accessed, no obstacles loaded." << std::endl;
  }
}


void getNewPlan() {

  pathList.clear();
  loadSettings();
  obstacleList.clear();
  // Get Obstacle List using an URI
  loadObstacles();
//  checkANDgetObstacleList();  // This used the Obstacle_List whiteboard class, which could cause the task to lock
  if (mapEngineIndex[engine] && validDomainFile && validProblemFile) {
    aptk::FF_Parser::get_problem_description( myDomain, myProblem, prob);
  //  aptk::FF_Parser::alter_problem();
    FF_alter_problem();
    aptk::FF_Parser::build_problem(prob);
    aptk::FF_Parser::Instantiate_problem(prob);
    Fwd_Search_Problem	search_prob( &prob );
    switch (mapEngineIndex[engine]) {
      case eP1: {
        std::cout << "################################     BFS_HMAX     ################################" << std::endl;
        std::ofstream details( "execution.details" );
        std::string plan_filename("plan.ipc");
        // NOT using the return value in this example
        float at_search_t = BFS_HMAX_do_search(search_prob, cost, details, plan_filename,  anytime, delayed, greedy );
        std::cout << "##################################################################################" << std::endl;
        break;
      }
      case eP2: {
        std::cout << "################################       BRFS       ################################" << std::endl;
        prob.initialize_successor_generator();
        std::cout << "Starting search with BrFS (time budget is 60 secs)..." << std::endl;
        BRFS_Fwd brfs_engine( search_prob );
        // NOT using the return value in this example
        float brfs_t = BRFS_do_search( brfs_engine, prob, 0.0f, "brfs.log" );
        std::cout << "BrFS search completed in " << brfs_t << " secs, check 'brfs.log' for details" << std::endl;
        std::cout << "##################################################################################" << std::endl;
        break;
      }
      case eP3: {
        std::cout << "################################       DAS       #################################" << std::endl;
        DAS engine( search_prob );
        DASPLANNER_do_search( engine, prob, budget - 0.005f, "das.log" );
        std::cout << "##################################################################################" << std::endl;
        break;
      }
      case eP4:
      case eP5:
      case eP6:
      case eP7:
      case eP8:
      case eP9:
      case eP10:
      default:
        break;
    }
    aptk::FF_Parser::clean_up(prob);
    std::ostringstream requestedPlanFilename;
    requestedPlanFilename << "Plan" << wbcManager_Status.to_string();
    std::ofstream planFile( requestedPlanFilename.str().c_str());
    if (!pathList.empty()) {
      if (planFile.good()) {
        std::cout << "Saving Requested Plan file as: " << requestedPlanFilename.str() << std::endl;
        for (uint32_t i=pathList.size(); i >0; i--){
            planFile << pathList[i-1].to_string() << '\n';
        }
        planFile.close();
      } else {
        std::cout << "Error opening " << requestedPlanFilename.str() << "Plan file, cannot save result." << std::endl;
      }
    } else {
      // No Plan Found
      std::cout << "No Plan Found." << std::endl;
      if (planFile.good()) {
        std::cout << "Saving Requested Plan file as: " << requestedPlanFilename.str() << std::endl;
        planFile << "NO PLAN" << '\n';
        planFile.close();
      } else {
        std::cout << "Error opening " << requestedPlanFilename.str() << "Plan file, cannot save result." << std::endl;
      }
    }
  } else {
    std::cout << "INVALID PLANNING ENGINE selected, please correct this before continuing." << std::endl;
  }
}


int main( int argc, char** argv ) {

  char cwd[FILENAME_MAX];
  if (!getcwd(cwd, sizeof(cwd))) { return errno; }

  std::cout << "*******************************     STARTING     *******************************" << std::endl;
  initialise_mapEngineIndex();  /// Setup the map enabling engine selection base on string names.


  gu_simple_whiteboard_descriptor* wbd = get_local_singleton_whiteboard();
  // Subtract from each to handle initial conditions, where a valid message might already be there.
  ctrPlan_Manager_Status = wbd->wb->event_counters[guWhiteboard::kPlan_Manager_Status_v]-1;
  ctrPlan_Goal_List = wbd->wb->event_counters[guWhiteboard::kPlan_Goal_List_v]=1;
  ctrPlan_Obstacle_List = wbd->wb->event_counters[guWhiteboard::kPlan_Obstacle_List_v]-1;

  wbcPlanner_Status = wbhPlanner_Status.get();
  while (true) {
    uint16_t  curCtrPlan_Manager_Status = wbd->wb->event_counters[guWhiteboard::kPlan_Manager_Status_v];
    uint16_t  curCtrPlan_Goal_List = wbd->wb->event_counters[guWhiteboard::kPlan_Goal_List_v];
    uint16_t  curCtrPlan_Obstacle_List = wbd->wb->event_counters[guWhiteboard::kPlan_Obstacle_List_v];

    wbcManager_Status = wbhManager_Status.get();
      if (wbcManager_Status.planHash() != wbcPlanner_Status.planHash() && wbcManager_Status.planHash() != 0) {
        //  Need to either produce a new plan
        //  or retrieve an existing one.
        planSent = false;
        std::ostringstream requestedPlanFilename;
        requestedPlanFilename << cwd << "/Plan" << wbcManager_Status.to_string();
        std::cout << "Requested Plan : " << wbcManager_Status.to_string() << std::endl;
        std::ifstream requestedPlanFile(requestedPlanFilename.str());
        if (!requestedPlanFile.good()) {
          // We need to create a plan first.
          getNewPlan();
        }
//        sendFromFile(wbcManager_Status.to_string());
        if (requestedPlanFilename.str().size()<= MAX_FILEPATH_LENGTH) {
          wbcPlan_Filename = requestedPlanFilename.str();
          wbhPlan_Filename.set(wbcPlan_Filename);
        } else {
            std::cout << "Plan's filename and path are to large (" << requestedPlanFilename.str().size() << ") for the whiteboard. Maximum length is: " << MAX_FILEPATH_LENGTH<< std::endl;
        }
        wbcPlanner_Status.planHash() = wbcManager_Status.planHash();
        wbhPlanner_Status.set(wbcPlanner_Status);
      }
      ctrPlan_Manager_Status = curCtrPlan_Manager_Status;
    protected_usleep(32000);

  }
  std::cout << "THIS IS WEIRD" << std::endl;
	return 0;
}

