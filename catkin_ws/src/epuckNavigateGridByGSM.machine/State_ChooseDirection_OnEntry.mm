wbcGoal_Control = wbhGoal_Control.get();
if (wbcGoal_Status.state().didFail()) {  // If failed last goal attempt check to see if we have a new goal.
  printf("#######################    G    O    A    L        F    A    I    L    U    R    E    #################################\n");
  if (!(wbcGoal_Status.goal().x() == wbcGoal_Control.goal().x() && wbcGoal_Status.goal().y() == wbcGoal_Control.goal().y())) {
    printf("#######################    G    O    A    L        F    A    I    L    U    R    E        R    E    S    E    T    #################################\n");
    wbcGoal_Status.state().set_didFail(false);  // If we have a new goal, we reset didFail since we haven't attempted it yet.
    wbcGoal_Status.goal().x() = wbcGoal_Control.goal().x();
    wbcGoal_Status.goal().y() = wbcGoal_Control.goal().y();
  }
}
wbcGoal_Status.goal().x() = wbcGoal_Control.goal().x();
wbcGoal_Status.goal().y() = wbcGoal_Control.goal().y();

// Failure to achieve a goal means we return to the last intersection, but our orientation is opposite.
// So we don't want to calculate a new direction back to a goal that we've failed to reach before.
// didFail will only be true if we failed in the past and the goal hasn't changed.
if (!wbcGoal_Status.state().didFail()) {
  int colDiff = wbcGoal_Control.goal().x()-wbcGoal_Status.curPosition().x();
  int rowDiff = wbcGoal_Control.goal().y()-wbcGoal_Status.curPosition().y();
  int absColDiff = abs(colDiff);
  int absRowDiff = abs(rowDiff);

  if (absColDiff > 1 || absRowDiff > 1 || absColDiff == absRowDiff) {
    // Goal is NOT Manhattan Adjacent or we are already there.
    whichWay = UNDECIDED;
  } else { // Goal is Manhattan Adjacent to current location.
//    if (!returning) {
      int newAngle = -1;
      if                 (colDiff ==  1 && rowDiff ==  0) newAngle = 90;
      if (newAngle < 0 && colDiff ==  0 && rowDiff == -1) newAngle = 0;
      if (newAngle < 0 && colDiff == -1 && rowDiff ==  0) newAngle = 270;
      if (newAngle < 0 && colDiff ==  0 && rowDiff ==  1) newAngle = 180;

      int turnAngle = (360+newAngle-curPosition.angle)%360;  // Add 360 to ensure always positive so modulus function works.
      printf("########################################################\n");
      printf("Ang = (360 + %d - %d)%%360 = %d\n", newAngle,curPosition.angle, turnAngle);
      printf("########################################################\n");
      switch (turnAngle) {
        case 0:
          whichWay = STRAIGHT;
          break;
        case 90:
          whichWay = RIGHT;
          break;
        case 180:
          whichWay = AROUND;
          break;
        case 270:
          whichWay = LEFT;
          break;
      }
      curPosition.angle = newAngle;
//    }
  }
} else {
}
gsLeftPathTrigger = 0;
gsCenterPathTrigger = 0;
gsRightPathTrigger = 0;
gsLeftIntersectionTrigger = 0;
gsCenterIntersectionTrigger = 0;
gsRightIntersectionTrigger = 0;

  printf("Goal is at (col,row) (%d,%d)\n", wbcGoal_Control.goal().x(),wbcGoal_Control.goal().y());
  printf("Status is (col,row) (%d,%d)\n", wbcGoal_Status.curPosition().x(),wbcGoal_Status.curPosition().y());

#ifdef DEBUG
  printf("ChooseDirection:OnEntry Done\n");
  printf("Directions Available = %d\n",static_cast<int>(possibleDirections));
  printf("Direction Chosen = %d\n",static_cast<int>(whichWay));
  printf("I am at Position (col,row) (%d,%d) heading %d degrees.\n", curPosition.x,curPosition.y,curPosition.angle);
#endif
