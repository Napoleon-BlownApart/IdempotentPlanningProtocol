wbcCurrentPosition.goal().set_x(wbcCurrentPosition.goal().x()-1);
wbhCurrentPosition.set(wbcCurrentPosition);

fprintf(stderr,"%s::%s::Position = %d,%d\n",machine_name(),state_name(),wbcCurrentPosition.goal().x(), wbcCurrentPosition.goal().y());

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
