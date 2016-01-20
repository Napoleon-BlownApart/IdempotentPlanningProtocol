cmake_minimum_required(VERSION 2.8.3)
project(epuckintersectionbygsm)
## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS clfsm gusimplewhiteboard)
###################################
## catkin specific configuration ##
###################################
catkin_package( LIBRARIES libepuckIntersectionByGSM )
###########
## Build ##
###########
set(CMAKE_CXX_FLAGS "-std=c++11 -DWHITEBOARD_POSTER_STRING_CONVERSION=1")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")
include_directories(include)
include_directories(${clfsm_INCLUDE_DIRS})
link_directories(${CATKIN_DEVEL_PREFIX}/lib)
## Declare a cpp library
add_library(epuckIntersectionByGSM_State_InitialPseudoState OBJECT State_InitialPseudoState.mm )
add_library(epuckIntersectionByGSM_State_Initial OBJECT State_Initial.mm )
add_library(epuckIntersectionByGSM_State_Observe OBJECT State_Observe.mm )
add_library(epuckIntersectionByGSM_State_Intersection_Check_LeftGS OBJECT State_Intersection_Check_LeftGS.mm )
add_library(epuckIntersectionByGSM_State_In_Intersection_Aligned OBJECT State_In_Intersection_Aligned.mm )
add_library(epuckIntersectionByGSM_State_Entering_Intersection OBJECT State_Entering_Intersection.mm )
add_library(epuckIntersectionByGSM_State_LeftGS_Detects_Path OBJECT State_LeftGS_Detects_Path.mm )
add_library(epuckIntersectionByGSM_State_CentreGS_Detects_Path OBJECT State_CentreGS_Detects_Path.mm )
add_library(epuckIntersectionByGSM_State_CentreGS_Detects_Intersection OBJECT State_CentreGS_Detects_Intersection.mm )
add_library(epuckIntersectionByGSM_State_RightGS_Detects_Path OBJECT State_RightGS_Detects_Path.mm )
add_library(epuckIntersectionByGSM_State_RightGS_Detects_Intersection OBJECT State_RightGS_Detects_Intersection.mm )
add_library(epuckIntersectionByGSM_State_May_Need_Align_In_Intersection OBJECT State_May_Need_Align_In_Intersection.mm )
add_library(epuckIntersectionByGSM_State_Align_In_Intersection OBJECT State_Align_In_Intersection.mm )
add_library(epuckIntersectionByGSM_State_May_Need_Align_Beyond_Intersection OBJECT State_May_Need_Align_Beyond_Intersection.mm )
add_library(epuckIntersectionByGSM_State_LeftGS_Detects_Nothing OBJECT State_LeftGS_Detects_Nothing.mm )
add_library(epuckIntersectionByGSM_State_Intersection_Check_CentreGS OBJECT State_Intersection_Check_CentreGS.mm )
add_library(epuckIntersectionByGSM_State_CentreGS_Detects_Nothing OBJECT State_CentreGS_Detects_Nothing.mm )
add_library(epuckIntersectionByGSM_State_Intersection_Check_RightGS OBJECT State_Intersection_Check_RightGS.mm )
add_library(epuckIntersectionByGSM_State_RightGS_Detects_Nothing OBJECT State_RightGS_Detects_Nothing.mm )
add_library(epuckIntersectionByGSM_State_Intersection_Alignment OBJECT State_Intersection_Alignment.mm )
add_library(epuckIntersectionByGSM_State_Determine_Direction_Left OBJECT State_Determine_Direction_Left.mm )
add_library(epuckIntersectionByGSM_State_Align_Beyond_Intersection OBJECT State_Align_Beyond_Intersection.mm )
add_library(epuckIntersectionByGSM_State_Left_Is_Available OBJECT State_Left_Is_Available.mm )
add_library(epuckIntersectionByGSM_State_Determine_Direction_Right OBJECT State_Determine_Direction_Right.mm )
add_library(epuckIntersectionByGSM_State_Right_Is_Available OBJECT State_Right_Is_Available.mm )
add_library(epuckIntersectionByGSM_State_Determine_Direction_Straight OBJECT State_Determine_Direction_Straight.mm )
add_library(epuckIntersectionByGSM_State_Straight_Is_Available OBJECT State_Straight_Is_Available.mm )
add_library(epuckIntersectionByGSM_State_Detected_Intersection OBJECT State_Detected_Intersection.mm )
add_library(epuckIntersectionByGSM_State_Not_Detected_Intersection OBJECT State_Not_Detected_Intersection.mm )
add_library(epuckIntersectionByGSM_State_LeftGS_Detects_Intersection OBJECT State_LeftGS_Detects_Intersection.mm )
add_library(epuckIntersectionByGSM_State_SUSPENDED OBJECT State_SUSPENDED.mm )
add_library(epuckIntersectionByGSM OBJECT epuckIntersectionByGSM.mm )
add_library(libepuckIntersectionByGSM
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_InitialPseudoState>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Initial>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Observe>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Intersection_Check_LeftGS>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_In_Intersection_Aligned>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Entering_Intersection>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_LeftGS_Detects_Path>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_CentreGS_Detects_Path>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_CentreGS_Detects_Intersection>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_RightGS_Detects_Path>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_RightGS_Detects_Intersection>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_May_Need_Align_In_Intersection>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Align_In_Intersection>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_May_Need_Align_Beyond_Intersection>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_LeftGS_Detects_Nothing>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Intersection_Check_CentreGS>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_CentreGS_Detects_Nothing>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Intersection_Check_RightGS>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_RightGS_Detects_Nothing>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Intersection_Alignment>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Determine_Direction_Left>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Align_Beyond_Intersection>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Left_Is_Available>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Determine_Direction_Right>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Right_Is_Available>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Determine_Direction_Straight>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Straight_Is_Available>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Detected_Intersection>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_Not_Detected_Intersection>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_LeftGS_Detects_Intersection>
$<TARGET_OBJECTS:epuckIntersectionByGSM_State_SUSPENDED>
$<TARGET_OBJECTS:epuckIntersectionByGSM>)
set_target_properties(libepuckIntersectionByGSM  PROPERTIES OUTPUT_NAME epuckIntersectionByGSM)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set_target_properties(epuckIntersectionByGSM_State_InitialPseudoState PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Initial PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Observe PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Intersection_Check_LeftGS PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_In_Intersection_Aligned PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Entering_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_LeftGS_Detects_Path PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_CentreGS_Detects_Path PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_CentreGS_Detects_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_RightGS_Detects_Path PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_RightGS_Detects_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_May_Need_Align_In_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Align_In_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_May_Need_Align_Beyond_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_LeftGS_Detects_Nothing PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Intersection_Check_CentreGS PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_CentreGS_Detects_Nothing PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Intersection_Check_RightGS PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_RightGS_Detects_Nothing PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Intersection_Alignment PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Determine_Direction_Left PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Align_Beyond_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Left_Is_Available PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Determine_Direction_Right PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Right_Is_Available PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Determine_Direction_Straight PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Straight_Is_Available PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Detected_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_Not_Detected_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_LeftGS_Detects_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM_State_SUSPENDED PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckIntersectionByGSM PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
## Specify libraries to link a library or executable target against
target_link_libraries(libepuckIntersectionByGSM ${catkin_LIBRARIES})
