wbcDifferentialRobot_Control.left_motor().set_speed(0);
wbcDifferentialRobot_Control.right_motor().set_speed(0);
wbhDifferentialRobot_Control.set(wbcDifferentialRobot_Control);
#ifdef DEBUG
  printf("Stop:OnEntry Done\n");
#endif
