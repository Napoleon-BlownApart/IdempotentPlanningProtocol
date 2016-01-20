wbcDirection_Control = wbhDirection_Control.get();
targetEncoderDelta = RIGHT_ANGLE_TURN;

notTurning    = wbcDirection_Control.direction()==Direction::BACK;
turningLeft   = wbcDirection_Control.direction()==Direction::LEFT;
turningRight  = wbcDirection_Control.direction()==Direction::RIGHT;
turningAround = wbcDirection_Control.direction()==Direction::AROUNDRIGHT||wbcDirection_Control.direction()==Direction::AROUNDLEFT;
goingStraight = wbcDirection_Control.direction()==Direction::STRAIGHT;

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
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
  printf("%s::========================================================\n",machine_name());
  fprintf(stderr,"%s::Direction = %s\n",machine_name(),dir.c_str());
  printf("%s::========================================================\n",machine_name());
#endif
