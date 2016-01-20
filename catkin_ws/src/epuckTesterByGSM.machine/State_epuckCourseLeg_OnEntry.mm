willSuspend = wbcEpuck_Test_Control.epuckCourseLegSuspended() && !wbcEpuck_Test_Status.epuckCourseLegSuspended();
willResume = !wbcEpuck_Test_Control.epuckCourseLegSuspended() && wbcEpuck_Test_Status.epuckCourseLegSuspended();
noChange = wbcEpuck_Test_Control.epuckCourseLegSuspended() == wbcEpuck_Test_Status.epuckCourseLegSuspended();

#ifdef DEBUG
  std::cout << machine_name() << "::" << state_name() << "::Checking State" << '\n';
#endif
