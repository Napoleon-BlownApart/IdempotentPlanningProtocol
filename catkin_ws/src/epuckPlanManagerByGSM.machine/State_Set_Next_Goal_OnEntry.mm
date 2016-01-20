//GOAL_ENVELOPE_SIZE
wbcGoal_Control = pathList.back();
pathList.pop_back();
wbhGoal_Control.set(wbcGoal_Control);
planIsNew = false;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done - GOAL is %s\n",machine_name(),state_name(), wbcGoal_Control.goal().description().c_str());
#endif
