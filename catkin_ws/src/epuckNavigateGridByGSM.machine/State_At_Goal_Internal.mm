wbcGoal_Control = wbhGoal_Control.get();
#ifdef DEBUG
  printf("At_Goal:Internal Done\n");
  if (curPosition.x == wbcGoal_Control.goal().x() && curPosition.y == wbcGoal_Control.goal().y()) {
    printf("I am at the GOAL\n");
  }
#endif
