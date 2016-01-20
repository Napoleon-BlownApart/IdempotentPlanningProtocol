seePath         = wbcEPuckGSM_Status.gs(1).value()  > PATH_THRESHOLD;
seeIntersection = wbcEPuckGSM_Status.gs(1).value()  < INTERSECTION_THRESHOLD;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
