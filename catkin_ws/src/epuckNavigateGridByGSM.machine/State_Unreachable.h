//
// State_Unreachable.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckNavigateGridByGSM_State_Unreachable_h
#define clfsm_epuckNavigateGridByGSM_State_Unreachable_h

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
            class Unreachable: public CLState
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
                    Transition_0(int toState = 7): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    Unreachable(const char *name = "Unreachable");
                    virtual ~Unreachable();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_Unreachable_Variables.h"
            };
        }
      }
    }
}

#endif
