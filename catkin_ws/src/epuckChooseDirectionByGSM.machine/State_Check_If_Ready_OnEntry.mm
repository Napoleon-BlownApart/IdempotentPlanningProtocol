wbcIntersection_Status = wbhIntersection_Status.get();

scanCompleted          = wbcIntersection_Status.scanComplete();
scanCompletedNoOptions = (wbcIntersection_Status.scanComplete())&&(wbcIntersection_Status.directions().direction()==Direction::BACK);


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
  if (wbcIntersection_Status.scanComplete()) {
    fprintf(stderr,"%s::SCAN COMPLETE\n",machine_name());
  } else {
    fprintf(stderr,"%s::NOT COMPLETE\n",machine_name());
  }
  printf("%s::========================================================\n",machine_name());

#endif
