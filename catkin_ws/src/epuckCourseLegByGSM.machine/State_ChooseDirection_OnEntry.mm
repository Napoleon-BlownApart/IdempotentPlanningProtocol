wbcGoal_Control = wbhGoal_Control.get();
gu_simple_whiteboard_descriptor* wbd = get_local_singleton_whiteboard();
uint16_t	newGoalControlCtr = wbd->wb->event_counters[kGOAL_Control_v];

wbcAngle = wbhAngle.get();
wbcCurrentPosition = wbhCurrentPosition.get();
wbcGoal_Status.curPosition().set_x(wbcCurrentPosition.goal().x());
wbcGoal_Status.curPosition().set_y(wbcCurrentPosition.goal().y());
fprintf(stderr,"%s::########################################################\n",machine_name());
std::cout << machine_name() << "::" << state_name() << "::wbcCurrentPosition.goal().x() = " << std::boolalpha << static_cast<int>(wbcCurrentPosition.goal().x()) << '\n';
std::cout << machine_name() << "::" << state_name() << "::wbcCurrentPosition.goal().y() = " << std::boolalpha << static_cast<int>(wbcCurrentPosition.goal().y()) << '\n';
fprintf(stderr,"%s::Obstacle %s\n",machine_name(),((wbcObstacleOnPath.obstacle())?"True":"False"));
fprintf(stderr,"%s::########################################################\n",machine_name());


if (wbcObstacleOnPath.obstacle()) {  // If failed last goal attempt check to see if we have a new goal.
  wbcGoal_Status.state().set_didFail(true);
//  wbcObstacleOnPath.set_obstacle(false);
//  wbhObstacleOnPath.set(wbcObstacleOnPath);

  fprintf(stderr,"%s::#######################    G    O    A    L        F    A    I    L    U    R    E    #################################\n",machine_name());
  if (!(wbcGoal_Status.goal().x() == wbcGoal_Control.goal().x() && wbcGoal_Status.goal().y() == wbcGoal_Control.goal().y()) ||
      (goalControlCtr != newGoalControlCtr)
      ) {
    fprintf(stderr,"%s::#######################    G    O    A    L        F    A    I    L    U    R    E        R    E    S    E    T    #################################\n",machine_name());
    wbcGoal_Status.state().set_didFail(false);  // If we have a new goal, we reset didFail since we haven't attempted it yet.
    wbcGoal_Status.goal().x() = wbcGoal_Control.goal().x();
    wbcGoal_Status.goal().y() = wbcGoal_Control.goal().y();
  }
}

wbcGoal_Status.goal().x() = wbcGoal_Control.goal().x();
wbcGoal_Status.goal().y() = wbcGoal_Control.goal().y();
wbhGoal_Status.set(wbcGoal_Status);

// Failure to achieve a goal means we return to the last intersection, but our orientation is opposite.
// So we don't want to calculate a new direction back to a goal that we've failed to reach before.
// didFail will only be true if we failed in the past and the goal hasn't changed.
if (!wbcGoal_Status.state().didFail()) {
//if (!wbcGoal_Status.state().didFail()) {
  int colDiff = wbcGoal_Control.goal().x()-wbcGoal_Status.curPosition().x();
  int rowDiff = wbcGoal_Control.goal().y()-wbcGoal_Status.curPosition().y();
  int absColDiff = abs(colDiff);
  int absRowDiff = abs(rowDiff);

  if (absColDiff > 1 || absRowDiff > 1 || absColDiff == absRowDiff) {
    // Goal is NOT Manhattan Adjacent or we are already there.
    whichWay = Direction::BACK;
  } else {  // Goal is Manhattan Adjacent to current location.
//    if (!returning) {
      int newAngle = -1;
      if                 (colDiff ==  1 && rowDiff ==  0) newAngle = 90;
      if (newAngle < 0 && colDiff ==  0 && rowDiff == -1) newAngle = 0;
      if (newAngle < 0 && colDiff == -1 && rowDiff ==  0) newAngle = 270;
      if (newAngle < 0 && colDiff ==  0 && rowDiff ==  1) newAngle = 180;

      int turnAngle = (360+newAngle-wbcAngle.angle())%360;  // Add 360 to ensure always positive so modulus function works.
      fprintf(stderr,"%s::########################################################\n",machine_name());
      fprintf(stderr,"%s::Ang = (360 + %d - %d)%%360 = %d\n",machine_name(),newAngle,wbcAngle.angle(), turnAngle);
      fprintf(stderr,"%s::########################################################\n",machine_name());
      switch (turnAngle) {
        case 0:
          whichWay = Direction::STRAIGHT;
          break;
        case 90:
          whichWay = Direction::RIGHT;
          break;
        case 180:
          {
            int choice = (rand() % 2)+1;
            if (choice==1) { whichWay = Direction::AROUNDLEFT; }
            else { whichWay = Direction::AROUNDRIGHT; }
          }
          break;
        case 270:
          whichWay = Direction::LEFT;
          break;
      }
        // Not needed with Subsumption Architecture as epuckOrientationByGSM will figure this out.
//      curPosition.angle = newAngle;
//    }
  }
  wbcDirection_Control.set_direction(whichWay);
}
goalControlCtr = newGoalControlCtr;

invalidGoal = (wbcGoal_Control.goal().x()==0)||(wbcGoal_Control.goal().y()==0);


#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
  fprintf(stderr,"%s::========================================================\n",machine_name());
  fprintf(stderr,"%s::Goal is at (col,row) (%d,%d)\n",machine_name(),wbcGoal_Control.goal().x(),wbcGoal_Control.goal().y());
  fprintf(stderr,"%s::Status is (col,row) (%d,%d) heading %d degrees.\n",machine_name(),wbcGoal_Status.curPosition().x(),wbcGoal_Status.curPosition().y(),wbcAngle.angle());
  std::string dir;
  switch (static_cast<int>(wbcDirection_Control.direction())) {
  case 0:
    dir="Back";
    break;
  case 1:
    dir="Straight";
    break;
  case 2:
    dir="Right";
    break;
  case 3:
    dir="Straight/Right";
    break;
  case 4:
    dir="Left";
    break;
  case 5:
    dir="Straight/Left";
    break;
  case 6:
    dir="Left/Right";
    break;
  case 7:
    dir="Straight/Left/Right";
    break;
  case 8:
    dir="AROUNDRIGHT";
    break;
  case 16:
    dir="AROUNDLEFT";
    break;
  }
  fprintf(stderr,"%s::========================================================\n",machine_name());
  fprintf(stderr,"%s::Direction = %s\n",machine_name(),dir.c_str());
#endif
