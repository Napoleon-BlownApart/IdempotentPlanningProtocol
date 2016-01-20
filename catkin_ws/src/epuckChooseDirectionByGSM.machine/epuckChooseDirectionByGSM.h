//
// epuckChooseDirectionByGSM.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_machine_epuckChooseDirectionByGSM_
#define clfsm_machine_epuckChooseDirectionByGSM_

#include "CLMachine.h"

namespace FSM
{
    class CLState;

    namespace CLM
    {
        class epuckChooseDirectionByGSM: public CLMachine
        {
            CLState *_states[7];
        public:
            epuckChooseDirectionByGSM(int mid  = 0, const char *name = "epuckChooseDirectionByGSM");
            virtual ~epuckChooseDirectionByGSM();
            virtual CLState * const * states() const { return _states; }
            virtual int numberOfStates() const { return 7; }
#           include "epuckChooseDirectionByGSM_Variables.h"
        };
    }
}

extern "C"
{
    FSM::CLM::epuckChooseDirectionByGSM *CLM_Create_epuckChooseDirectionByGSM(int mid, const char *name);
}

#endif // defined(clfsm_machine_epuckChooseDirectionByGSM_)
