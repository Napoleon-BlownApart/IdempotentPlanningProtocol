gu_simple_whiteboard_descriptor* wbd = get_local_singleton_whiteboard();
u_int16_t sample1 = wbd->wb->event_counters[kPlan_Obstacle_List_v];
wbhObstacle_List.set(wbcObstacle_List);
u_int16_t sample2 = wbd->wb->event_counters[kPlan_Obstacle_List_v];
std::cout << machine_name() << "::" << state_name() << "::obstacleList to send = " << std::boolalpha << wbcObstacle_List.description() << '\n';
std::cout << machine_name() << "::" << state_name() << "::sample2-sample1 = " << std::boolalpha << static_cast<int>(sample2-sample1) << '\n';
std::cout << machine_name() << "::" << state_name() << "::sample1-sample2 = " << std::boolalpha << static_cast<uint16_t>(sample1-sample2) << '\n';
if (sample2-sample1==1 || sample1-sample2==65535) {
  /** If the event counter only incremented by one in the sample period,
    * then we were the only ones who posted & therefore we advance the
    * 'obstacleListMsgCnt' so we don't trigger an unnecessary iteration
    * of sending obstacles.
    *
    * This calculation takes care of wrap around.
    */
  obstacleListMsgCnt = wbd->wb->event_counters[kPlan_Obstacle_List_v];
}

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
