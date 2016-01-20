//
// epuckTesterByGSM.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_machine_epuckTesterByGSM_
#define clfsm_machine_epuckTesterByGSM_

#include "CLMachine.h"

namespace FSM
{
    class CLState;

    namespace CLM
    {
        class epuckTesterByGSM: public CLMachine
        {
            CLState *_states[34];
        public:
            epuckTesterByGSM(int mid  = 0, const char *name = "epuckTesterByGSM");
            virtual ~epuckTesterByGSM();
            virtual CLState * const * states() const { return _states; }
            virtual int numberOfStates() const { return 34; }
#           include "epuckTesterByGSM_Variables.h"
        };
    }
}

extern "C"
{
    FSM::CLM::epuckTesterByGSM *CLM_Create_epuckTesterByGSM(int mid, const char *name);
}

#endif // defined(clfsm_machine_epuckTesterByGSM_)
