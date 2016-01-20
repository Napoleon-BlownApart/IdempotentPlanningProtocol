wbcDifferentialRobot_Control.left_motor().set_speed(TURN_FACTOR*MAX_SPEED);  // Since we are on the verge of an intersection, no point going full speed into it.
wbcDifferentialRobot_Control.right_motor().set_speed(TURN_FACTOR*MAX_SPEED);
wbhDifferentialRobot_Control.set(wbcDifferentialRobot_Control);
