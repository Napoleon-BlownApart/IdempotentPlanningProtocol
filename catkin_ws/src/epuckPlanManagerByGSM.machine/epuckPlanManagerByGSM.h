//
// epuckPlanManagerByGSM.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_machine_epuckPlanManagerByGSM_
#define clfsm_machine_epuckPlanManagerByGSM_

#include "CLMachine.h"

namespace FSM
{
    class CLState;

    namespace CLM
    {
        class epuckPlanManagerByGSM: public CLMachine
        {
            CLState *_states[18];
        public:
            epuckPlanManagerByGSM(int mid  = 0, const char *name = "epuckPlanManagerByGSM");
            virtual ~epuckPlanManagerByGSM();
            virtual CLState * const * states() const { return _states; }
            virtual int numberOfStates() const { return 18; }
#           include "epuckPlanManagerByGSM_Variables.h"
        };
    }
}

extern "C"
{
    FSM::CLM::epuckPlanManagerByGSM *CLM_Create_epuckPlanManagerByGSM(int mid, const char *name);
}

#endif // defined(clfsm_machine_epuckPlanManagerByGSM_)
