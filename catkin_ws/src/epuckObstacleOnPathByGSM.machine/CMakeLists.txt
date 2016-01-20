cmake_minimum_required(VERSION 2.8.3)
project(epuckobstacleonpathbygsm)
## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS clfsm gusimplewhiteboard)
###################################
## catkin specific configuration ##
###################################
catkin_package( LIBRARIES libepuckObstacleOnPathByGSM )
###########
## Build ##
###########
set(CMAKE_CXX_FLAGS "-std=c++11 -DWHITEBOARD_POSTER_STRING_CONVERSION=1")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")
include_directories(include)
include_directories(${clfsm_INCLUDE_DIRS})
link_directories(${CATKIN_DEVEL_PREFIX}/lib)
## Declare a cpp library
add_library(epuckObstacleOnPathByGSM_State_InitialPseudoState OBJECT State_InitialPseudoState.mm )
add_library(epuckObstacleOnPathByGSM_State_Initial OBJECT State_Initial.mm )
add_library(epuckObstacleOnPathByGSM_State_Have_Obstacle OBJECT State_Have_Obstacle.mm )
add_library(epuckObstacleOnPathByGSM_State_Observe_Obstacle OBJECT State_Observe_Obstacle.mm )
add_library(epuckObstacleOnPathByGSM_State_SUSPENDED OBJECT State_SUSPENDED.mm )
add_library(epuckObstacleOnPathByGSM_State_Observe_Intersection OBJECT State_Observe_Intersection.mm )
add_library(epuckObstacleOnPathByGSM_State_Entering_Intersection OBJECT State_Entering_Intersection.mm )
add_library(epuckObstacleOnPathByGSM_State_Detected_Intersection OBJECT State_Detected_Intersection.mm )
add_library(epuckObstacleOnPathByGSM_State_Not_Detected_Intersection OBJECT State_Not_Detected_Intersection.mm )
add_library(epuckObstacleOnPathByGSM OBJECT epuckObstacleOnPathByGSM.mm )
add_library(libepuckObstacleOnPathByGSM
$<TARGET_OBJECTS:epuckObstacleOnPathByGSM_State_InitialPseudoState>
$<TARGET_OBJECTS:epuckObstacleOnPathByGSM_State_Initial>
$<TARGET_OBJECTS:epuckObstacleOnPathByGSM_State_Have_Obstacle>
$<TARGET_OBJECTS:epuckObstacleOnPathByGSM_State_Observe_Obstacle>
$<TARGET_OBJECTS:epuckObstacleOnPathByGSM_State_SUSPENDED>
$<TARGET_OBJECTS:epuckObstacleOnPathByGSM_State_Observe_Intersection>
$<TARGET_OBJECTS:epuckObstacleOnPathByGSM_State_Entering_Intersection>
$<TARGET_OBJECTS:epuckObstacleOnPathByGSM_State_Detected_Intersection>
$<TARGET_OBJECTS:epuckObstacleOnPathByGSM_State_Not_Detected_Intersection>
$<TARGET_OBJECTS:epuckObstacleOnPathByGSM>)
set_target_properties(libepuckObstacleOnPathByGSM  PROPERTIES OUTPUT_NAME epuckObstacleOnPathByGSM)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set_target_properties(epuckObstacleOnPathByGSM_State_InitialPseudoState PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckObstacleOnPathByGSM_State_Initial PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckObstacleOnPathByGSM_State_Have_Obstacle PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckObstacleOnPathByGSM_State_Observe_Obstacle PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckObstacleOnPathByGSM_State_SUSPENDED PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckObstacleOnPathByGSM_State_Observe_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckObstacleOnPathByGSM_State_Entering_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckObstacleOnPathByGSM_State_Detected_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckObstacleOnPathByGSM_State_Not_Detected_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckObstacleOnPathByGSM PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
## Specify libraries to link a library or executable target against
target_link_libraries(libepuckObstacleOnPathByGSM ${catkin_LIBRARIES})
