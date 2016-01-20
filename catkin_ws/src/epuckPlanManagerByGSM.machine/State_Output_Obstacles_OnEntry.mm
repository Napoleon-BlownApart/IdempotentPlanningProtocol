// send obstacles starting with number wbcObstacle_List.startoff()

/**
OBSTACLE_ENVELOPE_SIZE
*/
obstacleListElementsFilled = 0;
guWhiteboard::Plan_Obstacle_List newList;
newList.set_startoff(wbcObstacle_List.startoff());
newList.obstacle(0).intersectionA().set_x(-1);
newList.obstacle(0).intersectionA().set_y(-1);
wbcObstacle_List = newList;
std::cout << machine_name() << "::" << state_name() << "::Obstacle_List_StartOff = " << std::boolalpha << wbcObstacle_List.startoff() << '\n';
std::cout << machine_name() << "::" << state_name() << "::obstacleList_Size = " << std::boolalpha << obstacleList.size() << '\n';
#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
