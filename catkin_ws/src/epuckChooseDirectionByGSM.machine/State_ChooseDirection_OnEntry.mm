int numChoices = 0;
if (wbcIntersection_Status.directions().direction() & Direction::STRAIGHT) numChoices++;
if (wbcIntersection_Status.directions().direction() & Direction::RIGHT) numChoices++;
if (wbcIntersection_Status.directions().direction() & Direction::LEFT) numChoices++;

int theChoice ;

// Only one possible way to go, so return immediately.
if (numChoices == 1) {
 wbcDirection_Control.set_direction(wbcIntersection_Status.directions().direction());
} else {
  // Otherwise pick a direction
  int choice = (rand() % numChoices)+1;
//  std::default_random_engine generator;
//  std::uniform_int_distribution<int> distribution(1,numChoices);
//  int choice = distribution(generator);
  theChoice = choice;
  if ((wbcIntersection_Status.directions().direction() & Direction::STRAIGHT) && (choice-- == 1)) {
    wbcDirection_Control.set_direction(Direction::STRAIGHT);
  } else if ((wbcIntersection_Status.directions().direction() & Direction::RIGHT) && (choice-- == 1)) {
    wbcDirection_Control.set_direction(Direction::RIGHT);
//    curPosition.angle = (curPosition.angle+90)%360;
  } else {
    wbcDirection_Control.set_direction(Direction::LEFT);
//    curPosition.angle = (curPosition.angle != 0) ? curPosition.angle-90 : 270;
  }
}
wbcIntersection_Status.directions().set_direction(Direction::BACK);
wbcIntersection_Status.set_scanComplete(false);
wbhIntersection_Status.set(wbcIntersection_Status);

wbhDirection_Control.set(wbcDirection_Control);

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
  fprintf(stderr,"%s::Num Choices/Choice = %d/%d\n",machine_name(),numChoices,theChoice);
  fprintf(stderr,"%s::Direction = %s\n",machine_name(),dir.c_str());
  printf("%s::========================================================\n",machine_name());

//  printf("Direction = %d\n",static_cast<int>(whichWay));
#endif
