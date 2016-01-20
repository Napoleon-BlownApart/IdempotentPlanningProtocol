wbcDirection_Control = wbhDirection_Control.get();

turnedLeft   = wbcDirection_Control.direction()==Direction::LEFT;
turnedRight  = wbcDirection_Control.direction()==Direction::RIGHT;
turnedAround = wbcDirection_Control.direction()==Direction::AROUNDRIGHT||wbcDirection_Control.direction()==Direction::AROUNDLEFT;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
