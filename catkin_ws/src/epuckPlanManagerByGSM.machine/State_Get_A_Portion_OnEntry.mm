#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif

for (int i=0; i < GOAL_ENVELOPE_SIZE; i++) {
    fprintf(stderr,"%s::Loop %d\n",machine_name(),i);
    if ((wbcGoal_List.subGoal(i).x() == 0) &&
        (wbcGoal_List.subGoal(i).y() == 0)) {
      break;
    }
    planElements++;
    guWhiteboard::GOAL_Control aSubGoal;
    aSubGoal.goal() = wbcGoal_List.subGoal(i);
    fprintf(stderr,"%s::Assign %d\n",machine_name(),i);
    std::cout << machine_name() << "::" << state_name() << "::Entry " << i << " = " << std::boolalpha << aSubGoal.description() << '\n';

    pathList.push_back(aSubGoal);
    fprintf(stderr,"%s::Increment %d\n",machine_name(),i);
}
fprintf(stderr,"%s::Completed Loop\n",machine_name());
Plan_Goal_List wbcTmpGoal_List;
wbcTmpGoal_List.set_startoff(planElements);
wbhGoal_List.set(wbcTmpGoal_List);
fprintf(stderr,"%s::Request next portion %d\n",machine_name(), planElements);
