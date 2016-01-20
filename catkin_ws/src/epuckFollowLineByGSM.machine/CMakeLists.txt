cmake_minimum_required(VERSION 2.8.3)
project(epuckfollowlinebygsm)
## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS clfsm gusimplewhiteboard)
###################################
## catkin specific configuration ##
###################################
catkin_package( LIBRARIES libepuckFollowLineByGSM )
###########
## Build ##
###########
set(CMAKE_CXX_FLAGS "-std=c++11 -DWHITEBOARD_POSTER_STRING_CONVERSION=1")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")
include_directories(include)
include_directories(${clfsm_INCLUDE_DIRS})
link_directories(${CATKIN_DEVEL_PREFIX}/lib)
## Declare a cpp library
add_library(epuckFollowLineByGSM_State_InitialPseudoState OBJECT State_InitialPseudoState.mm )
add_library(epuckFollowLineByGSM_State_Initial OBJECT State_Initial.mm )
add_library(epuckFollowLineByGSM_State_Forward OBJECT State_Forward.mm )
add_library(epuckFollowLineByGSM_State_Forward_Feedback OBJECT State_Forward_Feedback.mm )
add_library(epuckFollowLineByGSM_State_Continue_Forward OBJECT State_Continue_Forward.mm )
add_library(epuckFollowLineByGSM_State_VeeringRight OBJECT State_VeeringRight.mm )
add_library(epuckFollowLineByGSM_State_VeeringLeft OBJECT State_VeeringLeft.mm )
add_library(epuckFollowLineByGSM_State_SUSPENDED OBJECT State_SUSPENDED.mm )
add_library(epuckFollowLineByGSM OBJECT epuckFollowLineByGSM.mm )
add_library(libepuckFollowLineByGSM
$<TARGET_OBJECTS:epuckFollowLineByGSM_State_InitialPseudoState>
$<TARGET_OBJECTS:epuckFollowLineByGSM_State_Initial>
$<TARGET_OBJECTS:epuckFollowLineByGSM_State_Forward>
$<TARGET_OBJECTS:epuckFollowLineByGSM_State_Forward_Feedback>
$<TARGET_OBJECTS:epuckFollowLineByGSM_State_Continue_Forward>
$<TARGET_OBJECTS:epuckFollowLineByGSM_State_VeeringRight>
$<TARGET_OBJECTS:epuckFollowLineByGSM_State_VeeringLeft>
$<TARGET_OBJECTS:epuckFollowLineByGSM_State_SUSPENDED>
$<TARGET_OBJECTS:epuckFollowLineByGSM>)
set_target_properties(libepuckFollowLineByGSM  PROPERTIES OUTPUT_NAME epuckFollowLineByGSM)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set_target_properties(epuckFollowLineByGSM_State_InitialPseudoState PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckFollowLineByGSM_State_Initial PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckFollowLineByGSM_State_Forward PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckFollowLineByGSM_State_Forward_Feedback PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckFollowLineByGSM_State_Continue_Forward PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckFollowLineByGSM_State_VeeringRight PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckFollowLineByGSM_State_VeeringLeft PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckFollowLineByGSM_State_SUSPENDED PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckFollowLineByGSM PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
## Specify libraries to link a library or executable target against
target_link_libraries(libepuckFollowLineByGSM ${catkin_LIBRARIES})
