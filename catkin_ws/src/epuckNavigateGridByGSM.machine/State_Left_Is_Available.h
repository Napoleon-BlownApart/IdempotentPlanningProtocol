//
// State_Left_Is_Available.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckNavigateGridByGSM_State_Left_Is_Available_h
#define clfsm_epuckNavigateGridByGSM_State_Left_Is_Available_h

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMepuckNavigateGridByGSM
      {
        namespace State
        {
            class Left_Is_Available: public CLState
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
                    Transition_0(int toState = 31): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    Left_Is_Available(const char *name = "Left_Is_Available");
                    virtual ~Left_Is_Available();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_Left_Is_Available_Variables.h"
            };
        }
      }
    }
}

#endif
