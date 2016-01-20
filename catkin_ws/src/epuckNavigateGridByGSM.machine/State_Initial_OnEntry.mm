wbcEPuckGSM_Control.set_gs(0,1);
wbcEPuckGSM_Control.set_gs(1,1);
wbcEPuckGSM_Control.set_gs(2,1);
wbhEPuckGSM_Control.set(wbcEPuckGSM_Control);

wbcEPuckProximity_Control.set_ps(0,1);
wbcEPuckProximity_Control.set_ps(7,1);
wbhEPuckProximity_Control.set(wbcEPuckProximity_Control);

wbcDifferentialRobot_Control.left_motor().set_motorOn(true);
wbcDifferentialRobot_Control.right_motor().set_motorOn(true);
wbcDifferentialRobot_Control.left_motor().set_encoderOn(true);
wbcDifferentialRobot_Control.right_motor().set_encoderOn(true);
wbcDifferentialRobot_Control.left_motor().set_speed(0);
wbcDifferentialRobot_Control.right_motor().set_speed(0);

wbcEPuckLED_Control.led(0).set_enabled(true);	// Ring
wbcEPuckLED_Control.led(0).set_value(1);
wbcEPuckLED_Control.led(4).set_enabled(true);	// Tail lights
wbcEPuckLED_Control.led(4).set_value(1);
wbcEPuckLED_Control.led(8).set_enabled(true);	// Body
wbcEPuckLED_Control.led(8).set_value(1);
wbcEPuckLED_Control.led(9).set_enabled(true);	// Next to Camera
wbcEPuckLED_Control.led(9).set_value(1);
wbhEPuckLED_Control.set(wbcEPuckLED_Control);

wbcGoal_Control = wbhGoal_Control.get();
/***
  * IMPROVEMENT (TODO)
  *
  * READ GOAL_Status from the Whiteboard
  * If curPosition.x = 0 & curPosition.y = 0
  * Then
  *   Set to manual initial conditions (3,6)
  * Else
  *   The Whiteboard has a record of where we last were,
  *   so we use the values retrieved.
  *
  *
  * THIS CAN BE DONE FOR THE SENSORS AS WELL.
  *
  */
wbcGoal_Status.goal().set_x(wbcGoal_Control.goal().x());
wbcGoal_Status.goal().set_y(wbcGoal_Control.goal().y());
wbcGoal_Status.curPosition().set_x(3);
wbcGoal_Status.curPosition().set_y(6);
wbcGoal_Status.state().set_didFail(false);
wbhGoal_Status.set(wbcGoal_Status);

//curPosition = {3,6,0};	// Column, Row, Angle
curPosition.x = 3;	// Column
curPosition.y =6;	// Row
curPosition.angle = 0;	// Angle

srand(1);
#ifdef DEBUG
  printf("Initial:OnEntry Done\n");
#endif
