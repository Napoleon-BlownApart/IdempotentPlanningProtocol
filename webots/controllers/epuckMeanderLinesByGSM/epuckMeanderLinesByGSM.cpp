// This is the main program of your controller.
// It creates an instance of your Robot subclass, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node

#include "epuckMeanderLinesByGSM_Behaviour.h"

int main(int argc, char **argv)
{
  epuckMeanderLinesByGSM_Behaviour* controller = new epuckMeanderLinesByGSM_Behaviour();
  controller->run();
  delete controller;
  return 0;
}


