wbcObstacle_List.obstacle(obstacleListElementsFilled) = obstacleList[wbcObstacle_List.startoff()+obstacleListElementsFilled];
std::cout << machine_name() << "::" << state_name() << "::wbcObstacle_List.obstacle = " << std::boolalpha << wbcObstacle_List.obstacle(obstacleListElementsFilled).description() << '\n';

obstacleListElementsFilled++;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
