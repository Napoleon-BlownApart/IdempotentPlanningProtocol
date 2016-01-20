//
// State_RightGS_Detects_Nothing.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckIntersectionByGSM_State_RightGS_Detects_Nothing_h
#define clfsm_epuckIntersectionByGSM_State_RightGS_Detects_Nothing_h

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMepuckIntersectionByGSM
      {
        namespace State
        {
            class RightGS_Detects_Nothing: public CLState
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
                    Transition_0(int toState = 19): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    RightGS_Detects_Nothing(const char *name = "RightGS_Detects_Nothing");
                    virtual ~RightGS_Detects_Nothing();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_RightGS_Detects_Nothing_Variables.h"
            };
        }
      }
    }
}

#endif
