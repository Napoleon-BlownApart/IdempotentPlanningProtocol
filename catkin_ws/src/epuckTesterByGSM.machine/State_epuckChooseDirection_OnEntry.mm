willSuspend = wbcEpuck_Test_Control.epuckChooseDirectionSuspended() && !wbcEpuck_Test_Status.epuckChooseDirectionSuspended();
willResume = !wbcEpuck_Test_Control.epuckChooseDirectionSuspended() && wbcEpuck_Test_Status.epuckChooseDirectionSuspended();
noChange = wbcEpuck_Test_Control.epuckChooseDirectionSuspended() == wbcEpuck_Test_Status.epuckChooseDirectionSuspended();


#ifdef DEBUG
  std::cout << machine_name() << "::" << state_name() << "::Checking State" << '\n';
#endif
