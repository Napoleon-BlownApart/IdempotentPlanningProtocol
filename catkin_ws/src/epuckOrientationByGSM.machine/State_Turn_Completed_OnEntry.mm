wbcDirection_Control = wbhDirection_Control.get();

finishedTurn = wbcDirection_Control.direction()==Direction::BACK;
#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
