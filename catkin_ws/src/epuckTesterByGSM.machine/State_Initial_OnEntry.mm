guWhiteboard::Epuck_Test tmpEpuck_Test_Msg;
wbhEpuck_Test_Status.set(tmpEpuck_Test_Msg);
tmpEpuck_Test_Msg = wbhEpuck_Test_Start_Up_Status.get();
wbhEpuck_Test_Control.set(tmpEpuck_Test_Msg);

#ifdef DEBUG
  std::cout << machine_name() << "::" << state_name() << "::Reading Start-Up State" << '\n';
#endif
