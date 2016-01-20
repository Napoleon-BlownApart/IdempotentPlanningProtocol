willSuspend = wbcEpuck_Test_Control.epuckTurnSuspended() && !wbcEpuck_Test_Status.epuckTurnSuspended();
willResume = !wbcEpuck_Test_Control.epuckTurnSuspended() && wbcEpuck_Test_Status.epuckTurnSuspended();
noChange = wbcEpuck_Test_Control.epuckTurnSuspended() == wbcEpuck_Test_Status.epuckTurnSuspended();

#ifdef DEBUG
  std::cout << machine_name() << "::" << state_name() << "::Checking State" << '\n';
#endif
