wbcEPuckProximity_Status = wbhEPuckProximity_Status.get();
wbcEPuckGSM_Status = wbhEPuckGSM_Status.get();
wbcDifferentialRobot_Status = wbhDifferentialRobot_Status.get();

if (wbcEPuckGSM_Status.gs(2).value() > PATH_THRESHOLD) {
  gsRightPathTrigger++;
} else {
  gsRightPathTrigger = 0;
}
#ifdef DEBUG
  printf("Align:OnEntry Done\n");
#endif
