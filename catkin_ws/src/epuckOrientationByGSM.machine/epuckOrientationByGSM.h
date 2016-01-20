//
// epuckOrientationByGSM.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_machine_epuckOrientationByGSM_
#define clfsm_machine_epuckOrientationByGSM_

#include "CLMachine.h"

namespace FSM
{
    class CLState;

    namespace CLM
    {
        class epuckOrientationByGSM: public CLMachine
        {
            CLState *_states[10];
        public:
            epuckOrientationByGSM(int mid  = 0, const char *name = "epuckOrientationByGSM");
            virtual ~epuckOrientationByGSM();
            virtual CLState * const * states() const { return _states; }
            virtual int numberOfStates() const { return 10; }
#           include "epuckOrientationByGSM_Variables.h"
        };
    }
}

extern "C"
{
    FSM::CLM::epuckOrientationByGSM *CLM_Create_epuckOrientationByGSM(int mid, const char *name);
}

#endif // defined(clfsm_machine_epuckOrientationByGSM_)
