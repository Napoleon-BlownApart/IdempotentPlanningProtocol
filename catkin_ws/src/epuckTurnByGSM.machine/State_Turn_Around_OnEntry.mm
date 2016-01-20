targetEncoderDelta = TURN_AROUND;

turningLeft   = wbcDirection_Control.direction()==Direction::AROUNDLEFT;
turningRight  = wbcDirection_Control.direction()==Direction::AROUNDRIGHT;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
