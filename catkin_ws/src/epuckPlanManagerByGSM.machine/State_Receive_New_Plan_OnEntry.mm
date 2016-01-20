//pathList.reserve(wbcPlanner_Status.numUnits());
//wbcGoal_Control.goal().set_x(2);
//wbcGoal_Control.goal().set_y(2);
//pathList.push_back(wbcGoal_Control);
//wbcGoal_Control.goal().set_x(3);
//wbcGoal_Control.goal().set_y(2);
//pathList.push_back(wbcGoal_Control);
//wbcGoal_Control.goal().set_x(4);
//wbcGoal_Control.goal().set_y(2);
//pathList.push_back(wbcGoal_Control);
//wbcGoal_Control.goal().set_x(5);
//wbcGoal_Control.goal().set_y(2);
//pathList.push_back(wbcGoal_Control);
//wbcGoal_Control.goal().set_x(6);
//wbcGoal_Control.goal().set_y(2);
//pathList.push_back(wbcGoal_Control);
//wbcGoal_Control.goal().set_x(6);
//wbcGoal_Control.goal().set_y(3);
//pathList.push_back(wbcGoal_Control);
//wbcGoal_Control.goal().set_x(5);
//wbcGoal_Control.goal().set_y(3);
//pathList.push_back(wbcGoal_Control);
//wbcGoal_Control.goal().set_x(4);
//wbcGoal_Control.goal().set_y(3);
//pathList.push_back(wbcGoal_Control);
//wbcGoal_Control.goal().set_x(3);
//wbcGoal_Control.goal().set_y(3);
//pathList.push_back(wbcGoal_Control);
//wbcGoal_Control.goal().set_x(3);
//wbcGoal_Control.goal().set_y(4);
//pathList.push_back(wbcGoal_Control);
//wbcGoal_Control.goal().set_x(3);
//wbcGoal_Control.goal().set_y(5);
//pathList.push_back(wbcGoal_Control);

// Request plan step X
// planList.reserve REQUIRED NUMBER

// Receive the list of sub-goals based on wbcPlanner_Status.
/**
  GOAL_ENVELOPE_SIZE
*/
waitingForPlan = false;
planIsNew = true;
std::cout << machine_name() << "::" << state_name() << "::pathList.size() = " << std::boolalpha << pathList.size() << '\n';
for (int i=0; i<pathList.size(); i++) {
  std::cout << machine_name() << "::" << state_name() << "::Entry " << i << " = " << std::boolalpha << pathList[i].description() << '\n';
}
std::cout << machine_name() << "::" << state_name() << "::planElements = " << std::boolalpha << planElements << '\n';

//  This code was used with the Plan_Goal_List whiteboard message.
//pathList.clear();
//planElements = 0;
//Plan_Goal_List wbcTmpGoal_List;
//wbhGoal_List.set(wbcTmpGoal_List);



const char PROPERTY_SEPARATOR = ':';

wbcPlan_Filename = wbhPlan_Filename.get();
std::cout << "Loading Plan: " << wbcPlan_Filename.filename() << std::endl;
std::ifstream planFile(wbcPlan_Filename.filename());
if (planFile.good()) {
  pathList.clear();
  std::string aLine;
  while(std::getline(planFile,aLine)) {
    std::string key(aLine);
    GOAL_Control thisGoal;
    std::istringstream iss(aLine);
    std::string token;
    getline(iss, token, PROPERTY_SEPARATOR);
    thisGoal.set_goal(token);
//    getline(iss, token, PROPERTY_SEPARATOR);
//    thisObstacle.set_intersectionB(token);
//    thisObstacle.set_isValidLocation(true);
//    obstacleMap[key] = thisObstacle;
    pathList.push_back(thisGoal);
  }
  std::cout << pathList.size() << " Sub-goal(s) have been loaded." << std::endl;
  for (int i=0; i<pathList.size(); i++) {
    std::cout << machine_name() << "::" << state_name() << "::Sub-Goal = " << std::boolalpha << pathList[i].to_string() << '\n';
  }
} else {
  std::cout << "Plan Not Found" << std::endl;
}


#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif

/*  OLD Transitions:
0 after_ms(32)
*/

