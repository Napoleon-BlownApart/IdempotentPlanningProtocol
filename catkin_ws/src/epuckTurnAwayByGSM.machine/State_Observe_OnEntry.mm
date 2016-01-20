wbcEPuckProximity_Status = wbhEPuckProximity_Status.get();
wbcDirection_Control = wbhDirection_Control.get();

obstacleOnLeft  = (wbcEPuckProximity_Status.ps(7).value()>RANGE_THRESHOLD)&&(wbcDirection_Control.direction()==Direction::BACK);
obstacleOnRight = (wbcEPuckProximity_Status.ps(0).value()>RANGE_THRESHOLD)&&(wbcDirection_Control.direction()==Direction::BACK);

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
