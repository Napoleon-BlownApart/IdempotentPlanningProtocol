wbcEPuckProximity_Status = wbhEPuckProximity_Status.get();

obstacleDetected = (wbcEPuckProximity_Status.ps(0).value()>RANGE_THRESHOLD||wbcEPuckProximity_Status.ps(7).value()>RANGE_THRESHOLD);

#ifdef DEBUG
  fprintf(stderr,"%s::%s:Internal Done\n",machine_name(),state_name());
#endif
