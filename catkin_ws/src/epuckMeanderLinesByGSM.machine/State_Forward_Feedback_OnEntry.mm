double diff = (wbcEPuckGSM_Status.gs(0).value() - wbcEPuckGSM_Status.gs(2).value());
double leftSpeed = MAX_SPEED-(ALIGN_GAIN*diff);
double rightSpeed = MAX_SPEED+(ALIGN_GAIN*diff);

wbcDifferentialRobot_Control.left_motor().set_speed(static_cast<int16_t>(leftSpeed));
wbcDifferentialRobot_Control.right_motor().set_speed(static_cast<int16_t>(rightSpeed));
wbhDifferentialRobot_Control.set(wbcDifferentialRobot_Control);

gsLeftPathTrigger = 0;
gsRightPathTrigger = 0;
#ifdef DEBUG
  printf("Forward_Feedback:OnEntry Done\n");
#endif
