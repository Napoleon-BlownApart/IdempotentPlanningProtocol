wbcAngle = wbhAngle.get();

movedUp     = wbcAngle.angle()==0;
movedRight  = wbcAngle.angle()==90;
movedDown   = wbcAngle.angle()==180;
movedLeft   = wbcAngle.angle()==270;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
