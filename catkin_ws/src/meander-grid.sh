#!/bin/bash
echo "Run the machines necessary to achieve the 'Meander Grid' behaviour level"
#
/home/nap/Documents/thesis/webots/catkin_ws/devel/lib/clfsm/clfsm \
  epuckFollowLineByGSM.machine/ \
  epuckIntersectionByGSM.machine/ \
  epuckChooseDirectionByGSM.machine/ \
  epuckTurnByGSM.machine/ \
  epuckTurnAwayByGSM.machine/
