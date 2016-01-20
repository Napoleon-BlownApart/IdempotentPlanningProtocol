needAlign = gsLeftPathTrigger>=SENSOR_TRIGGER_SIZE||gsRightPathTrigger>=SENSOR_TRIGGER_SIZE;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
