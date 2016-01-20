gu_simple_whiteboard_descriptor* wbd = get_local_singleton_whiteboard();
plannerStatusMsgCnt = wbd->wb->event_counters[kPlan_Obstacle_List_v];

lastPlanHash = wbcManager_Status.planHash();
std::ostringstream hashSS;
hashSS  << wbcDomain_Filename.to_string() \
        << wbcProblem_Filename.to_string() \
        << wbcPlanner_Settings.to_string() \
        << wbcGoal_Status.curPosition().to_string() \
        << obstacleStr;
wbcManager_Status.set_planHash(str_hash(hashSS.str()));
//wbcManager_Status.set_plan(false);
wbhManager_Status.set(wbcManager_Status);
waitingForPlan = true;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
  std::cout << machine_name() << "::" << state_name() << "::obstacleStr = " << std::boolalpha << obstacleStr << '\n';
  std::cout << machine_name() << "::" << state_name() << "::hashSS.str() = " << std::boolalpha << hashSS.str() << '\n';
#endif
