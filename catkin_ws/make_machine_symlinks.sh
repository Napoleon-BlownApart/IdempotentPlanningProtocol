#!/bin/bash

declare -a machines=(
                        epuckTesterByGSM.machine
                        epuckFollowLineByGSM.machine
                        epuckIntersectionByGSM.machine
                        epuckChooseDirectionByGSM.machine
                        epuckTurnByGSM.machine
                        epuckTurnAwayByGSM.machine
                        epuckObstacleOnPathByGSM.machine
                        epuckOrientationByGSM.machine
                        epuckCoordinatesByGSM.machine
                        epuckCourseLegByGSM.machine
                        epuckPlanManagerByGSM.machine
                     );
currpath=`pwd`
lencurrpath=${#currpath}
for machine in "${machines[@]}"; do
  machinename="${machine%.*}"
  # Test if shared library exists for the machine
  if [ ! -e ""devel/lib/lib${machinename}.so"" ]; then
      echo -en "ERROR:: Shared Library MISSING for $machinename;\n"
      echo -en "\t\tHave you built this machine?\n"
  else
  # Test if a link already exists inside the machine and is correct.
    if [ -e "src/$machine/Linux-x86_64/${machinename}.so" ]; then
#      echo -en "File exists for $machine\n"
      # Test if file is a symlink
      if [ ! -L "src/$machine/Linux-x86_64/${machinename}.so" ]; then
        #  -h also tests for a symlink.
        echo -en "ERROR:: $currpath/src/$machine/Linux-x86_64/$machinename.so IS NOT A SYMLINK;\n"
        echo -en "\t\tProbably need to delete it and run this script again.\n"
        echo -en "\t\tSymlink needs to point to $currpath/devel/lib/lib${machinename}.so\n"
      else
        # It is a symlink, so test if it points to the right place.
        linklocation=`readlink -f src/$machine/Linux-x86_64/${machinename}.so`
#        echo -en "$linklocation\n"
        target=${linklocation:lencurrpath}
#        echo -en  "$target\n"
        if [ ! $target = "/devel/lib/lib${machinename}.so" ]; then
          echo -en  "ERROR:: Symlink $currpath/src/$machine/Linux-x86_64/${machinename}.so pointing to the wrong file;\n"
          echo -en  "\t\tShould be pointing to: $currpath/devel/lib/lib${machinename}.so\n"
          echo -en  "\t\tBut is pointing to   : $linklocation\n"
#        else
#          echo -en  "Symlink points to correct file.\n"
        fi
      fi
    elif readlink -q src/$machine/Linux-x86_64/${machinename}.so >/dev/null ; then
        echo -en "ERROR:: SYMLINK $currpath/src/$machine/Linux-x86_64/${machinename}.so is broken;\n"
        echo -en "\t\tPlease delete and run this script again.\n"
    else
      echo -en "Creating symlink for $machine\n"
      echo -en "\tln -s $currpath/devel/lib/lib${machinename}.so src/$machine/Linux-x86_64/${machinename}.so >& /dev/null\n"
      ln -s $currpath/devel/lib/lib${machinename}.so src/$machine/Linux-x86_64/${machinename}.so >& /dev/null
    fi
  fi
done

