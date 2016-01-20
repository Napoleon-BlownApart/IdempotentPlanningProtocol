curPosition.angle = (curPosition.angle + 180) % 360;
returning = true;
encStateB4Maneuver.encoder[0] = wbcDifferentialRobot_Status.left_motor().odo();
encStateB4Maneuver.encoder[1] = wbcDifferentialRobot_Status.right_motor().odo();
whichWay = RIGHT;

// SEND Message for replay.  Current Position plus direction.
#ifdef DEBUG
  printf("TurnRightAwayFromObstacleOnLeft:OnEntry Done\n");
#endif
