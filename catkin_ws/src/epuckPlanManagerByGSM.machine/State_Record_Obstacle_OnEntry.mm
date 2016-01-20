const char PROPERTY_SEPARATOR = ':';

std::ostringstream ss;
ss << wbcGoal_Status.curPosition().to_string() << PROPERTY_SEPARATOR << wbcGoal_Control.goal().to_string();
newObstacle = false;
obstacleMap_it = obstacleMap.find(ss.str());
if (obstacleMap_it == obstacleMap.end()) {
  newObstacle = true;
  Plan_Obstacle thisObstacle;
  thisObstacle.intersectionA() = wbcGoal_Status.curPosition();
  thisObstacle.intersectionB() = wbcGoal_Control.goal();
//  thisObstacle.set_isValidLocation(true);
  obstacleMap[ss.str()] = thisObstacle;
  std::cout << machine_name() << "::" << state_name() << "::Recorded Obstacle = " << std::boolalpha << thisObstacle.description() << '\n';
  obstacleList.push_back(thisObstacle);
}
obstacleProcessed = true;
std::cout << machine_name() << "::" << state_name() << "::newObstacle = " << std::boolalpha << newObstacle << '\n';
// Post number of obstacles
//wbcManager_Status.set_numUnits(obstacleList.size());

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
