wbcEPuckGSM_Status = wbhEPuckGSM_Status.get();
wbcObstacleOnPath = wbhObstacleOnPath.get();

intersectionDetected    = wbcEPuckGSM_Status.gs(1).value()< INTERSECTION_THRESHOLD;
intersectionNotDetected = wbcEPuckGSM_Status.gs(1).value()>=INTERSECTION_THRESHOLD;
enteringIntersection    = gsCenterIntersectionTrigger>=SENSOR_TRIGGER_SIZE;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
//  fprintf(stderr,"%s::%s:Counter = %d\n",machine_name(),state_name(),gsCenterIntersectionTrigger);
//  fprintf(stderr,"%s::%s:Sensor = %d\n",machine_name(),state_name(),wbcEPuckGSM_Status.gs(1).value());
//  fprintf(stderr,"%%s::%s:Obstacle = %s\n",machine_name(),state_name(),( (wbcObstacleOnPath.obstacle())?"True":"False") );
//  fprintf(stderr,"%%s::%s:Obstacle = %s\n",machine_name(),state_name(),( (is_running("epuckFollowLineByGSM"))?"True":"False") );
#endif
