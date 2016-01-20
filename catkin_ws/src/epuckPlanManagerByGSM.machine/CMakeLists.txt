cmake_minimum_required(VERSION 2.8.3)
project(epuckplanmanagerbygsm)
## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS clfsm gusimplewhiteboard)
###################################
## catkin specific configuration ##
###################################
catkin_package( LIBRARIES libepuckPlanManagerByGSM )
###########
## Build ##
###########
set(CMAKE_CXX_FLAGS "-std=c++11 -DWHITEBOARD_POSTER_STRING_CONVERSION=1")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")
include_directories(include)
include_directories(${clfsm_INCLUDE_DIRS})
link_directories(${CATKIN_DEVEL_PREFIX}/lib)
## Declare a cpp library
add_library(epuckPlanManagerByGSM_State_InitialPseudoState OBJECT State_InitialPseudoState.mm )
add_library(epuckPlanManagerByGSM_State_Initial OBJECT State_Initial.mm )
add_library(epuckPlanManagerByGSM_State_Observe OBJECT State_Observe.mm )
add_library(epuckPlanManagerByGSM_State_Output_Obstacles OBJECT State_Output_Obstacles.mm )
add_library(epuckPlanManagerByGSM_State_Receive_New_Plan OBJECT State_Receive_New_Plan.mm )
add_library(epuckPlanManagerByGSM_State_Set_Next_Goal OBJECT State_Set_Next_Goal.mm )
add_library(epuckPlanManagerByGSM_State_Record_Obstacle OBJECT State_Record_Obstacle.mm )
add_library(epuckPlanManagerByGSM_State_Save_Obstacles OBJECT State_Save_Obstacles.mm )
add_library(epuckPlanManagerByGSM_State_Plan_Settings OBJECT State_Plan_Settings.mm )
add_library(epuckPlanManagerByGSM_State_Load_Obstacles OBJECT State_Load_Obstacles.mm )
add_library(epuckPlanManagerByGSM_State_Is_This_The_End OBJECT State_Is_This_The_End.mm )
add_library(epuckPlanManagerByGSM_State_Last_Obstacle_Only OBJECT State_Last_Obstacle_Only.mm )
add_library(epuckPlanManagerByGSM_State_Is_Array_Full OBJECT State_Is_Array_Full.mm )
add_library(epuckPlanManagerByGSM_State_Add_Next_Obstacle OBJECT State_Add_Next_Obstacle.mm )
add_library(epuckPlanManagerByGSM_State_Get_A_Portion OBJECT State_Get_A_Portion.mm )
add_library(epuckPlanManagerByGSM_State_Send_Obstacles OBJECT State_Send_Obstacles.mm )
add_library(epuckPlanManagerByGSM_State_No_Change OBJECT State_No_Change.mm )
add_library(epuckPlanManagerByGSM_State_Request_New_Plan OBJECT State_Request_New_Plan.mm )
add_library(epuckPlanManagerByGSM OBJECT epuckPlanManagerByGSM.mm )
add_library(libepuckPlanManagerByGSM
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_InitialPseudoState>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Initial>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Observe>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Output_Obstacles>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Receive_New_Plan>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Set_Next_Goal>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Record_Obstacle>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Save_Obstacles>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Plan_Settings>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Load_Obstacles>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Is_This_The_End>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Last_Obstacle_Only>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Is_Array_Full>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Add_Next_Obstacle>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Get_A_Portion>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Send_Obstacles>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_No_Change>
$<TARGET_OBJECTS:epuckPlanManagerByGSM_State_Request_New_Plan>
$<TARGET_OBJECTS:epuckPlanManagerByGSM>)
set_target_properties(libepuckPlanManagerByGSM  PROPERTIES OUTPUT_NAME epuckPlanManagerByGSM)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set_target_properties(epuckPlanManagerByGSM_State_InitialPseudoState PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Initial PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Observe PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Output_Obstacles PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Receive_New_Plan PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Set_Next_Goal PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Record_Obstacle PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Save_Obstacles PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Plan_Settings PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Load_Obstacles PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Is_This_The_End PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Last_Obstacle_Only PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Is_Array_Full PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Add_Next_Obstacle PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Get_A_Portion PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Send_Obstacles PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_No_Change PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM_State_Request_New_Plan PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
set_target_properties(epuckPlanManagerByGSM PROPERTIES COMPILE_FLAGS "-x c++ -fPIC")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
## Specify libraries to link a library or executable target against
target_link_libraries(libepuckPlanManagerByGSM ${catkin_LIBRARIES})
