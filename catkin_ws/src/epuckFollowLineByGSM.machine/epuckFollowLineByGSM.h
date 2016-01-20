//
// epuckFollowLineByGSM.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_machine_epuckFollowLineByGSM_
#define clfsm_machine_epuckFollowLineByGSM_

#include "CLMachine.h"

namespace FSM
{
    class CLState;

    namespace CLM
    {
        class epuckFollowLineByGSM: public CLMachine
        {
            CLState *_states[8];
        public:
            epuckFollowLineByGSM(int mid  = 0, const char *name = "epuckFollowLineByGSM");
            virtual ~epuckFollowLineByGSM();
            virtual CLState * const * states() const { return _states; }
            virtual int numberOfStates() const { return 8; }
#           include "epuckFollowLineByGSM_Variables.h"
        };
    }
}

extern "C"
{
    FSM::CLM::epuckFollowLineByGSM *CLM_Create_epuckFollowLineByGSM(int mid, const char *name);
}

#endif // defined(clfsm_machine_epuckFollowLineByGSM_)
