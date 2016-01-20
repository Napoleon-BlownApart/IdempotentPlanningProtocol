//
// epuckIntersectionByGSM.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_machine_epuckIntersectionByGSM_
#define clfsm_machine_epuckIntersectionByGSM_

#include "CLMachine.h"

namespace FSM
{
    class CLState;

    namespace CLM
    {
        class epuckIntersectionByGSM: public CLMachine
        {
            CLState *_states[31];
        public:
            epuckIntersectionByGSM(int mid  = 0, const char *name = "epuckIntersectionByGSM");
            virtual ~epuckIntersectionByGSM();
            virtual CLState * const * states() const { return _states; }
            virtual int numberOfStates() const { return 31; }
#           include "epuckIntersectionByGSM_Variables.h"
        };
    }
}

extern "C"
{
    FSM::CLM::epuckIntersectionByGSM *CLM_Create_epuckIntersectionByGSM(int mid, const char *name);
}

#endif // defined(clfsm_machine_epuckIntersectionByGSM_)
