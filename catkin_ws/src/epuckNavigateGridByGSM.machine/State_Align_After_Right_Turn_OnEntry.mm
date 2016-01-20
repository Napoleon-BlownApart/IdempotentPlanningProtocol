wbcEPuckProximity_Status = wbhEPuckProximity_Status.get();
wbcEPuckGSM_Status = wbhEPuckGSM_Status.get();
wbcDifferentialRobot_Status = wbhDifferentialRobot_Status.get();

if (wbcEPuckGSM_Status.gs(0).value() > PATH_THRESHOLD) {
  gsLeftPathTrigger++;
} else {
   gsLeftPathTrigger = 0;
}
#ifdef DEBUG
  fprintf(stderr,"%s:OnEntry Done\n",state_name());
#endif
