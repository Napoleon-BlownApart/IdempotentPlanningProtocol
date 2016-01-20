wbcDirection_Control.set_direction(Direction::BACK);
wbhDirection_Control.set(wbcDirection_Control);

restart("epuckFollowLineByGSM");

//#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done (Reset Direction_Control)\n",machine_name(),state_name());
//#endif
