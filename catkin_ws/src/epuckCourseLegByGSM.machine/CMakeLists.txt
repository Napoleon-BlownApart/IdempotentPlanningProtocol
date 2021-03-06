cmake_minimum_required(VERSION 2.8.3)
project(epuckcourselegbygsm)
## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS clfsm gusimplewhiteboard)
###################################
## catkin specific configuration ##
###################################
catkin_package( LIBRARIES libepuckCourseLegByGSM )
###########
## Build ##
###########
set(CMAKE_CXX_FLAGS "-std=c++11 -DWHITEBOARD_POSTER_STRING_CONVERSION=1")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")
include_directories(include)
include_directories(${clfsm_INCLUDE_DIRS})
link_directories(${CATKIN_DEVEL_PREFIX}/lib)
## Declare a cpp library
add_library(epuckCourseLegByGSM_State_InitialPseudoState OBJECT State_InitialPseudoState.mm )
add_library(epuckCourseLegByGSM_State_Initial OBJECT State_Initial.mm )
add_library(epuckCourseLegByGSM_State_ChooseDirection OBJECT State_ChooseDirection.mm )
add_library(epuckCourseLegByGSM_State_Wait_4_Scan OBJECT State_Wait_4_Scan.mm )
add_library(epuckCourseLegByGSM_State_SUSPENDED OBJECT State_SUSPENDED.mm )
add_library(epuckCourseLegByGSM_State_At_Goal OBJECT State_At_Goal.mm )
add_library(epuckCourseLegByGSM_State_Unreachable OBJECT State_Unreachable.mm )
add_library(epuckCourseLegByGSM_State_Stop OBJECT State_Stop.mm )
add_library(epuckCourseLegByGSM_State_DirectionChosen OBJECT State_DirectionChosen.mm )
add_library(epuckCourseLegByGSM_State_Observe OBJECT State_Observe.mm )
add_library(epuckCourseLegByGSM_State_Detected_Intersection OBJECT State_Detected_Intersection.mm )
add_library(epuckCourseLegByGSM_State_Not_Detected_Intersection OBJECT State_Not_Detected_Intersection.mm )
add_library(epuckCourseLegByGSM OBJECT epuckCourseLegByGSM.mm )
add_library(libepuckCourseLegByGSM
$<TARGET_OBJECTS:epuckCourseLegByGSM_State_InitialPseudoState>
$<TARGET_OBJECTS:epuckCourseLegByGSM_State_Initial>
$<TARGET_OBJECTS:epuckCourseLegByGSM_State_ChooseDirection>
$<TARGET_OBJECTS:epuckCourseLegByGSM_State_Wait_4_Scan>
$<TARGET_OBJECTS:epuckCourseLegByGSM_State_SUSPENDED>
$<TARGET_OBJECTS:epuckCourseLegByGSM_State_At_Goal>
$<TARGET_OBJECTS:epuckCourseLegByGSM_State_Unreachable>
$<TARGET_OBJECTS:epuckCourseLegByGSM_State_Stop>
$<TARGET_OBJECTS:epuckCourseLegByGSM_State_DirectionChosen>
$<TARGET_OBJECTS:epuckCourseLegByGSM_State_Observe>
$<TARGET_OBJECTS:epuckCourseLegByGSM_State_Detected_Intersection>
$<TARGET_OBJECTS:epuckCourseLegByGSM_State_Not_Detected_Intersection>
$<TARGET_OBJECTS:epuckCourseLegByGSM>)
set_target_properties(libepuckCourseLegByGSM  PROPERTIES OUTPUT_NAME epuckCourseLegByGSM)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set_target_properties(epuckCourseLegByGSM_State_InitialPseudoState PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCourseLegByGSM_State_Initial PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCourseLegByGSM_State_ChooseDirection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCourseLegByGSM_State_Wait_4_Scan PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCourseLegByGSM_State_SUSPENDED PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCourseLegByGSM_State_At_Goal PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCourseLegByGSM_State_Unreachable PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCourseLegByGSM_State_Stop PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCourseLegByGSM_State_DirectionChosen PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCourseLegByGSM_State_Observe PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCourseLegByGSM_State_Detected_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCourseLegByGSM_State_Not_Detected_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCourseLegByGSM PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
## Specify libraries to link a library or executable target against
target_link_libraries(libepuckCourseLegByGSM  ${catkin_LIBRARIES})
