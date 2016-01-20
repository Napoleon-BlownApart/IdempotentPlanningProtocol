wbcEPuckProximity_Status = wbhEPuckProximity_Status.get();
wbcEPuckProximity_Control.set_ps(0,1);
wbcEPuckProximity_Control.set_ps(1,wbcEPuckProximity_Status.ps(1).enabled());
wbcEPuckProximity_Control.set_ps(2,wbcEPuckProximity_Status.ps(2).enabled());
wbcEPuckProximity_Control.set_ps(3,wbcEPuckProximity_Status.ps(3).enabled());
wbcEPuckProximity_Control.set_ps(4,wbcEPuckProximity_Status.ps(4).enabled());
wbcEPuckProximity_Control.set_ps(5,wbcEPuckProximity_Status.ps(5).enabled());
wbcEPuckProximity_Control.set_ps(6,wbcEPuckProximity_Status.ps(6).enabled());
wbcEPuckProximity_Control.set_ps(7,1);
wbhEPuckProximity_Control.set(wbcEPuckProximity_Control);
wbcObstacleOnPath.set_obstacle(false);
wbhObstacleOnPath.set(wbcObstacleOnPath);

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
