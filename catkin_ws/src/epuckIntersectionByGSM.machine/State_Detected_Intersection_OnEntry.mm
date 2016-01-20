gsCenterIntersectionTrigger++;
wbcEPuckGSM_Status = wbhEPuckGSM_Status.get();

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
  std::cout << machine_name() << "::" << state_name() << "::Interseaction Reading = " << std::boolalpha << wbcEPuckGSM_Status.gs(1).value() << '\n';
  std::cout << machine_name() << "::" << state_name() << "::Interseaction Desc = " << std::boolalpha << wbcEPuckGSM_Status.gs(1).description() << '\n';
#endif
