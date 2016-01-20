wbcIntersection_Status = wbhIntersection_Status.get();
wbcObstacleOnPath = wbhObstacleOnPath.get();
wbcDirection_Control = wbhDirection_Control.get();

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
  fprintf(stderr,"%s::========================================================\n",machine_name());
  fprintf(stderr,"%s::Direction = %s\n",machine_name(),dir.c_str());
  if (wbcIntersection_Status.scanComplete()) {
    fprintf(stderr,"%s::SCAN COMPLETE\n",machine_name());
  } else {
    fprintf(stderr,"%s::NOT COMPLETE\n",machine_name());
  }
  fprintf(stderr,"%s::Obstacle %s\n",machine_name(),((wbcObstacleOnPath.obstacle())?"True":"False"));
  fprintf(stderr,"%s::Last Direction %d\n",machine_name(),wbcDirection_Control.direction());
  fprintf(stderr,"%s::========================================================\n",machine_name());

#endif
