/** Send reset signal to the planner.
  *
  * plan() = false and numUnits!=0
  */
//wbcManager_Status.set_numUnits(1);  /// Any number but zero, with wbcManager_Status.plan() == false is a reset.
//wbcManager_Status.set_plan(false);  /// Set plan() == false for reset.
//wbhManager_Status.set(wbcManager_Status);

gu_simple_whiteboard_descriptor* wbd = get_local_singleton_whiteboard();
obstacleListMsgCnt = wbd->wb->event_counters[kPlan_Obstacle_List_v];
firstPass = true;
pathList.clear();
#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
  std::cout << machine_name() << "::" << state_name() << "::pathList.size() = " << std::boolalpha << pathList.size() << '\n';
#endif
