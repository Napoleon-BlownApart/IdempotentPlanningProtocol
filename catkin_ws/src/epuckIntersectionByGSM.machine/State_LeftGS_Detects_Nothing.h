//
// State_LeftGS_Detects_Nothing.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckIntersectionByGSM_State_LeftGS_Detects_Nothing_h
#define clfsm_epuckIntersectionByGSM_State_LeftGS_Detects_Nothing_h

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
            class LeftGS_Detects_Nothing: public CLState
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
                    Transition_0(int toState = 15): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    LeftGS_Detects_Nothing(const char *name = "LeftGS_Detects_Nothing");
                    virtual ~LeftGS_Detects_Nothing();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_LeftGS_Detects_Nothing_Variables.h"
            };
        }
      }
    }
}

#endif
