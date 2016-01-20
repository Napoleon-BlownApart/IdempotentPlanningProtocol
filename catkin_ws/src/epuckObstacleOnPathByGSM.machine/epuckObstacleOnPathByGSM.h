//
// epuckObstacleOnPathByGSM.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_machine_epuckObstacleOnPathByGSM_
#define clfsm_machine_epuckObstacleOnPathByGSM_

#include "CLMachine.h"

namespace FSM
{
    class CLState;

    namespace CLM
    {
        class epuckObstacleOnPathByGSM: public CLMachine
        {
            CLState *_states[9];
        public:
            epuckObstacleOnPathByGSM(int mid  = 0, const char *name = "epuckObstacleOnPathByGSM");
            virtual ~epuckObstacleOnPathByGSM();
            virtual CLState * const * states() const { return _states; }
            virtual int numberOfStates() const { return 9; }
#           include "epuckObstacleOnPathByGSM_Variables.h"
        };
    }
}

extern "C"
{
    FSM::CLM::epuckObstacleOnPathByGSM *CLM_Create_epuckObstacleOnPathByGSM(int mid, const char *name);
}

#endif // defined(clfsm_machine_epuckObstacleOnPathByGSM_)
