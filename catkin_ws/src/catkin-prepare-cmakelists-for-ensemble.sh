#!/bin/bash
##
##  Use the machine_catkin_setup.sh script to create the CMakeLists.txt files
##  for each of the machines.
##  Then move the generated files into the respective machine's folder.
##
./machine_catkin_setup.sh epuckFollowLineByGSM.machine
./machine_catkin_setup.sh epuckIntersectionByGSM.machine
./machine_catkin_setup.sh epuckChooseDirectionByGSM.machine
./machine_catkin_setup.sh epuckTurnAwayByGSM.machine
./machine_catkin_setup.sh epuckTurnByGSM.machine
#
./machine_catkin_setup.sh epuckCoordinatesByGSM.machine
./machine_catkin_setup.sh epuckObstacleOnPathByGSM.machine
./machine_catkin_setup.sh epuckOrientationByGSM.machine
#
./machine_catkin_setup.sh epuckCourseLegByGSM.machine
#
./machine_catkin_setup.sh epuckPlanManagerByGSM.machine
#
mv CMakeLists_epuckFollowLineByGSM.txt ./epuckFollowLineByGSM.machine/CMakeLists.txt
mv CMakeLists_epuckIntersectionByGSM.txt ./epuckIntersectionByGSM.machine/CMakeLists.txt
mv CMakeLists_epuckChooseDirectionByGSM.txt ./epuckChooseDirectionByGSM.machine/CMakeLists.txt
mv CMakeLists_epuckTurnAwayByGSM.txt ./epuckTurnAwayByGSM.machine/CMakeLists.txt
mv CMakeLists_epuckTurnByGSM.txt ./epuckTurnByGSM.machine/CMakeLists.txt
#
mv CMakeLists_epuckCoordinatesByGSM.txt ./epuckCoordinatesByGSM.machine/CMakeLists.txt
mv CMakeLists_epuckObstacleOnPathByGSM.txt ./epuckObstacleOnPathByGSM.machine/CMakeLists.txt
mv CMakeLists_epuckOrientationByGSM.txt ./epuckOrientationByGSM.machine/CMakeLists.txt
#
mv CMakeLists_epuckCourseLegByGSM.txt ./epuckCourseLegByGSM.machine/CMakeLists.txt
#
mv CMakeLists_epuckPlanManagerByGSM.txt ./epuckPlanManagerByGSM.machine/CMakeLists.txt

