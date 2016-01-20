angle= (angle + 90) % 360;
wbcAngle.set_angle(angle);
wbhAngle.set(wbcAngle);

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
  printf("%s::========================================================\n",machine_name());
  fprintf(stderr,"%s::Angle = %d\n",machine_name(),wbcAngle.angle());
  printf("%s::========================================================\n",machine_name());
#endif
