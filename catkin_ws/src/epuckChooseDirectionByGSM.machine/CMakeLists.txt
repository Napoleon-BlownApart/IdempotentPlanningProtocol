cmake_minimum_required(VERSION 2.8.3)
project(epuckchoosedirectionbygsm)
## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS clfsm gusimplewhiteboard)
###################################
## catkin specific configuration ##
###################################
catkin_package( LIBRARIES libepuckChooseDirectionByGSM )
###########
## Build ##
###########
set(CMAKE_CXX_FLAGS "-std=c++11 -DWHITEBOARD_POSTER_STRING_CONVERSION=1")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")
include_directories(include)
include_directories(${clfsm_INCLUDE_DIRS})
link_directories(${CATKIN_DEVEL_PREFIX}/lib)
## Declare a cpp library
add_library(epuckChooseDirectionByGSM_State_InitialPseudoState OBJECT State_InitialPseudoState.mm )
add_library(epuckChooseDirectionByGSM_State_Initial OBJECT State_Initial.mm )
add_library(epuckChooseDirectionByGSM_State_ChooseDirection OBJECT State_ChooseDirection.mm )
add_library(epuckChooseDirectionByGSM_State_Stop OBJECT State_Stop.mm )
add_library(epuckChooseDirectionByGSM_State_Check_If_Ready OBJECT State_Check_If_Ready.mm )
add_library(epuckChooseDirectionByGSM_State_Not_Ready OBJECT State_Not_Ready.mm )
add_library(epuckChooseDirectionByGSM_State_SUSPENDED OBJECT State_SUSPENDED.mm )
add_library(epuckChooseDirectionByGSM OBJECT epuckChooseDirectionByGSM.mm )
add_library(libepuckChooseDirectionByGSM
$<TARGET_OBJECTS:epuckChooseDirectionByGSM_State_InitialPseudoState>
$<TARGET_OBJECTS:epuckChooseDirectionByGSM_State_Initial>
$<TARGET_OBJECTS:epuckChooseDirectionByGSM_State_ChooseDirection>
$<TARGET_OBJECTS:epuckChooseDirectionByGSM_State_Stop>
$<TARGET_OBJECTS:epuckChooseDirectionByGSM_State_Check_If_Ready>
$<TARGET_OBJECTS:epuckChooseDirectionByGSM_State_Not_Ready>
$<TARGET_OBJECTS:epuckChooseDirectionByGSM_State_SUSPENDED>
$<TARGET_OBJECTS:epuckChooseDirectionByGSM>)
set_target_properties(libepuckChooseDirectionByGSM  PROPERTIES OUTPUT_NAME epuckChooseDirectionByGSM)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set_target_properties(epuckChooseDirectionByGSM_State_InitialPseudoState PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckChooseDirectionByGSM_State_Initial PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckChooseDirectionByGSM_State_ChooseDirection PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckChooseDirectionByGSM_State_Stop PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckChooseDirectionByGSM_State_Check_If_Ready PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckChooseDirectionByGSM_State_Not_Ready PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckChooseDirectionByGSM_State_SUSPENDED PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckChooseDirectionByGSM PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
## Specify libraries to link a library or executable target against
target_link_libraries(libepuckChooseDirectionByGSM  ${catkin_LIBRARIES})
