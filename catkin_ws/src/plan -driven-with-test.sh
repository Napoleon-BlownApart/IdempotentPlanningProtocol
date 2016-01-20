#!/bin/bash
echo "Run the machines necessary to allow simulation of Plan Manager crashes."
#
/home/nap/Documents/thesis/webots/catkin_ws/devel/lib/clfsm/clfsm \
  epuckTesterByGSM.machine/ \
  epuckFollowLineByGSM.machine/ \
  epuckIntersectionByGSM.machine/ \
  epuckChooseDirectionByGSM.machine/ \
  epuckTurnByGSM.machine/ \
  epuckTurnAwayByGSM.machine/ \
  epuckObstacleOnPathByGSM.machine/ \
  epuckOrientationByGSM.machine/ \
  epuckCoordinatesByGSM.machine/ \
  epuckCourseLegByGSM.machine/ \
  epuckPlanManagerByGSM.machine

