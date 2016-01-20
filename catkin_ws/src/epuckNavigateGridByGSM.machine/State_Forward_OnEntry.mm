wbcEPuckProximity_Status = wbhEPuckProximity_Status.get();
wbcEPuckGSM_Status = wbhEPuckGSM_Status.get();
wbcDifferentialRobot_Status = wbhDifferentialRobot_Status.get();

if (wbcEPuckGSM_Status.gs(0).value() > PATH_THRESHOLD) {
  gsLeftPathTrigger++;
} else {
  gsLeftPathTrigger = 0;
}

if (wbcEPuckGSM_Status.gs(1).value() < INTERSECTION_THRESHOLD) {
  gsCenterIntersectionTrigger++;
} else {
  gsCenterIntersectionTrigger = 0;
}

if (wbcEPuckGSM_Status.gs(2).value() > PATH_THRESHOLD) {
  gsRightPathTrigger++;
} else {
  gsRightPathTrigger = 0;
}
#ifdef DEBUG
  printf("Forward:OnEntry Done\n");
#endif
