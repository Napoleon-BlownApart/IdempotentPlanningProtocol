wbcDifferentialRobot_Status = wbhDifferentialRobot_Status.get();
wbcDifferentialRobot_Control.left_motor().set_motorOn(wbcDifferentialRobot_Status.left_motor().motorOn());
wbcDifferentialRobot_Control.right_motor().set_motorOn(wbcDifferentialRobot_Status.right_motor().motorOn());
wbcDifferentialRobot_Control.left_motor().set_encoderOn(wbcDifferentialRobot_Status.left_motor().encoderOn());
wbcDifferentialRobot_Control.right_motor().set_encoderOn(wbcDifferentialRobot_Status.right_motor().encoderOn());
wbcDifferentialRobot_Control.left_motor().set_speed(0);
wbcDifferentialRobot_Control.right_motor().set_speed(0);
wbhDifferentialRobot_Control.set(wbcDifferentialRobot_Control);

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
  fprintf(stderr,"An ERROR has occurred\n");
#endif
