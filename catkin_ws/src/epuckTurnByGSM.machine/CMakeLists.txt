cmake_minimum_required(VERSION 2.8.3)
project(epuckturnbygsm)
## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS clfsm gusimplewhiteboard)
###################################
## catkin specific configuration ##
###################################
catkin_package( LIBRARIES libepuckTurnByGSM )
###########
## Build ##
###########
set(CMAKE_CXX_FLAGS "-std=c++11 -DWHITEBOARD_POSTER_STRING_CONVERSION=1")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")
include_directories(include)
include_directories(${clfsm_INCLUDE_DIRS})
link_directories(${CATKIN_DEVEL_PREFIX}/lib)
## Declare a cpp library
add_library(epuckTurnByGSM_State_InitialPseudoState OBJECT State_InitialPseudoState.mm )
add_library(epuckTurnByGSM_State_Initial OBJECT State_Initial.mm )
add_library(epuckTurnByGSM_State_Turn_Right OBJECT State_Turn_Right.mm )
add_library(epuckTurnByGSM_State_Turn_Left OBJECT State_Turn_Left.mm )
add_library(epuckTurnByGSM_State_Align_After_Left_Turn OBJECT State_Align_After_Left_Turn.mm )
add_library(epuckTurnByGSM_State_Continue_Align_Left OBJECT State_Continue_Align_Left.mm )
add_library(epuckTurnByGSM_State_Observe OBJECT State_Observe.mm )
add_library(epuckTurnByGSM_State_Not_Required OBJECT State_Not_Required.mm )
add_library(epuckTurnByGSM_State_Turn_Around OBJECT State_Turn_Around.mm )
add_library(epuckTurnByGSM_State_SUSPENDED OBJECT State_SUSPENDED.mm )
add_library(epuckTurnByGSM_State_Turn_Completed OBJECT State_Turn_Completed.mm )
add_library(epuckTurnByGSM_State_Align_After_Right_Turn OBJECT State_Align_After_Right_Turn.mm )
add_library(epuckTurnByGSM_State_Continue_Align_Right OBJECT State_Continue_Align_Right.mm )
add_library(epuckTurnByGSM_State_Straight OBJECT State_Straight.mm )
add_library(epuckTurnByGSM OBJECT epuckTurnByGSM.mm )
add_library(libepuckTurnByGSM
$<TARGET_OBJECTS:epuckTurnByGSM_State_InitialPseudoState>
$<TARGET_OBJECTS:epuckTurnByGSM_State_Initial>
$<TARGET_OBJECTS:epuckTurnByGSM_State_Turn_Right>
$<TARGET_OBJECTS:epuckTurnByGSM_State_Turn_Left>
$<TARGET_OBJECTS:epuckTurnByGSM_State_Align_After_Left_Turn>
$<TARGET_OBJECTS:epuckTurnByGSM_State_Continue_Align_Left>
$<TARGET_OBJECTS:epuckTurnByGSM_State_Observe>
$<TARGET_OBJECTS:epuckTurnByGSM_State_Not_Required>
$<TARGET_OBJECTS:epuckTurnByGSM_State_Turn_Around>
$<TARGET_OBJECTS:epuckTurnByGSM_State_SUSPENDED>
$<TARGET_OBJECTS:epuckTurnByGSM_State_Turn_Completed>
$<TARGET_OBJECTS:epuckTurnByGSM_State_Align_After_Right_Turn>
$<TARGET_OBJECTS:epuckTurnByGSM_State_Continue_Align_Right>
$<TARGET_OBJECTS:epuckTurnByGSM_State_Straight>
$<TARGET_OBJECTS:epuckTurnByGSM>)
set_target_properties(libepuckTurnByGSM  PROPERTIES OUTPUT_NAME epuckTurnByGSM)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set_target_properties(epuckTurnByGSM_State_InitialPseudoState PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnByGSM_State_Initial PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnByGSM_State_Turn_Right PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnByGSM_State_Turn_Left PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnByGSM_State_Align_After_Left_Turn PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnByGSM_State_Continue_Align_Left PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnByGSM_State_Observe PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnByGSM_State_Not_Required PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnByGSM_State_Turn_Around PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnByGSM_State_SUSPENDED PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnByGSM_State_Turn_Completed PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnByGSM_State_Align_After_Right_Turn PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnByGSM_State_Continue_Align_Right PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnByGSM_State_Straight PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckTurnByGSM PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
## Specify libraries to link a library or executable target against
target_link_libraries(libepuckTurnByGSM ${catkin_LIBRARIES})
