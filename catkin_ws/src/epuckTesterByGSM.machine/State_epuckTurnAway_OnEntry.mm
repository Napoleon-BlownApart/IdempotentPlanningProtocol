willSuspend = wbcEpuck_Test_Control.epuckTurnAwaySuspended() && !wbcEpuck_Test_Status.epuckTurnAwaySuspended();
willResume = !wbcEpuck_Test_Control.epuckTurnAwaySuspended() && wbcEpuck_Test_Status.epuckTurnAwaySuspended();
noChange = wbcEpuck_Test_Control.epuckTurnAwaySuspended() == wbcEpuck_Test_Status.epuckTurnAwaySuspended();

#ifdef DEBUG
  std::cout << machine_name() << "::" << state_name() << "::Checking State" << '\n';
#endif
