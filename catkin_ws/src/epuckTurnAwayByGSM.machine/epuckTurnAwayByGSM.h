//
// epuckTurnAwayByGSM.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_machine_epuckTurnAwayByGSM_
#define clfsm_machine_epuckTurnAwayByGSM_

#include "CLMachine.h"

namespace FSM
{
    class CLState;

    namespace CLM
    {
        class epuckTurnAwayByGSM: public CLMachine
        {
            CLState *_states[7];
        public:
            epuckTurnAwayByGSM(int mid  = 0, const char *name = "epuckTurnAwayByGSM");
            virtual ~epuckTurnAwayByGSM();
            virtual CLState * const * states() const { return _states; }
            virtual int numberOfStates() const { return 7; }
#           include "epuckTurnAwayByGSM_Variables.h"
        };
    }
}

extern "C"
{
    FSM::CLM::epuckTurnAwayByGSM *CLM_Create_epuckTurnAwayByGSM(int mid, const char *name);
}

#endif // defined(clfsm_machine_epuckTurnAwayByGSM_)
