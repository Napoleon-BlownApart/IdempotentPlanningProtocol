cmake_minimum_required(VERSION 2.8.3)
project(epuckmeanderlinesbygsm)

#set(WHITEBOARD_POSTER_STRING_CONVERSION 1)

#set(WEBOTS_HOME $ENV{WEBOTS_HOME})
#find_library(CPP_CONTROLLER_LIBRARY CppController ${WEBOTS_HOME}/lib)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS clfsm gusimplewhiteboard)
###################################
## catkin specific configuration ##
###################################
catkin_package( LIBRARIES libepuckMeanderLinesByGSM )
###########
## Build ##
###########
set(CMAKE_CXX_FLAGS "-std=c++11 -DWHITEBOARD_POSTER_STRING_CONVERSION=1")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")
include_directories(include)
#include_directories(${libclfsm_INCLUDE_DIRS})
include_directories(${clfsm_INCLUDE_DIRS})
#include_directories(${WEBOTS_HOME}/include/controller/cpp)
link_directories(${CATKIN_DEVEL_PREFIX}/lib)

## Declare a cpp library
add_library(epuckMeanderLinesByGSM_State_InitialPseudoState OBJECT State_InitialPseudoState.mm )
add_library(epuckMeanderLinesByGSM_State_Initial OBJECT State_Initial.mm )
add_library(epuckMeanderLinesByGSM_State_Forward OBJECT State_Forward.mm )
add_library(epuckMeanderLinesByGSM_State_Intersection_Check_LeftGS OBJECT State_Intersection_Check_LeftGS.mm )
add_library(epuckMeanderLinesByGSM_State_Turn_Right OBJECT State_Turn_Right.mm )
add_library(epuckMeanderLinesByGSM_State_Turn_Left OBJECT State_Turn_Left.mm )
add_library(epuckMeanderLinesByGSM_State_Align_After_Left_Turn OBJECT State_Align_After_Left_Turn.mm )
add_library(epuckMeanderLinesByGSM_State_ChooseDirection OBJECT State_ChooseDirection.mm )
add_library(epuckMeanderLinesByGSM_State_Stop OBJECT State_Stop.mm )
add_library(epuckMeanderLinesByGSM_State_Entering_Intersection OBJECT State_Entering_Intersection.mm )
add_library(epuckMeanderLinesByGSM_State_Forward_Feedback OBJECT State_Forward_Feedback.mm )
add_library(epuckMeanderLinesByGSM_State_LeftGS_Detects_Path OBJECT State_LeftGS_Detects_Path.mm )
add_library(epuckMeanderLinesByGSM_State_LeftGS_Detects_Intersection OBJECT State_LeftGS_Detects_Intersection.mm )
add_library(epuckMeanderLinesByGSM_State_CentreGS_Detects_Path OBJECT State_CentreGS_Detects_Path.mm )
add_library(epuckMeanderLinesByGSM_State_CentreGS_Detects_Intersection OBJECT State_CentreGS_Detects_Intersection.mm )
add_library(epuckMeanderLinesByGSM_State_RightGS_Detects_Path OBJECT State_RightGS_Detects_Path.mm )
add_library(epuckMeanderLinesByGSM_State_RightGS_Detects_Intersection OBJECT State_RightGS_Detects_Intersection.mm )
add_library(epuckMeanderLinesByGSM_State_May_Need_Align_In_Intersection OBJECT State_May_Need_Align_In_Intersection.mm )
add_library(epuckMeanderLinesByGSM_State_Align_In_Intersection OBJECT State_Align_In_Intersection.mm )
add_library(epuckMeanderLinesByGSM_State_Align_To_Left_Beyond_Intersection OBJECT State_Align_To_Left_Beyond_Intersection.mm )
add_library(epuckMeanderLinesByGSM_State_May_Need_Align_Beyond_Intersection OBJECT State_May_Need_Align_Beyond_Intersection.mm )
add_library(epuckMeanderLinesByGSM_State_TurnLeftAwayFromObstacleOnRight OBJECT State_TurnLeftAwayFromObstacleOnRight.mm )
add_library(epuckMeanderLinesByGSM_State_TurnRightAwayFromObstacleOnLeft OBJECT State_TurnRightAwayFromObstacleOnLeft.mm )
add_library(epuckMeanderLinesByGSM_State_LeftGS_Detects_Nothing OBJECT State_LeftGS_Detects_Nothing.mm )
add_library(epuckMeanderLinesByGSM_State_Intersection_Check_CentreGS OBJECT State_Intersection_Check_CentreGS.mm )
add_library(epuckMeanderLinesByGSM_State_CentreGS_Detects_Nothing OBJECT State_CentreGS_Detects_Nothing.mm )
add_library(epuckMeanderLinesByGSM_State_Intersection_Check_RightGS OBJECT State_Intersection_Check_RightGS.mm )
add_library(epuckMeanderLinesByGSM_State_RightGS_Detects_Nothing OBJECT State_RightGS_Detects_Nothing.mm )
add_library(epuckMeanderLinesByGSM_State_Intersection_Alignment OBJECT State_Intersection_Alignment.mm )
add_library(epuckMeanderLinesByGSM_State_Determine_Directiion_Left OBJECT State_Determine_Directiion_Left.mm )
add_library(epuckMeanderLinesByGSM_State_Align_Beyond_Intersection OBJECT State_Align_Beyond_Intersection.mm )
add_library(epuckMeanderLinesByGSM_State_Left_Is_Available OBJECT State_Left_Is_Available.mm )
add_library(epuckMeanderLinesByGSM_State_Determine_Direction_Right OBJECT State_Determine_Direction_Right.mm )
add_library(epuckMeanderLinesByGSM_State_Right_Is_Available OBJECT State_Right_Is_Available.mm )
add_library(epuckMeanderLinesByGSM_State_Determine_Direction_Straight OBJECT State_Determine_Direction_Straight.mm )
add_library(epuckMeanderLinesByGSM_State_Straight_Is_Available OBJECT State_Straight_Is_Available.mm )
add_library(epuckMeanderLinesByGSM_State_Continue_Forward OBJECT State_Continue_Forward.mm )
add_library(epuckMeanderLinesByGSM_State_Continue_Align_Left OBJECT State_Continue_Align_Left.mm )
add_library(epuckMeanderLinesByGSM_State_Align_After_Right_Turn OBJECT State_Align_After_Right_Turn.mm )
add_library(epuckMeanderLinesByGSM_State_Continue_Align_Right OBJECT State_Continue_Align_Right.mm )
add_library(epuckMeanderLinesByGSM OBJECT epuckMeanderLinesByGSM.mm )
add_library(libepuckMeanderLinesByGSM
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_InitialPseudoState>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Initial>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Forward>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Intersection_Check_LeftGS>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Turn_Right>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Turn_Left>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Align_After_Left_Turn>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_ChooseDirection>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Stop>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Entering_Intersection>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Forward_Feedback>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_LeftGS_Detects_Path>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_LeftGS_Detects_Intersection>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_CentreGS_Detects_Path>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_CentreGS_Detects_Intersection>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_RightGS_Detects_Path>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_RightGS_Detects_Intersection>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_May_Need_Align_In_Intersection>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Align_In_Intersection>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Align_To_Left_Beyond_Intersection>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_May_Need_Align_Beyond_Intersection>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_TurnLeftAwayFromObstacleOnRight>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_TurnRightAwayFromObstacleOnLeft>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_LeftGS_Detects_Nothing>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Intersection_Check_CentreGS>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_CentreGS_Detects_Nothing>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Intersection_Check_RightGS>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_RightGS_Detects_Nothing>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Intersection_Alignment>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Determine_Directiion_Left>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Align_Beyond_Intersection>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Left_Is_Available>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Determine_Direction_Right>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Right_Is_Available>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Determine_Direction_Straight>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Straight_Is_Available>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Continue_Forward>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Continue_Align_Left>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Align_After_Right_Turn>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM_State_Continue_Align_Right>
$<TARGET_OBJECTS:epuckMeanderLinesByGSM>)
set_target_properties(libepuckMeanderLinesByGSM  PROPERTIES OUTPUT_NAME epuckMeanderLinesByGSM)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set_target_properties(epuckMeanderLinesByGSM_State_InitialPseudoState PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Initial PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Forward PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Intersection_Check_LeftGS PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Turn_Right PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Turn_Left PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Align_After_Left_Turn PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_ChooseDirection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Stop PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Entering_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Forward_Feedback PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_LeftGS_Detects_Path PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_LeftGS_Detects_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_CentreGS_Detects_Path PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_CentreGS_Detects_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_RightGS_Detects_Path PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_RightGS_Detects_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_May_Need_Align_In_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Align_In_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Align_To_Left_Beyond_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_May_Need_Align_Beyond_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_TurnLeftAwayFromObstacleOnRight PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_TurnRightAwayFromObstacleOnLeft PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_LeftGS_Detects_Nothing PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Intersection_Check_CentreGS PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_CentreGS_Detects_Nothing PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Intersection_Check_RightGS PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_RightGS_Detects_Nothing PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Intersection_Alignment PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Determine_Directiion_Left PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Align_Beyond_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Left_Is_Available PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Determine_Direction_Right PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Right_Is_Available PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Determine_Direction_Straight PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Straight_Is_Available PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Continue_Forward PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Continue_Align_Left PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Align_After_Right_Turn PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM_State_Continue_Align_Right PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckMeanderLinesByGSM PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
## Specify libraries to link a library or executable target against
target_link_libraries(libepuckMeanderLinesByGSM ${catkin_LIBRARIES})
