#!/bin/bash 
# (c) Vlad Estivill-Castro
# seting up a clfsm amchine for catkin
#
# Modified by Dimitri Joukoff to remove intermediate steps
# that were required before the output file could be used.
#
echo -e "\n(c)-2014 Vlad Estivill-castro\n"
echo -e "Set up for " $1 "on" $(date +"%x %r %Z\n") 
#
# Do we have the .machine in the input
machineName=$1
if [ "$machineName" != "${machineName/machine/}" ]; then
	#echo "extension provided"
machineExtension=$(echo $machineName | sed "s?/??" )
else
	#echo "appending extension"
	machineExtension=$1".machine"
fi
machineName=$(echo $machineExtension | sed "s/\.machine//" )
########## We have the machineName and the machineEstension
UNAME_S=$(uname -s)
UNAME_M=$(uname -m)
thePrefix="lib"
    realtive_catkin_destiantion="../../../devel" 
    catkin_destination=$(pwd)"/$realtive_catkin_destiantion/lib"
    echo "The destination will become $catkin_destination"
##############
if [ -d $machineExtension ]; then
    echo -e "Machine *>" $machineExtension "<* found. Things are fine.\n\n" 
    outputCMakeLists=CMakeLists_$machineName.txt
    echo -e "See\n $outputCMakeLists\n\n"
    destination=$catkin_destination/$machineExtension/${UNAME_S}-${UNAME_M}
    ############################ create the directory for execution
    if [ -d $destination ]; then
	    echo -e "Destination $destination exists\n"
    else
	    echo -e "Creating destination $destination \n"
	    mkdir -p $destination
    fi
    ########
    # copy include files
    cp $machineExtension/*.h ../include
    cp $machineExtension/*.expr ../include
    cp $machineExtension/*VarRefs.mm ../include
    cp $machineExtension/*OnEntry.mm ../include
    cp $machineExtension/*OnExit.mm ../include
    cp $machineExtension/*Internal.mm ../include
    echo "Your CMakeLists.txt needs : find_package(catkin REQUIRED COMPONENTS clfsm gusimplewhiteboard)" 
    #

    echo "cmake_minimum_required(VERSION 2.8.3)" > $outputCMakeLists
    echo "project(${machineName,,})" >> $outputCMakeLists
#    echo "set(WHITEBOARD_POSTER_STRING_CONVERSION 1)" >> $outputCMakeLists
#    echo 'message(STATUS "${PROJECT_NAME} string conversion is: ${WHITEBOARD_POSTER_STRING_CONVERSION}")' >> $outputCMakeLists

#    echo 'set(WEBOTS_HOME $ENV{WEBOTS_HOME})' >> $outputCMakeLists
#    echo 'find_library(CPP_CONTROLLER_LIBRARY CppController ${WEBOTS_HOME}/lib)' >> $outputCMakeLists

    echo "## Find catkin macros and libraries" >> $outputCMakeLists
    echo "find_package(catkin REQUIRED COMPONENTS clfsm gusimplewhiteboard)" >> $outputCMakeLists
    #
    echo "###################################" >> $outputCMakeLists
    echo "## catkin specific configuration ##" >> $outputCMakeLists
    echo "###################################" >> $outputCMakeLists
    echo "Your CMakeLists.txt needs : catkin_package( LIBRARIES  $thePrefix$machineName )"
    echo "catkin_package( LIBRARIES $thePrefix$machineName )" >> $outputCMakeLists
    #
    echo "###########" >> $outputCMakeLists
    echo "## Build ##"  >> $outputCMakeLists
    echo "###########" >> $outputCMakeLists
    echo "Your CMakeLists.txt needs : " 'set(CMAKE_CXX_FLAGS "-std=c++11 -DWHITEBOARD_POSTER_STRING_CONVERSION=1")'
    echo 'set(CMAKE_CXX_FLAGS "-std=c++11 -DWHITEBOARD_POSTER_STRING_CONVERSION=1")' >> $outputCMakeLists
    echo "Your CMakeLists.txt needs : "'set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")'
    echo 'set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")' >> $outputCMakeLists
    #
    echo "Your CMakeLists.txt needs : include_directories(include)"
#    echo 'Your CMakeLists.txt needs : include_directories(${libclfsm_INCLUDE_DIRS})'
    echo 'Your CMakeLists.txt needs : include_directories(${clfsm_INCLUDE_DIRS})'
    echo 'Your CMakeLists.txt needs : include_directories(${CATKIN_DEVEL_PREFIX}/lib)'
    echo "include_directories(include)" >> $outputCMakeLists
#    echo 'include_directories(${libclfsm_INCLUDE_DIRS})' >> $outputCMakeLists
    echo 'include_directories(${clfsm_INCLUDE_DIRS})' >>  $outputCMakeLists
    echo 'link_directories(${CATKIN_DEVEL_PREFIX}/lib)' >>  $outputCMakeLists
#    echo 'include_directories(${WEBOTS_HOME}/include/controller/cpp)' >>  $outputCMakeLists
    ########
    echo "## Declare a cpp library" >>  $outputCMakeLists
    # copy source files files
    #first the machine
#    cp $machineExtension/$machineName.mm ../src
    linkForMachine="add_library($thePrefix$machineName\n"
    ###### loop over the machine's states
    lineNum=1
    stateName=$(sed -n "${lineNum}p" $machineExtension/States)
    filenameForState=State_$stateName.mm
    while [ -f $machineExtension/$filenameForState ]; do
       echo  "Procesing state :" $stateName
       echo "Your CMakeLists.txt needs : add_library(${machineName}_State_"$stateName" OBJECT "$filenameForState  ")"
       echo "add_library(${machineName}_State_"$stateName" OBJECT "$filenameForState  ")"  >>  $outputCMakeLists
#       cp $machineExtension/$filenameForState ../src
       linkForMachine=$linkForMachine'$<TARGET_OBJECTS:'"${machineName}_State_$stateName>\n"
       # update the filename or the state
       lineNum=$((lineNum+1))
       stateName=$(sed -n "${lineNum}p" $machineExtension/States)
       filenameForState=State_$stateName.mm
    done
    #
    #
    # comamnd for the machine
    echo "Your CMakeLists.txt needs : add_library($machineName OBJECT $machineName.mm )"
    echo "add_library($machineName OBJECT $machineName.mm )" >>  $outputCMakeLists
    linkForMachine=$linkForMachine'$<TARGET_OBJECTS:'$machineName">)"
    echo -e "Your CMakeLists.txt needs : " $linkForMachine
    echo -e $linkForMachine >> $outputCMakeLists
    echo "set_target_properties($thePrefix$machineName  PROPERTIES OUTPUT_NAME $machineName)"
    echo  "set_target_properties($thePrefix$machineName  PROPERTIES OUTPUT_NAME $machineName)" >> $outputCMakeLists
    #
    # repeat the loop over the states for Linux additional flags
    #
    echo "Your CMakeLists.txt needs : " 'if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")'
    echo 'if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")' >> $outputCMakeLists
    lineNum=1
    stateName=$(sed -n "${lineNum}p" $machineExtension/States)
    filenameForState=State_$stateName.mm
    while [ -f $machineExtension/$filenameForState ]; do
	    echo "Your CMakeLists.txt needs : set_target_properties(${machineName}_State_$stateName PROPERTIES COMPILE_FLAGS" '"-x c++ -fPIC")'
	    echo "set_target_properties(${machineName}_State_$stateName PROPERTIES COMPILE_FLAGS" '"-x c++ -fPIC")' >> $outputCMakeLists
       # update the filename or the state
       lineNum=$((lineNum+1))
       stateName=$(sed -n "${lineNum}p" $machineExtension/States)
       filenameForState=State_$stateName.mm
    done
    #
    echo "Your CMakeLists.txt needs : set_target_properties($machineName PROPERTIES COMPILE_FLAGS" '"-x c++ -fPIC")'
    echo "set_target_properties($machineName PROPERTIES COMPILE_FLAGS" '"-x c++ -fPIC")' >> $outputCMakeLists
    #
    echo "Your CMakeLists.txt needs : " 'endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")'
    echo 'endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")' >> $outputCMakeLists

    echo "## Specify libraries to link a library or executable target against" >> $outputCMakeLists
    echo "target_link_libraries($thePrefix$machineName " '${catkin_LIBRARIES})'
    echo "target_link_libraries($thePrefix$machineName " '${catkin_LIBRARIES})'  >> $outputCMakeLists

    ##########
    # Hints for installing
    echo -e "\nINSTALLING: $machineName.machine \n"
    echo "You should copy the result after a succesfull catkin_make"
    echo "You are at $(pwd)":
    if [ $UNAME_S = "Darwin" ]; then
       result="$realtive_catkin_destiantion/lib/lib$machineName.dylib"
       else
       result="$realtive_catkin_destiantion/lib/lib$machineName.so"
       fi
    echo -e "The result should be at $result\n"
    echo -e "mv $result $destination/$machineName\n"
    echo -e "And if not there, also create a linto to a .so file\n"
    echo -e "ln -f $destination/$machineName $destination/$machineName.so "
    echo -e "\nRUNNING: $machineName.machine \n"
    echo -e "$realtive_catkin_destiantion/lib/clfsm/clfsm $realtive_catkin_destiantion/lib/$machineName.machine \n"
    #
else
       echo "Machine not found! Run this script in teh same directory wherw <machineName>.machine is "
fi
