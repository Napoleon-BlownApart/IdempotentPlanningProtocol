wbcDifferentialRobot_Control.left_motor().set_speed(0);
wbcDifferentialRobot_Control.right_motor().set_speed(0);
wbhDifferentialRobot_Control.set(wbcDifferentialRobot_Control);

#ifdef DEBUG
  fprintf(stderr,"%s:OnEntry Done\n",state_name());
  fprintf(stderr,"An ERROR has occurred\n");
#endif
