wbcEPuckProximity_Status = wbhEPuckProximity_Status.get();
wbcDifferentialRobot_Status = wbhDifferentialRobot_Status.get();
wbcEPuckGSM_Status = wbhEPuckGSM_Status.get();
#ifdef DEBUG
  printf("Beginning Right Enc = %d\n",encStateB4Maneuver.encoder[1]);
  printf("Current   Right Enc = %d\n",wbcDifferentialRobot_Status.right_motor().odo());
  printf("Difference  = %d\n",encStateB4Maneuver.encoder[1]-wbcDifferentialRobot_Status.right_motor().odo());
  printf("Turn_Right:Internal Done\n");
#endif
