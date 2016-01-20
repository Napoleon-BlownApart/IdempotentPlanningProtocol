wbcIntersection_Status.directions().set_direction(Direction::BACK);
wbcIntersection_Status.set_scanComplete(false);
wbhIntersection_Status.set(wbcIntersection_Status);

wbcEPuckGSM_Control.set_gs(0,1);
wbcEPuckGSM_Control.set_gs(1,1);
wbcEPuckGSM_Control.set_gs(2,1);
wbhEPuckGSM_Control.set(wbcEPuckGSM_Control);
std::cout << machine_name() << "::" << state_name() << "::Enabled GSM = " << std::boolalpha << wbhEPuckGSM_Control().description() << '\n';

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
