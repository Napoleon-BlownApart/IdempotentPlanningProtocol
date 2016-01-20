wbcGoal_Control = wbhGoal_Control.get();
#ifdef DEBUG
  if (curPosition.x == wbcGoal_Control.goal().x() && curPosition.y == wbcGoal_Control.goal().y()) {
    printf("I am at the GOAL\n");
    }
  if (wbcGoal_Control.goal().x()==0 && wbcGoal_Control.goal().y()==0) {
    printf("THERE IS NO GOAL\n");
    }
#endif
