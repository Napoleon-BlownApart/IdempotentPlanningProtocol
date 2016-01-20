//
// epuckCoordinatesByGSM.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_machine_epuckCoordinatesByGSM_
#define clfsm_machine_epuckCoordinatesByGSM_

#include "CLMachine.h"

namespace FSM
{
    class CLState;

    namespace CLM
    {
        class epuckCoordinatesByGSM: public CLMachine
        {
            CLState *_states[13];
        public:
            epuckCoordinatesByGSM(int mid  = 0, const char *name = "epuckCoordinatesByGSM");
            virtual ~epuckCoordinatesByGSM();
            virtual CLState * const * states() const { return _states; }
            virtual int numberOfStates() const { return 13; }
#           include "epuckCoordinatesByGSM_Variables.h"
        };
    }
}

extern "C"
{
    FSM::CLM::epuckCoordinatesByGSM *CLM_Create_epuckCoordinatesByGSM(int mid, const char *name);
}

#endif // defined(clfsm_machine_epuckCoordinatesByGSM_)
