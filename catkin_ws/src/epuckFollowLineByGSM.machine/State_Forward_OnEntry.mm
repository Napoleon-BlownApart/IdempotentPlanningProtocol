wbcEPuckGSM_Status = wbhEPuckGSM_Status.get();

veeringLeft   = (wbcEPuckGSM_Status.gs(2).value()>PATH_THRESHOLD);
veeringRight  = (wbcEPuckGSM_Status.gs(0).value()>PATH_THRESHOLD);

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
