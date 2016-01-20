//
// epuckNavigateGridByGSM.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef __clfsm__epuckNavigateGridByGSM__
#define __clfsm__epuckNavigateGridByGSM__

#include "CLMachine.h"

namespace FSM
{
    class CLState;

    namespace CLM
    {
        class epuckNavigateGridByGSM: public CLMachine
        {
            CLState *_states[42];
        public:
            epuckNavigateGridByGSM(int mid  = 0, const char *name = "epuckNavigateGridByGSM");
            virtual ~epuckNavigateGridByGSM();
            virtual CLState * const * states() const { return _states; }
            virtual int numberOfStates() const { return 42; }
#           include "epuckNavigateGridByGSM_Variables.h"
        };
    }
}

extern "C"
{
    FSM::CLM::epuckNavigateGridByGSM *CLM_Create_epuckNavigateGridByGSM(int mid, const char *name);
}

#endif // defined(__gufsm__epuckNavigateGridByGSM__)
