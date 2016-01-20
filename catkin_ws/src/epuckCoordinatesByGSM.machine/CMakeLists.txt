cmake_minimum_required(VERSION 2.8.3)
project(epuckcoordinatesbygsm)
## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS clfsm gusimplewhiteboard)
###################################
## catkin specific configuration ##
###################################
catkin_package( LIBRARIES libepuckCoordinatesByGSM )
###########
## Build ##
###########
set(CMAKE_CXX_FLAGS "-std=c++11 -DWHITEBOARD_POSTER_STRING_CONVERSION=1")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")
include_directories(include)
include_directories(${clfsm_INCLUDE_DIRS})
link_directories(${CATKIN_DEVEL_PREFIX}/lib)
## Declare a cpp library
add_library(epuckCoordinatesByGSM_State_InitialPseudoState OBJECT State_InitialPseudoState.mm )
add_library(epuckCoordinatesByGSM_State_Initial OBJECT State_Initial.mm )
add_library(epuckCoordinatesByGSM_State_Observe OBJECT State_Observe.mm )
add_library(epuckCoordinatesByGSM_State_Detected_Intersection OBJECT State_Detected_Intersection.mm )
add_library(epuckCoordinatesByGSM_State_Not_Detected_Intersection OBJECT State_Not_Detected_Intersection.mm )
add_library(epuckCoordinatesByGSM_State_Entering_Intersection OBJECT State_Entering_Intersection.mm )
add_library(epuckCoordinatesByGSM_State_Update_Coordinates OBJECT State_Update_Coordinates.mm )
add_library(epuckCoordinatesByGSM_State_Moved_Up OBJECT State_Moved_Up.mm )
add_library(epuckCoordinatesByGSM_State_Moved_Right OBJECT State_Moved_Right.mm )
add_library(epuckCoordinatesByGSM_State_Moved_Down OBJECT State_Moved_Down.mm )
add_library(epuckCoordinatesByGSM_State_Moved_Left OBJECT State_Moved_Left.mm )
add_library(epuckCoordinatesByGSM_State_SUSPENDED OBJECT State_SUSPENDED.mm )
add_library(epuckCoordinatesByGSM_State_Are_We_Travelling OBJECT State_Are_We_Travelling.mm )
add_library(epuckCoordinatesByGSM OBJECT epuckCoordinatesByGSM.mm )
add_library(libepuckCoordinatesByGSM
$<TARGET_OBJECTS:epuckCoordinatesByGSM_State_InitialPseudoState>
$<TARGET_OBJECTS:epuckCoordinatesByGSM_State_Initial>
$<TARGET_OBJECTS:epuckCoordinatesByGSM_State_Observe>
$<TARGET_OBJECTS:epuckCoordinatesByGSM_State_Detected_Intersection>
$<TARGET_OBJECTS:epuckCoordinatesByGSM_State_Not_Detected_Intersection>
$<TARGET_OBJECTS:epuckCoordinatesByGSM_State_Entering_Intersection>
$<TARGET_OBJECTS:epuckCoordinatesByGSM_State_Update_Coordinates>
$<TARGET_OBJECTS:epuckCoordinatesByGSM_State_Moved_Up>
$<TARGET_OBJECTS:epuckCoordinatesByGSM_State_Moved_Right>
$<TARGET_OBJECTS:epuckCoordinatesByGSM_State_Moved_Down>
$<TARGET_OBJECTS:epuckCoordinatesByGSM_State_Moved_Left>
$<TARGET_OBJECTS:epuckCoordinatesByGSM_State_SUSPENDED>
$<TARGET_OBJECTS:epuckCoordinatesByGSM_State_Are_We_Travelling>
$<TARGET_OBJECTS:epuckCoordinatesByGSM>)
set_target_properties(libepuckCoordinatesByGSM  PROPERTIES OUTPUT_NAME epuckCoordinatesByGSM)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set_target_properties(epuckCoordinatesByGSM_State_InitialPseudoState PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCoordinatesByGSM_State_Initial PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCoordinatesByGSM_State_Observe PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCoordinatesByGSM_State_Detected_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCoordinatesByGSM_State_Not_Detected_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCoordinatesByGSM_State_Entering_Intersection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCoordinatesByGSM_State_Update_Coordinates PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCoordinatesByGSM_State_Moved_Up PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCoordinatesByGSM_State_Moved_Right PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCoordinatesByGSM_State_Moved_Down PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCoordinatesByGSM_State_Moved_Left PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCoordinatesByGSM_State_SUSPENDED PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCoordinatesByGSM_State_Are_We_Travelling PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckCoordinatesByGSM PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
## Specify libraries to link a library or executable target against
target_link_libraries(libepuckCoordinatesByGSM ${catkin_LIBRARIES})
