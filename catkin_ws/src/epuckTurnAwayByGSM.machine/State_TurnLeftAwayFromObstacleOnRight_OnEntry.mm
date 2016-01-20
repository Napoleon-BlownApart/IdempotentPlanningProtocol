suspend("epuckFollowLineByGSM");
//POST MESSAGE WITH DIRECTION = LEFT
wbcDirection_Control.set_direction(Direction::AROUNDLEFT);
wbhDirection_Control.set(wbcDirection_Control);

wbcGoal_Status = wbhGoal_Status.get();
wbcGoal_Status.state().set_didFail(true);
wbhGoal_Status.set(wbcGoal_Status);

//#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
//  fprintf(stderr,"%s::Obstacle on Right\n",machine_name());
//#endif
