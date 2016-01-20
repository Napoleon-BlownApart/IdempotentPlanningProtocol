wbcEPuckGSM_Status = wbhEPuckGSM_Status.get();
seePath         = wbcEPuckGSM_Status.gs(0).value()  > PATH_THRESHOLD;
seeIntersection = wbcEPuckGSM_Status.gs(0).value()  < INTERSECTION_THRESHOLD;
#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
