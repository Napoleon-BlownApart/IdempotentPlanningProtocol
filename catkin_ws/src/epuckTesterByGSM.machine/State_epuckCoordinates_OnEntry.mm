willSuspend = wbcEpuck_Test_Control.epuckCoordinatesSuspended() && !wbcEpuck_Test_Status.epuckCoordinatesSuspended();
willResume = !wbcEpuck_Test_Control.epuckCoordinatesSuspended() && wbcEpuck_Test_Status.epuckCoordinatesSuspended();
noChange = wbcEpuck_Test_Control.epuckCoordinatesSuspended() == wbcEpuck_Test_Status.epuckCoordinatesSuspended();

#ifdef DEBUG
  std::cout << machine_name() << "::" << state_name() << "::Checking State" << '\n';
#endif
