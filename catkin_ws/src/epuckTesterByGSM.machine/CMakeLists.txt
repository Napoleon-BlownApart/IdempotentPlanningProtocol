cmake_minimum_required(VERSION 2.8.3)
project(epucktesterbygsm)
## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS clfsm gusimplewhiteboard)
###################################
## catkin specific configuration ##
###################################
catkin_package( LIBRARIES libepuckTesterByGSM )
###########
## Build ##
###########
set(CMAKE_CXX_FLAGS "-std=c++11 -DWHITEBOARD_POSTER_STRING_CONVERSION=1")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")
include_directories(include)
include_directories(${clfsm_INCLUDE_DIRS})
link_directories(${CATKIN_DEVEL_PREFIX}/lib)
## Declare a cpp library
add_library(epuckTesterByGSM_State_InitialPseudoState OBJECT State_InitialPseudoState.mm )
add_library(epuckTesterByGSM_State_Initial OBJECT State_Initial.mm )
add_library(epuckTesterByGSM_State_observe OBJECT State_observe.mm )
add_library(epuckTesterByGSM_State_epuckFollowsLine OBJECT State_epuckFollowsLine.mm )
add_library(epuckTesterByGSM_State_epuckFollowsLine_Suspend OBJECT State_epuckFollowsLine_Suspend.mm )
add_library(epuckTesterByGSM_State_epuckFollowsLine_Resume OBJECT State_epuckFollowsLine_Resume.mm )
add_library(epuckTesterByGSM_State_epuckIntersection OBJECT State_epuckIntersection.mm )
add_library(epuckTesterByGSM_State_epuckIntersection_Suspend OBJECT State_epuckIntersection_Suspend.mm )
add_library(epuckTesterByGSM_State_epuckIntersection_Resume OBJECT State_epuckIntersection_Resume.mm )
add_library(epuckTesterByGSM_State_epuckTurnAway OBJECT State_epuckTurnAway.mm )
add_library(epuckTesterByGSM_State_epuckTurnAway_Suspend OBJECT State_epuckTurnAway_Suspend.mm )
add_library(epuckTesterByGSM_State_epuckTurnAway_Resume OBJECT State_epuckTurnAway_Resume.mm )
add_library(epuckTesterByGSM_State_epuckChooseDirection OBJECT State_epuckChooseDirection.mm )
add_library(epuckTesterByGSM_State_epuckChooseDirection_Suspend OBJECT State_epuckChooseDirection_Suspend.mm )
add_library(epuckTesterByGSM_State_epuckChooseDirection_Resume OBJECT State_epuckChooseDirection_Resume.mm )
add_library(epuckTesterByGSM_State_epuckTurn OBJECT State_epuckTurn.mm )
add_library(epuckTesterByGSM_State_epuckTurn_Suspend OBJECT State_epuckTurn_Suspend.mm )
add_library(epuckTesterByGSM_State_epuckTurn_Resume OBJECT State_epuckTurn_Resume.mm )
add_library(epuckTesterByGSM_State_epuckOrientation OBJECT State_epuckOrientation.mm )
add_library(epuckTesterByGSM_State_epuckOrientation_Suspend OBJECT State_epuckOrientation_Suspend.mm )
add_library(epuckTesterByGSM_State_epuckOrientation_Resume OBJECT State_epuckOrientation_Resume.mm )
add_library(epuckTesterByGSM_State_epuckObstacleOnPath OBJECT State_epuckObstacleOnPath.mm )
add_library(epuckTesterByGSM_State_epuckObstacleOnPath_Suspend OBJECT State_epuckObstacleOnPath_Suspend.mm )
add_library(epuckTesterByGSM_State_epuckObstacleOnPath_Resume OBJECT State_epuckObstacleOnPath_Resume.mm )
add_library(epuckTesterByGSM_State_epuckCoordinates OBJECT State_epuckCoordinates.mm )
add_library(epuckTesterByGSM_State_epuckCoordinates_Suspend OBJECT State_epuckCoordinates_Suspend.mm )
add_library(epuckTesterByGSM_State_epuckCoordinates_Resume OBJECT State_epuckCoordinates_Resume.mm )
add_library(epuckTesterByGSM_State_epuckCourseLeg OBJECT State_epuckCourseLeg.mm )
add_library(epuckTesterByGSM_State_epuckCourseLeg_Suspend OBJECT State_epuckCourseLeg_Suspend.mm )
add_library(epuckTesterByGSM_State_epuckCourseLeg_Resume OBJECT State_epuckCourseLeg_Resume.mm )
add_library(epuckTesterByGSM_State_epuckPlanManager OBJECT State_epuckPlanManager.mm )
add_library(epuckTesterByGSM_State_epuckPlanManager_Suspend OBJECT State_epuckPlanManager_Suspend.mm )
add_library(epuckTesterByGSM_State_epuckPlanManager_Resume OBJECT State_epuckPlanManager_Resume.mm )
add_library(epuckTesterByGSM_State_loop_Back OBJECT State_loop_Back.mm )
add_library(epuckTesterByGSM OBJECT epuckTesterByGSM.mm )
add_library(libepuckTesterByGSM
$<TARGET_OBJECTS:epuckTesterByGSM_State_InitialPseudoState>
$<TARGET_OBJECTS:epuckTesterByGSM_State_Initial>
$<TARGET_OBJECTS:epuckTesterByGSM_State_observe>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckFollowsLine>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckFollowsLine_Suspend>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckFollowsLine_Resume>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckIntersection>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckIntersection_Suspend>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckIntersection_Resume>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckTurnAway>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckTurnAway_Suspend>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckTurnAway_Resume>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckChooseDirection>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckChooseDirection_Suspend>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckChooseDirection_Resume>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckTurn>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckTurn_Suspend>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckTurn_Resume>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckOrientation>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckOrientation_Suspend>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckOrientation_Resume>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckObstacleOnPath>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckObstacleOnPath_Suspend>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckObstacleOnPath_Resume>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckCoordinates>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckCoordinates_Suspend>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckCoordinates_Resume>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckCourseLeg>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckCourseLeg_Suspend>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckCourseLeg_Resume>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckPlanManager>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckPlanManager_Suspend>
$<TARGET_OBJECTS:epuckTesterByGSM_State_epuckPlanManager_Resume>
$<TARGET_OBJECTS:epuckTesterByGSM_State_loop_Back>
$<TARGET_OBJECTS:epuckTesterByGSM>)
set_target_properties(libepuckTesterByGSM  PROPERTIES OUTPUT_NAME epuckTesterByGSM)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set_target_properties(epuckTesterByGSM_State_InitialPseudoState PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_Initial PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_observe PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckFollowsLine PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckFollowsLine_Suspend PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckFollowsLine_Resume PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckIntersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckIntersection_Suspend PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckIntersection_Resume PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckTurnAway PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckTurnAway_Suspend PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckTurnAway_Resume PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckChooseDirection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckChooseDirection_Suspend PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckChooseDirection_Resume PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckTurn PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckTurn_Suspend PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckTurn_Resume PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckOrientation PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckOrientation_Suspend PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckOrientation_Resume PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckObstacleOnPath PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckObstacleOnPath_Suspend PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckObstacleOnPath_Resume PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckCoordinates PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckCoordinates_Suspend PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckCoordinates_Resume PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckCourseLeg PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckCourseLeg_Suspend PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckCourseLeg_Resume PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckPlanManager PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckPlanManager_Suspend PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_epuckPlanManager_Resume PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM_State_loop_Back PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTesterByGSM PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
## Specify libraries to link a library or executable target against
target_link_libraries(libepuckTesterByGSM ${catkin_LIBRARIES})
