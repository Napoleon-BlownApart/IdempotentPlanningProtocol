seePath         = wbcEPuckGSM_Status.gs(2).value()  > PATH_THRESHOLD;
seeIntersection = wbcEPuckGSM_Status.gs(2).value()  < INTERSECTION_THRESHOLD;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
