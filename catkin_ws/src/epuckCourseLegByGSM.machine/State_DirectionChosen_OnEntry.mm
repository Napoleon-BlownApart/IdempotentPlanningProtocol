wbcIntersection_Status.directions().set_direction(Direction::BACK);
wbcIntersection_Status.set_scanComplete(false);
wbhIntersection_Status.set(wbcIntersection_Status);

wbhDirection_Control.set(wbcDirection_Control);
#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
