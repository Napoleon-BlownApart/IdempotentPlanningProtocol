willSuspend = wbcEpuck_Test_Control.epuckObstacleOnPathSuspended() && !wbcEpuck_Test_Status.epuckObstacleOnPathSuspended();
willResume = !wbcEpuck_Test_Control.epuckObstacleOnPathSuspended() && wbcEpuck_Test_Status.epuckObstacleOnPathSuspended();
noChange = wbcEpuck_Test_Control.epuckObstacleOnPathSuspended() == wbcEpuck_Test_Status.epuckObstacleOnPathSuspended();

#ifdef DEBUG
  std::cout << machine_name() << "::" << state_name() << "::Checking State" << '\n';
#endif
