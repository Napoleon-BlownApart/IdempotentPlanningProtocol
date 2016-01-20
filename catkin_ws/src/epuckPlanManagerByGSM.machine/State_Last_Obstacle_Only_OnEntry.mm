#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Starting\n",machine_name(),state_name());
#endif
wbcObstacle_List.obstacle(0) = obstacleList.back();
wbcObstacle_List.set_startoff(obstacleList.size()-1);

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
