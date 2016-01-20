notFullwithMoreObstacles = (obstacleListElementsFilled<OBSTACLE_ENVELOPE_SIZE)&&(wbcObstacle_List.startoff()+obstacleListElementsFilled<obstacleList.size());
isFullorDone = (obstacleListElementsFilled>=OBSTACLE_ENVELOPE_SIZE) || (obstacleListElementsFilled>=obstacleList.size());
std::cout << machine_name() << "::" << state_name() << "::obstacleList.size() = " << std::boolalpha << obstacleList.size() << '\n';
std::cout << machine_name() << "::" << state_name() << "::obstacleListElementsFilled = " << std::boolalpha << static_cast<int>(obstacleListElementsFilled) << '\n';
std::cout << machine_name() << "::" << state_name() << "::isFullorDone = " << std::boolalpha << isFullorDone << '\n';
std::cout << machine_name() << "::" << state_name() << "::notFullwithMoreObstacles = " << std::boolalpha << notFullwithMoreObstacles << '\n';

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif

/* Old Transitions
0:  (!wbcPlanner_Status.plan())&&(wbcPlanner_Status.numUnits()!=0)

*/
