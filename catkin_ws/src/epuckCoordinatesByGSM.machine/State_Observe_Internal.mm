wbcEPuckGSM_Status = wbhEPuckGSM_Status.get();

intersectionDetected    = wbcEPuckGSM_Status.gs(1).value()< INTERSECTION_THRESHOLD;
intersectionNotDetected = wbcEPuckGSM_Status.gs(1).value()>=INTERSECTION_THRESHOLD;
//enteringIntersection    = gsCenterIntersectionTrigger>=SENSOR_TRIGGER_SIZE;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:Internal Done\n",machine_name(),state_name());
#endif

