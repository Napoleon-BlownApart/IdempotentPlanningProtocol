//
// epuckMeanderLinesByGSM.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef __clfsm__epuckMeanderLinesByGSM__
#define __clfsm__epuckMeanderLinesByGSM__

#include "CLMachine.h"

namespace FSM
{
    class CLState;

    namespace CLM
    {
        class epuckMeanderLinesByGSM: public CLMachine
        {
            CLState *_states[40];
        public:
            epuckMeanderLinesByGSM(int mid  = 0, const char *name = "epuckMeanderLinesByGSM");
            virtual ~epuckMeanderLinesByGSM();
            virtual CLState * const * states() const { return _states; }
            virtual int numberOfStates() const { return 40; }
#           include "epuckMeanderLinesByGSM_Variables.h"
        };
    }
}

extern "C"
{
    FSM::CLM::epuckMeanderLinesByGSM *CLM_Create_epuckMeanderLinesByGSM(int mid, const char *name);
}

#endif // defined(__gufsm__epuckMeanderLinesByGSM__)
