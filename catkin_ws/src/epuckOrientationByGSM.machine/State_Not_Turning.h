//
// State_Not_Turning.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckOrientationByGSM_State_Not_Turning_h
#define clfsm_epuckOrientationByGSM_State_Not_Turning_h

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMepuckOrientationByGSM
      {
        namespace State
        {
            class Not_Turning: public CLState
            {
                class OnEntry: public CLAction
                {
                    virtual void perform(CLMachine *, CLState *) const;
                };

                class OnExit: public CLAction
                {
                    virtual void perform(CLMachine *, CLState *) const;
                };

                class Internal: public CLAction
                {
                    virtual void perform(CLMachine *, CLState *) const;
                };

                class Transition_0: public CLTransition
                {
                public:
                    Transition_0(int toState = 2): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    Not_Turning(const char *name = "Not_Turning");
                    virtual ~Not_Turning();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_Not_Turning_Variables.h"
            };
        }
      }
    }
}

#endif
