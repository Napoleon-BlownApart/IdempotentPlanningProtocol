//
// State_Continue_Align_Right.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckMeanderLinesByGSM_State_Continue_Align_Right_h
#define clfsm_epuckMeanderLinesByGSM_State_Continue_Align_Right_h

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMepuckMeanderLinesByGSM
      {
        namespace State
        {
            class Continue_Align_Right: public CLState
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
                    Transition_0(int toState = 38): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    Continue_Align_Right(const char *name = "Continue_Align_Right");
                    virtual ~Continue_Align_Right();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_Continue_Align_Right_Variables.h"
            };
        }
      }
    }
}

#endif
