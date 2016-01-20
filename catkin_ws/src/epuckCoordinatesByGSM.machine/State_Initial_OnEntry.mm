wbcCurrentPosition.goal().set_x(3);	// Column
wbcCurrentPosition.goal().set_y(6);	// Row
wbhCurrentPosition.set(wbcCurrentPosition);

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
  printf("%s::========================================================\n",machine_name());
  fprintf(stderr,"%s::%s::Position = %d,%d\n",machine_name(),state_name(),wbcCurrentPosition.goal().x(), wbcCurrentPosition.goal().y());
  printf("%s::========================================================\n",machine_name());
#endif
