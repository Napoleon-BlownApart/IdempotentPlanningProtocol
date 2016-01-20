cmake_minimum_required(VERSION 2.8.3)
project(webots_epuck_whiteboard_controller)

set(WEBOTS_HOME $ENV{WEBOTS_HOME})

find_package(catkin REQUIRED COMPONENTS gusimplewhiteboard)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_library(CPP_CONTROLLER_LIBRARY CppController ${WEBOTS_HOME}/lib)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES clfsm
  CATKIN_DEPENDS gusimplewhiteboard
#  DEPENDS system_lib
)

###########
## Build ##
###########

set(CMAKE_C_FLAGS "-std=c99")
set(CMAKE_CXX_FLAGS "-std=c++11 -DWHITEBOARD_POSTER_STRING_CONVERSION=1")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
	include
	${gusimplewhiteboard_INCLUDE_DIRS}
	${WEBOTS_HOME}/include/controller/cpp
)

add_executable(epuckwhiteboard
	src/epuckwhiteboard.cpp
)
target_link_libraries(epuckwhiteboard
	gusimplewhiteboard
	${CMAKE_DL_LIBS}
	${LIBDISPATCH_LIBRARIES}
	${CMAKE_THREAD_LIBS_INIT}
  ${CPP_CONTROLLER_LIBRARY}
	dispatch
)
add_dependencies(epuckwhiteboard
	gusimplewhiteboard
)


#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS clfsm clfsm_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_clfsm.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
