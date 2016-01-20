canGoRight = (!((wbcIntersection_Status.directions().direction())&Direction::RIGHT)&&(gsRightPathTrigger>=SENSOR_TRIGGER_SIZE)&&(gsCenterIntersectionTrigger>=SENSOR_TRIGGER_SIZE));


#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
