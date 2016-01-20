willSuspend = wbcEpuck_Test_Control.epuckOrientationSuspended() && !wbcEpuck_Test_Status.epuckOrientationSuspended();
willResume = !wbcEpuck_Test_Control.epuckOrientationSuspended() && wbcEpuck_Test_Status.epuckOrientationSuspended();
noChange = wbcEpuck_Test_Control.epuckOrientationSuspended() == wbcEpuck_Test_Status.epuckOrientationSuspended();

#ifdef DEBUG
  std::cout << machine_name() << "::" << state_name() << "::Checking State" << '\n';
#endif
