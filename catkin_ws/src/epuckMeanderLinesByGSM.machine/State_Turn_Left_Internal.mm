wbcEPuckProximity_Status = wbhEPuckProximity_Status.get();
wbcDifferentialRobot_Status = wbhDifferentialRobot_Status.get();
wbcEPuckGSM_Status = wbhEPuckGSM_Status.get();
wbcDifferentialRobot_Control.left_motor().set_speed(static_cast<int16_t>(-TURN_FACTOR*MAX_SPEED));
wbcDifferentialRobot_Control.right_motor().set_speed(static_cast<int16_t>(TURN_FACTOR*MAX_SPEED));
wbhDifferentialRobot_Control.set(wbcDifferentialRobot_Control);
#ifdef DEBUG
  printf("Turn_LeftInternal Done\n");
#endif
