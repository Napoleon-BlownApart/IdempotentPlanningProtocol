wbcGoal_Control = wbhGoal_Control.get();

wbcDifferentialRobot_Control = wbhDifferentialRobot_Control.get();
wbcDifferentialRobot_Control.left_motor().set_speed(0);
wbcDifferentialRobot_Control.right_motor().set_speed(0);
wbhDifferentialRobot_Control.set(wbcDifferentialRobot_Control);

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif // DEBUG
