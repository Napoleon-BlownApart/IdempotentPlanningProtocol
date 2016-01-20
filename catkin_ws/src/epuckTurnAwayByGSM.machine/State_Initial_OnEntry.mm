wbcEPuckProximity_Control.set_ps(0,1);
wbcEPuckProximity_Control.set_ps(7,1);
wbhEPuckProximity_Control.set(wbcEPuckProximity_Control);
fprintf(stderr,"%s::ePuck Proximity setup for TurnAway\n",machine_name());

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
