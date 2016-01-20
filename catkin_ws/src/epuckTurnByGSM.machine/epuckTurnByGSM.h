//
// epuckTurnByGSM.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_machine_epuckTurnByGSM_
#define clfsm_machine_epuckTurnByGSM_

#include "CLMachine.h"

namespace FSM
{
    class CLState;

    namespace CLM
    {
        class epuckTurnByGSM: public CLMachine
        {
            CLState *_states[14];
        public:
            epuckTurnByGSM(int mid  = 0, const char *name = "epuckTurnByGSM");
            virtual ~epuckTurnByGSM();
            virtual CLState * const * states() const { return _states; }
            virtual int numberOfStates() const { return 14; }
#           include "epuckTurnByGSM_Variables.h"
        };
    }
}

extern "C"
{
    FSM::CLM::epuckTurnByGSM *CLM_Create_epuckTurnByGSM(int mid, const char *name);
}

#endif // defined(clfsm_machine_epuckTurnByGSM_)
