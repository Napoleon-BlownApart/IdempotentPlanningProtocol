wbcDifferentialRobot_Control.left_motor().set_speed(static_cast<int16_t>(-TURN_FACTOR*MAX_SPEED));
wbcDifferentialRobot_Control.right_motor().set_speed(static_cast<int16_t>(TURN_FACTOR*MAX_SPEED));
wbhDifferentialRobot_Control.set(wbcDifferentialRobot_Control);
#ifdef DEBUG
  printf("Turn_Left:OnEntry Done\n");
#endif
