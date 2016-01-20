wbcDomain_Filename.set_filename("/home/nap/Documents/thesis/planning/dev/planner/domain-3dmaze.pddl");
wbhDomain_Filename.set(wbcDomain_Filename);
wbcProblem_Filename.set_filename("/home/nap/Documents/thesis/planning/dev/planner/problem-epuck_full.pddl");
wbhProblem_Filename.set(wbcProblem_Filename);
wbcObstacles_Filename.set_filename("/home/nap/Documents/thesis/webots/catkin_ws/src/current_obstacles.txt");
wbhObstacles_Filename.set(wbcObstacles_Filename);


/** Planner settings
  *
  * These are passed as parameters to the appropriate search
  * engines in the Planner module as required.
  *
  * They are not made use of in this example, and are set here
  * as an indicatior of how to use them.
  *
  * refer to the wb_plan_planner_settings.h files in /typeClassDefs.
  */
wbcPlanner_Settings.set_max_novelty(2);
wbcPlanner_Settings.set_cost(0.0f);
wbcPlanner_Settings.set_bound(0.0f);
wbcPlanner_Settings.set_budget(0.0f);
wbcPlanner_Settings.set_heuristic(1);
/**
  * These are used by the BFS_HMAX algorigthm and are set false here.
  *
  */
wbcPlanner_Settings.set_anytime(false);
wbcPlanner_Settings.set_delayed(false);
wbcPlanner_Settings.set_greedy(false);

/** Search Engine selection.
  *
  * We will use the 'BFS_HMAX' algorithm in this example.
  *
  * Currently the following are defined:
  *   "BFS_HMAX"
  *   "BRFS"
  *   "DAS"
  *
  * Refer to the planner module comments for valid alternatives.
  *
  */
wbcPlanner_Settings.set_engine("BFS_HMAX");
wbhPlanner_Settings.set(wbcPlanner_Settings);

planIsNew = false;  // For some reason, when restarted, this can be true, though nothing sets it to true until later (Receive_New_Plan_OnEntry)
//wbcManager_Status.set_plan(false);
//wbhManager_Status.set(wbcManager_Status);

#ifdef DEBUG
  fprintf(stderr,"%s::%s:OnEntry Done\n",machine_name(),state_name());
#endif
