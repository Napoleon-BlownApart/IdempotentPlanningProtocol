willSuspend = wbcEpuck_Test_Control.epuckFollowsLineSuspended() && !wbcEpuck_Test_Status.epuckFollowsLineSuspended();
willResume = !wbcEpuck_Test_Control.epuckFollowsLineSuspended() && wbcEpuck_Test_Status.epuckFollowsLineSuspended();
noChange = wbcEpuck_Test_Control.epuckFollowsLineSuspended() == wbcEpuck_Test_Status.epuckFollowsLineSuspended();

#ifdef DEBUG
  std::cout << machine_name() << "::" << state_name() << "::Checking State" << '\n';
#endif
