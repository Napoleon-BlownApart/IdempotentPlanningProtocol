willSuspend = wbcEpuck_Test_Control.epuckPlanManagerSuspended() && !wbcEpuck_Test_Status.epuckPlanManagerSuspended();
willResume = !wbcEpuck_Test_Control.epuckPlanManagerSuspended() && wbcEpuck_Test_Status.epuckPlanManagerSuspended();
noChange = wbcEpuck_Test_Control.epuckPlanManagerSuspended() == wbcEpuck_Test_Status.epuckPlanManagerSuspended();

#ifdef DEBUG
  std::cout << machine_name() << "::" << state_name() << "::Checking State" << '\n';
  std::cout << machine_name() << "::" << state_name() << "::wbcEpuck_Test_Control.epuckPlanManagerSuspended()" << std::boolalpha << wbcEpuck_Test_Control.epuckPlanManagerSuspended() << '\n';
  std::cout << machine_name() << "::" << state_name() << "::wbcEpuck_Test_Status.epuckPlanManagerSuspended()" << std::boolalpha << wbcEpuck_Test_Status.epuckPlanManagerSuspended() << '\n';
  std::cout << machine_name() << "::" << state_name() << "::willSuspend" << std::boolalpha << willSuspend << '\n';
  std::cout << machine_name() << "::" << state_name() << "::willResume" << std::boolalpha << willResume << '\n';
  std::cout << machine_name() << "::" << state_name() << "::noChange" << std::boolalpha << noChange << '\n';
#endif
