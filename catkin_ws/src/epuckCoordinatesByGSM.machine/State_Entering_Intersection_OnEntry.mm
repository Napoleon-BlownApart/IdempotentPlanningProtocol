gsCenterIntersectionTrigger=0;
wbcObstacleOnPath = wbhObstacleOnPath.get();

backAfterObstacle = (wbcObstacleOnPath.obstacle())||(!is_running("epuckFollowLineByGSM"));
newIntersection = (!wbcObstacleOnPath.obstacle())&&(is_running("epuckFollowLineByGSM"));

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
  fprintf(stderr,"%s::Counter = %d\n",machine_name(),gsCenterIntersectionTrigger);
  fprintf(stderr,"%s::Obstacle = %s\n",machine_name(),( (wbcObstacleOnPath.obstacle())?"True":"False") );
  fprintf(stderr,"%s::Obstacle = %s\n",machine_name(),( (is_running("epuckFollowLineByGSM"))?"True":"False") );
#endif
