cmake_minimum_required(VERSION 2.8.3)
project(epuckturnawaybygsm)
## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS clfsm gusimplewhiteboard)
###################################
## catkin specific configuration ##
###################################
catkin_package( LIBRARIES libepuckTurnAwayByGSM )
###########
## Build ##
###########
set(CMAKE_CXX_FLAGS "-std=c++11 -DWHITEBOARD_POSTER_STRING_CONVERSION=1")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")
include_directories(include)
include_directories(${clfsm_INCLUDE_DIRS})
link_directories(${CATKIN_DEVEL_PREFIX}/lib)
## Declare a cpp library
add_library(epuckTurnAwayByGSM_State_InitialPseudoState OBJECT State_InitialPseudoState.mm )
add_library(epuckTurnAwayByGSM_State_Initial OBJECT State_Initial.mm )
add_library(epuckTurnAwayByGSM_State_TurnLeftAwayFromObstacleOnRight OBJECT State_TurnLeftAwayFromObstacleOnRight.mm )
add_library(epuckTurnAwayByGSM_State_TurnRightAwayFromObstacleOnLeft OBJECT State_TurnRightAwayFromObstacleOnLeft.mm )
add_library(epuckTurnAwayByGSM_State_Observe OBJECT State_Observe.mm )
add_library(epuckTurnAwayByGSM_State_No_Obstacles OBJECT State_No_Obstacles.mm )
add_library(epuckTurnAwayByGSM_State_SUSPENDED OBJECT State_SUSPENDED.mm )
add_library(epuckTurnAwayByGSM OBJECT epuckTurnAwayByGSM.mm )
add_library(libepuckTurnAwayByGSM
$<TARGET_OBJECTS:epuckTurnAwayByGSM_State_InitialPseudoState>
$<TARGET_OBJECTS:epuckTurnAwayByGSM_State_Initial>
$<TARGET_OBJECTS:epuckTurnAwayByGSM_State_TurnLeftAwayFromObstacleOnRight>
$<TARGET_OBJECTS:epuckTurnAwayByGSM_State_TurnRightAwayFromObstacleOnLeft>
$<TARGET_OBJECTS:epuckTurnAwayByGSM_State_Observe>
$<TARGET_OBJECTS:epuckTurnAwayByGSM_State_No_Obstacles>
$<TARGET_OBJECTS:epuckTurnAwayByGSM_State_SUSPENDED>
$<TARGET_OBJECTS:epuckTurnAwayByGSM>)
set_target_properties(libepuckTurnAwayByGSM  PROPERTIES OUTPUT_NAME epuckTurnAwayByGSM)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set_target_properties(epuckTurnAwayByGSM_State_InitialPseudoState PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnAwayByGSM_State_Initial PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnAwayByGSM_State_TurnLeftAwayFromObstacleOnRight PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnAwayByGSM_State_TurnRightAwayFromObstacleOnLeft PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnAwayByGSM_State_Observe PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnAwayByGSM_State_No_Obstacles PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnAwayByGSM_State_SUSPENDED PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnAwayByGSM PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
## Specify libraries to link a library or executable target against
target_link_libraries(libepuckTurnAwayByGSM ${catkin_LIBRARIES})
