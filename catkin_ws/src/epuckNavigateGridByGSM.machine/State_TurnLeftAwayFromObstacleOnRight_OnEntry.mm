curPosition.angle = (curPosition.angle + 180) % 360; // Adding 180 is the same as subtracting 180 but the modulus function handles additions easier, so we add.
returning = true;
encStateB4Maneuver.encoder[0] = wbcDifferentialRobot_Status.left_motor().odo();
encStateB4Maneuver.encoder[1] = wbcDifferentialRobot_Status.right_motor().odo();
whichWay = LEFT;
wbcGoal_Status.state().set_didFail(true);
wbhGoal_Status.set(wbcGoal_Status);
// SEND Message for replay.  Current Position plus direction.
#ifdef DEBUG
  printf("TurnLeftAwayFromObstacleOnRight:OnEntry Done\n");
#endif
