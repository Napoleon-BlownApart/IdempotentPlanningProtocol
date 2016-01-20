#!/bin/bash
##
##  Re-initialise the simulation's generated files so that a clean run follows.
##
rm -f 'path/to/planner'/Plan*    # where the plan library is kept
rm -f 'path/to/catkin_workspace_parent'/catkin_ws/src/current_obstacles.txt # where the list of current obstacles are stored
rm -f /tmp/guWhiteboard # remove the file which references the shared memory for a clean run
