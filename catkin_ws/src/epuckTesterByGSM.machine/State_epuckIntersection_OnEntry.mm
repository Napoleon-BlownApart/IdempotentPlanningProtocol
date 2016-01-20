willSuspend = wbcEpuck_Test_Control.epuckIntersectionSuspended() && !wbcEpuck_Test_Status.epuckIntersectionSuspended();
willResume = !wbcEpuck_Test_Control.epuckIntersectionSuspended() && wbcEpuck_Test_Status.epuckIntersectionSuspended();
noChange = wbcEpuck_Test_Control.epuckIntersectionSuspended() == wbcEpuck_Test_Status.epuckIntersectionSuspended();

#ifdef DEBUG
  std::cout << machine_name() << "::" << state_name() << "::Checking State" << '\n';
#endif
