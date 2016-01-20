wbcEPuckProximity_Status = wbhEPuckProximity_Status.get();
wbcDifferentialRobot_Status = wbhDifferentialRobot_Status.get();
wbcEPuckGSM_Status = wbhEPuckGSM_Status.get();
wbcDifferentialRobot_Control.left_motor().set_speed(static_cast<int16_t>(TURN_FACTOR*MAX_SPEED));
wbcDifferentialRobot_Control.right_motor().set_speed(static_cast<int16_t>(-TURN_FACTOR*MAX_SPEED));
wbhDifferentialRobot_Control.set(wbcDifferentialRobot_Control);
#ifdef DEBUG
  printf("Beginning Right Enc = %d\n",encStateB4Maneuver.encoder[1]);
  printf("Current   Right Enc = %d\n",wbcDifferentialRobot_Status.right_motor().odo());
  printf("Difference  = %d\n",encStateB4Maneuver.encoder[1]-wbcDifferentialRobot_Status.right_motor().odo());
  printf("Turn_Right:Internal Done\n");
#endif
