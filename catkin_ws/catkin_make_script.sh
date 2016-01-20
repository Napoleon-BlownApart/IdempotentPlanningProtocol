#!/bin/bash
# call using:
# $1 = "catkin" or "catkin_make"
# $2 = working directory (ie path to your Catkin Workspace)
# $3 = Build Target Name
# $4 = Build Type = None/Debug/Release/RelWithDebInfo/MinSizeRel (Compiler dependent, but ok with GCC)
cd $2
source devel/setup.bash >& /dev/null
case $1 in
catkin_make)
    if [[ $5 == "Quick" ]]; then
      echo "QUICK MODE"
      which catkin_make
      catkin_make #-DCMAKE_BUILD_TYPE=$4 #-DCMAKE_CXX_FLAGS_DEBUG="-pg" -DCMAKE_C_FLAGS_DEBUG="-pg" # -DCMAKE_EXE_LINKER_FLAGS_Debug="-pg"
    else
      echo "FULL INFO MODE"
      catkin_make VERBOSE=1 -DCMAKE_BUILD_TYPE=$4 -DCMAKE_CXX_FLAGS_DEBUG="-pg" -DCMAKE_C_FLAGS_DEBUG="-pg" -DCMAKE_EXE_LINKER_FLAGS_Debug="-v -pg"
    fi
    ;;
catkin)
    targetpath=${3#/}
    echo $targetpath
    target=$(basename "$targetpath")
    target="${target%.*}"
    target="${target,,}"
    echo "catkin build target is: " $target
    catkin build $target --cmake-args -DCMAKE_BUILD_TYPE=$4
    ;;
esac

# CMAKE_EXE_LINKER_FLAGS_Debug="-v -g"
:<<'COMMENTS_ABOUT_DEBUG_SWITCHES'
-p
    Generate extra code to write profile information suitable for the analysis program prof. You must use this option when compiling the source files you want data about, and you must also use it when linking.


-pg
    Generate extra code to write profile information suitable for the analysis program gprof. You must use this option when compiling the source files you want data about, and you must also use it when linking. 
COMMENTS_ABOUT_DEBUG_SWITCHES




# # -DCMAKE_BUILD_TYPE=Debug CMAKE_EXE_LINKER_FLAGS_Debug="-v -g"
# # -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++   
# #if [[ $? != 0 ]]; then
# #	read -p "Error occurred.\n Press any key to continue... " -n1 -s
# #fi

#
