cmake_minimum_required(VERSION 2.8.3)
project(epuckorientationbygsm)
## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS clfsm gusimplewhiteboard)
###################################
## catkin specific configuration ##
###################################
catkin_package( LIBRARIES libepuckOrientationByGSM )
###########
## Build ##
###########
set(CMAKE_CXX_FLAGS "-std=c++11 -DWHITEBOARD_POSTER_STRING_CONVERSION=1")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")
include_directories(include)
include_directories(${clfsm_INCLUDE_DIRS})
link_directories(${CATKIN_DEVEL_PREFIX}/lib)
## Declare a cpp library
add_library(epuckOrientationByGSM_State_InitialPseudoState OBJECT State_InitialPseudoState.mm )
add_library(epuckOrientationByGSM_State_Initial OBJECT State_Initial.mm )
add_library(epuckOrientationByGSM_State_Observe_Turn OBJECT State_Observe_Turn.mm )
add_library(epuckOrientationByGSM_State_Not_Turning OBJECT State_Not_Turning.mm )
add_library(epuckOrientationByGSM_State_Turn_Completed OBJECT State_Turn_Completed.mm )
add_library(epuckOrientationByGSM_State_Not_Yet OBJECT State_Not_Yet.mm )
add_library(epuckOrientationByGSM_State_Turn_Right OBJECT State_Turn_Right.mm )
add_library(epuckOrientationByGSM_State_Turn_Left OBJECT State_Turn_Left.mm )
add_library(epuckOrientationByGSM_State_Turn_Around OBJECT State_Turn_Around.mm )
add_library(epuckOrientationByGSM_State_SUSPENDED OBJECT State_SUSPENDED.mm )
add_library(epuckOrientationByGSM OBJECT epuckOrientationByGSM.mm )
add_library(libepuckOrientationByGSM
$<TARGET_OBJECTS:epuckOrientationByGSM_State_InitialPseudoState>
$<TARGET_OBJECTS:epuckOrientationByGSM_State_Initial>
$<TARGET_OBJECTS:epuckOrientationByGSM_State_Observe_Turn>
$<TARGET_OBJECTS:epuckOrientationByGSM_State_Not_Turning>
$<TARGET_OBJECTS:epuckOrientationByGSM_State_Turn_Completed>
$<TARGET_OBJECTS:epuckOrientationByGSM_State_Not_Yet>
$<TARGET_OBJECTS:epuckOrientationByGSM_State_Turn_Right>
$<TARGET_OBJECTS:epuckOrientationByGSM_State_Turn_Left>
$<TARGET_OBJECTS:epuckOrientationByGSM_State_Turn_Around>
$<TARGET_OBJECTS:epuckOrientationByGSM_State_SUSPENDED>
$<TARGET_OBJECTS:epuckOrientationByGSM>)
set_target_properties(libepuckOrientationByGSM  PROPERTIES OUTPUT_NAME epuckOrientationByGSM)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set_target_properties(epuckOrientationByGSM_State_InitialPseudoState PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckOrientationByGSM_State_Initial PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckOrientationByGSM_State_Observe_Turn PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckOrientationByGSM_State_Not_Turning PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckOrientationByGSM_State_Turn_Completed PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckOrientationByGSM_State_Not_Yet PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckOrientationByGSM_State_Turn_Right PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckOrientationByGSM_State_Turn_Left PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckOrientationByGSM_State_Turn_Around PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckOrientationByGSM_State_SUSPENDED PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckOrientationByGSM PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
## Specify libraries to link a library or executable target against
target_link_libraries(libepuckOrientationByGSM ${catkin_LIBRARIES})
