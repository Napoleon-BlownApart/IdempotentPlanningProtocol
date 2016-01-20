const char PROPERTY_SEPARATOR = ':';
//getPlanningControl message
//#ifdef DEBUG
//  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
//#endif
wbcPlanner_Status = wbhPlanner_Status.get();
wbcObstacle_List = wbhObstacle_List.get();
wbcGoal_Status = wbhGoal_Status.get();
wbcObstacleOnPath = wbhObstacleOnPath.get();


/** Planner's Needs */
gu_simple_whiteboard_descriptor* wbd = get_local_singleton_whiteboard();
int newObstacleListMsgCnt = wbd->wb->event_counters[kPlan_Obstacle_List_v];

obstacleListRequested = ( /**wbcObstacle_List.startoff()!=0 &&*/
                          /*!wbcObstacle_List.obstacle(0).isValidLocation() && */
//                          wbcObstacle_List.obstacle(0).intersectionA().x()==0 &&
//                          wbcObstacle_List.obstacle(0).intersectionA().y()==0 &&
//                          wbcObstacle_List.obstacle(0).intersectionB().x()==0 &&
//                          wbcObstacle_List.obstacle(0).intersectionB().y()==0 &&
                          obstacleListMsgCnt != newObstacleListMsgCnt /** &&
                          waitingForPlan */
                        );

/**  ePuck's Needs */
int colDiff = wbcGoal_Control.goal().x()-wbcGoal_Status.curPosition().x();
int rowDiff = wbcGoal_Control.goal().y()-wbcGoal_Status.curPosition().y();
int absColDiff = abs(colDiff);
int absRowDiff = abs(rowDiff);

obstacle = (wbcObstacleOnPath.obstacle()) && (!(absColDiff > 1 || absRowDiff > 1 || absColDiff == absRowDiff));

unreachable = ((absColDiff > 1 || absRowDiff > 1 || absColDiff == absRowDiff));

atSubGoal = (wbcGoal_Status.curPosition().x() == wbcGoal_Status.goal().x()) &&
            (wbcGoal_Status.curPosition().y() == wbcGoal_Status.goal().y()) &&
            !wbcGoal_Status.state().didFail() &&
            (wbcGoal_Status.curPosition().x() == wbcGoal_Control.goal().x()) &&
            (wbcGoal_Status.curPosition().y() == wbcGoal_Control.goal().y());

std::ostringstream ss;
ss << wbcGoal_Status.curPosition().to_string() << PROPERTY_SEPARATOR << wbcGoal_Control.goal().to_string();
obstacleMap_it = obstacleMap.find(ss.str());

bool underway = !atSubGoal && !unreachable && (obstacleMap_it == obstacleMap.end());

needNewPlan = (unreachable || obstacleProcessed || ((pathList.size() == 0) && (!underway || firstPass) )) && (!planIsNew && !waitingForPlan);

int newplannerStatusMsgCnt = wbd->wb->event_counters[kPlan_Planner_Status_v];
planReady = (wbcManager_Status.planHash() == wbcPlanner_Status.planHash()) && waitingForPlan && (plannerStatusMsgCnt != newplannerStatusMsgCnt);
plannerStatusMsgCnt = newplannerStatusMsgCnt;
//subGoalAchieved = subGoalAchieved ||

std::cout << machine_name() << "::" << state_name() << "::wbcManager_Status.planHash() = " << std::boolalpha << wbcManager_Status.description() << '\n';
std::cout << machine_name() << "::" << state_name() << "::wbcPlanner_Status.planHash() = " << std::boolalpha << wbcPlanner_Status.description() << '\n';
std::cout << machine_name() << "::" << state_name() << "::underway = " << std::boolalpha << underway << '\n';
std::cout << machine_name() << "::" << state_name() << "::wbcObstacleOnPath = " << std::boolalpha << wbcObstacleOnPath.obstacle() << '\n';
std::cout << machine_name() << "::" << state_name() << "::didFail = " << std::boolalpha << wbcGoal_Status.state().didFail() << '\n';
std::cout << machine_name() << "::" << state_name() << "::obstacleListRequested = " << std::boolalpha << obstacleListRequested << '\n';
std::cout << machine_name() << "::" << state_name() << "::obstacle = " << std::boolalpha << obstacle << '\n';
std::cout << machine_name() << "::" << state_name() << "::unreachable = " << std::boolalpha << unreachable << '\n';
std::cout << machine_name() << "::" << state_name() << "::atSubGoal = " << std::boolalpha << atSubGoal << '\n';
std::cout << machine_name() << "::" << state_name() << "::obstacleProcessed = " << std::boolalpha << obstacleProcessed << '\n';
std::cout << machine_name() << "::" << state_name() << "::planIsNew = " << std::boolalpha << planIsNew << '\n';
std::cout << machine_name() << "::" << state_name() << "::needNewPlan = " << std::boolalpha << needNewPlan << '\n';
std::cout << machine_name() << "::" << state_name() << "::waitingForPlan = " << std::boolalpha << waitingForPlan << '\n';
std::cout << machine_name() << "::" << state_name() << "::pathList.size() == 0 = " << std::boolalpha << (pathList.size() == 0) << '\n';
std::cout << machine_name() << "::" << state_name() << "::planReady = " << std::boolalpha << planReady << '\n';
std::cout << machine_name() << "::" << state_name() << "::SAME HASH = " << std::boolalpha << (wbcManager_Status.planHash() == wbcPlanner_Status.planHash()) << '\n';
fprintf(stderr,"%s::%s::Current Goal     = (%d,%d)\n",machine_name(),state_name(),wbcGoal_Status.goal().x(),wbcGoal_Status.goal().y());
fprintf(stderr,"%s::%s::Current Position = (%d,%d)\n",machine_name(),state_name(),wbcGoal_Status.curPosition().x(),wbcGoal_Status.curPosition().y());


obstacleProcessed = false;
firstPass = false;

//goalAchieved = goalAchieved && !unreachable;

//validGoal = !unreachable && pathList.size()!=0
//((wbcGoal_Status.goal().x() == 0) && (wbcGoal_Status.goal().y() == 0));
//wbcManager_Status.set_plan(unreachable );
//wbcManager_Status.set_numUnits(static_cast<int32_t>(!unreachable));
//wbhManager_Status.set(wbcManager_Status);



    // Goal is Manhattan Adjacent and we are NOT already there, then we failed because of an obstacle.
//fprintf(stderr,"%s::%s: Unreachable Goal\n",machine_name(),state_name());
//wbcPlanner_Status.plan()


/*  OLD Transitions:
0:  ((!wbcManager_Status.plan())&&(wbcManager_Status.numUnits()!=0))||((!wbcPlanner_Status.plan())&&(wbcPlanner_Status.numUnits()!=0))
3:  obstacleListRequested  // (obstacleList.size()!=0)&&(wbcObstacle_List.startoff()!=0)&&(((wbcObstacle_List.obstacle(0).intersectionA().x()==0)&&(wbcObstacle_List.obstacle(0).intersectionA().y()==0))&&((wbcObstacle_List.obstacle(0).intersectionB().x()==0)&&(wbcObstacle_List.obstacle(0).intersectionB().y()==0)))
4:  (wbcPlanner_Status.planHash()==wbcManager_Status.planHash())&&needPlan  //  (wbcPlanner_Status.plan())&&(wbcManager_Status.plan())
*/
