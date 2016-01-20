wbcEPuckGSM_Status = wbhEPuckGSM_Status.get();

//if (wbcEPuckGSM_Status.gs(2).value() > PATH_THRESHOLD) {
//  gsRightPathTrigger++;
//  #ifdef DEBUG
//    fprintf(stderr,"%s::%s:Saw the path\n",machine_name(),state_name());
//  #endif
//} else {
//  gsRightPathTrigger = 0;
//}

/// Use boolean logic instead of above if statements, and save on number of states
gsRightPathTrigger+=(wbcEPuckGSM_Status.gs(2).value() > PATH_THRESHOLD);
gsRightPathTrigger*=(wbcEPuckGSM_Status.gs(2).value() > PATH_THRESHOLD);

finishedTurn = gsRightPathTrigger>=SENSOR_TRIGGER_SIZE;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
