//wbcGoal_Status = wbhGoal_Status.get();
//wbcIntersection_Status.set_intersectionCoord(wbcGoal_Status.curPosition());
// Directions available are already know.  Comment here to indicate this.
//wbcIntersection_Status.set_directions(wbcIntersection_Status.set_directions());
wbcIntersection_Status.set_scanComplete(true);
wbhIntersection_Status.set(wbcIntersection_Status);


//suspend_self();

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
  std::string dir;
  switch (static_cast<int>(wbcIntersection_Status.directions().direction())) {
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
  printf("%s::========================================================\n",machine_name());
  fprintf(stderr,"%s::Direction = %s\n",machine_name(),dir.c_str());
  printf("%s::========================================================\n",machine_name());
#endif
