wbcEPuckGSM_Status = wbhEPuckGSM_Status.get();

//if (wbcEPuckGSM_Status.gs(0).value() > PATH_THRESHOLD) {
//  gsLeftPathTrigger++;
//  #ifdef DEBUG
//    fprintf(stderr,"%s::%s:Saw the path\n",machine_name(),state_name());
//  #endif
//} else {
//  gsLeftPathTrigger = 0;
//}

/// Use boolean logic instead of above if statements, and save on number of states
gsLeftPathTrigger+=(wbcEPuckGSM_Status.gs(0).value() > PATH_THRESHOLD);
gsLeftPathTrigger*=(wbcEPuckGSM_Status.gs(0).value() > PATH_THRESHOLD);

finishedTurn = gsLeftPathTrigger>=SENSOR_TRIGGER_SIZE;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
