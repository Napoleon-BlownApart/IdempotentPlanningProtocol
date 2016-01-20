encStateB4Maneuver.encoder[0] = wbcDifferentialRobot_Status.left_motor().odo();
encStateB4Maneuver.encoder[1] = wbcDifferentialRobot_Status.right_motor().odo();

gsLeftPathTrigger = 0;
gsRightPathTrigger = 0;
gsLeftIntersectionTrigger = 0;
gsRightIntersectionTrigger = 0;
possibleDirections = UNDECIDED;
if (!returning) {
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
returning = false;
#ifdef DEBUG
  printf("Entering_Intersection:OnEntry Done\n");
#endif
