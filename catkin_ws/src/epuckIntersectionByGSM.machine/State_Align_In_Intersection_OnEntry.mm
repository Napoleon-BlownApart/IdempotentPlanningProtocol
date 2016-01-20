double diff = (wbcEPuckGSM_Status.gs(0).value() - wbcEPuckGSM_Status.gs(2).value());
double leftSpeed = (TURN_FACTOR * MAX_SPEED) - (ALIGN_GAIN * 0.5 * diff);
double rightSpeed = (TURN_FACTOR * MAX_SPEED) + (ALIGN_GAIN * 0.5 * diff);

wbcDifferentialRobot_Control = wbhDifferentialRobot_Control.get();
wbcDifferentialRobot_Control.left_motor().set_speed(static_cast<int16_t>(leftSpeed));
wbcDifferentialRobot_Control.right_motor().set_speed(static_cast<int16_t>(rightSpeed));
wbhDifferentialRobot_Control.set(wbcDifferentialRobot_Control);

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
