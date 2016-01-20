wbcDifferentialRobot_Control = wbhDifferentialRobot_Control.get();
wbcDifferentialRobot_Control.left_motor().set_speed(0);
wbcDifferentialRobot_Control.right_motor().set_speed(0);
wbhDifferentialRobot_Control.set(wbcDifferentialRobot_Control);
wbcGoal_Control = wbhGoal_Control.get();

invalidGoal = (wbcGoal_Control.goal().x()==0)||(wbcGoal_Control.goal().y()==0);

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
  fprintf(stderr,"%s::#############################\n",machine_name());
  fprintf(stderr,"%s::# STOP!!!!!    Invalid Goal #\n",machine_name());
  fprintf(stderr,"%s::#############################\n",machine_name());
#endif
