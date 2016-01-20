wbcDirection_Control.set_direction(Direction::BACK);
wbhDirection_Control.set(wbcDirection_Control);

srand(1);
#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
