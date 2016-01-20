wbcEPuckGSM_Status = wbhEPuckGSM_Status.get();
intersectionDetected    = wbcEPuckGSM_Status.gs(1).value()< INTERSECTION_THRESHOLD;
intersectionNotDetected = wbcEPuckGSM_Status.gs(1).value()>=INTERSECTION_THRESHOLD;
enteringIntersection    = gsCenterIntersectionTrigger>=SENSOR_TRIGGER_SIZE;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
  std::cout << machine_name() << "::" << state_name() << "::wbcEPuckGSM_Status Reading GS(1).value = " << std::boolalpha << wbcEPuckGSM_Status.gs(1).value() << '\n';
  std::cout << machine_name() << "::" << state_name() << "::wbcEPuckGSM_Status GS(1) Desc = " << std::boolalpha << wbcEPuckGSM_Status.gs(1).description() << '\n';
  std::cout << machine_name() << "::" << state_name() << "::wbcEPuckGSM_Status Desc = " << std::boolalpha << wbcEPuckGSM_Status.description() << '\n';
  std::cout << machine_name() << "::" << state_name() << "::wbhEPuckGSM_Control Desc = " << std::boolalpha << wbhEPuckGSM_Control().description() << '\n';
#endif
