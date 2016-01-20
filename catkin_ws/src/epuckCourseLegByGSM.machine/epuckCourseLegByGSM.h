//
// epuckCourseLegByGSM.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_machine_epuckCourseLegByGSM_
#define clfsm_machine_epuckCourseLegByGSM_

#include "CLMachine.h"

namespace FSM
{
    class CLState;

    namespace CLM
    {
        class epuckCourseLegByGSM: public CLMachine
        {
            CLState *_states[12];
        public:
            epuckCourseLegByGSM(int mid  = 0, const char *name = "epuckCourseLegByGSM");
            virtual ~epuckCourseLegByGSM();
            virtual CLState * const * states() const { return _states; }
            virtual int numberOfStates() const { return 12; }
#           include "epuckCourseLegByGSM_Variables.h"
        };
    }
}

extern "C"
{
    FSM::CLM::epuckCourseLegByGSM *CLM_Create_epuckCourseLegByGSM(int mid, const char *name);
}

#endif // defined(clfsm_machine_epuckCourseLegByGSM_)
