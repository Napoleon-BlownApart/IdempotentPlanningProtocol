wbcEPuckGSM_Control.set_gs(0,1);
wbcEPuckGSM_Control.set_gs(1,1);
wbcEPuckGSM_Control.set_gs(2,1);
wbhEPuckGSM_Control.set(wbcEPuckGSM_Control);
std::cout << machine_name() << "::" << state_name() << "::Enabled GSM = " << std::boolalpha << wbhEPuckGSM_Control().description() << '\n';

wbcEPuckLED_Control.led(0).set_enabled(true);	// Ring
wbcEPuckLED_Control.led(0).set_value(1);
wbcEPuckLED_Control.led(4).set_enabled(true);	// Tail lights
wbcEPuckLED_Control.led(4).set_value(1);
wbcEPuckLED_Control.led(8).set_enabled(true);	// Body
wbcEPuckLED_Control.led(8).set_value(1);
wbcEPuckLED_Control.led(9).set_enabled(true);	// Next to Camera
wbcEPuckLED_Control.led(9).set_value(1);
wbhEPuckLED_Control.set(wbcEPuckLED_Control);

wbcDifferentialRobot_Control.left_motor().set_motorOn(true);
wbcDifferentialRobot_Control.right_motor().set_motorOn(true);
wbcDifferentialRobot_Control.left_motor().set_encoderOn(true);
wbcDifferentialRobot_Control.right_motor().set_encoderOn(true);
wbcDifferentialRobot_Control.left_motor().set_speed(0);
wbcDifferentialRobot_Control.right_motor().set_speed(0);
wbhDifferentialRobot_Control.set(wbcDifferentialRobot_Control);

fprintf(stderr,"%s::ePuck Motors, GSM, and LEDs setup for FollowLine\n",machine_name());
