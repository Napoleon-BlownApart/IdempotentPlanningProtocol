encStateB4Maneuver.encoder[0] = wbcDifferentialRobot_Status.left_motor().odo();
encStateB4Maneuver.encoder[1] = wbcDifferentialRobot_Status.right_motor().odo();
//wbcGoal_Control = wbhGoal_Control.get();

gsLeftPathTrigger = 0;
gsRightPathTrigger = 0;
gsLeftIntersectionTrigger = 0;
gsRightIntersectionTrigger = 0;
possibleDirections = UNDECIDED;
if (!wbcGoal_Status.state().didFail()) {
  switch(curPosition.angle) {
    case 0:
      curPosition.y--;
      break;
    case 90:
      curPosition.x++;
      break;
    case 180:
      curPosition.y++;
      break;
    case 270:
      curPosition.x--;
      break;
  }
}
//wbcGoal_Status.goal().set_x(wbcGoal_Control.goal().x());
//wbcGoal_Status.goal().set_y(wbcGoal_Control.goal().y());
wbcGoal_Status.curPosition().set_x(curPosition.x);
wbcGoal_Status.curPosition().set_y(curPosition.y);
wbhGoal_Status.set(wbcGoal_Status);

  printf("Entering Intersection at Position (col,row) (%d,%d) heading %d degrees.\n", curPosition.x,curPosition.y,curPosition.angle);

#ifdef DEBUG
  fprintf(stderr,"%s:OnEntry Done\n",state_name());

#endif
