//load planList with received items
wbcGoal_List = wbhGoal_List.get();
#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif


/* Old Transitions
0:  wbcGoal_List.startoff()!=planElements   //  (!wbcPlanner_Status.plan())&&(wbcPlanner_Status.numUnits()!=0)
1:  (wbcPlanner_Status.numUnits()-wbcGoal_List.startoff())<GOAL_ENVELOPE_SIZE
*/
