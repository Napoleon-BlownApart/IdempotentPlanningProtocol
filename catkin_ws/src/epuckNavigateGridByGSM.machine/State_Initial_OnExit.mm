wbcDifferentialRobot_Control.left_motor().set_speed(MAX_SPEED);
wbcDifferentialRobot_Control.right_motor().set_speed(MAX_SPEED);
wbhDifferentialRobot_Control.set(wbcDifferentialRobot_Control);
#ifdef DEBUG
  printf("Initial:OnExit Done\n");
#endif
