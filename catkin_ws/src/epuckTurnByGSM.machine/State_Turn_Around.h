//
// State_Turn_Around.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckTurnByGSM_State_Turn_Around_h
#define clfsm_epuckTurnByGSM_State_Turn_Around_h

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMepuckTurnByGSM
      {
        namespace State
        {
            class Turn_Around: public CLState
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

                class Transition_1: public CLTransition
                {
                public:
                    Transition_1(int toState = 3): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[2];

                public:
                    Turn_Around(const char *name = "Turn_Around");
                    virtual ~Turn_Around();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 2; }

#                   include "State_Turn_Around_Variables.h"
            };
        }
      }
    }
}

#endif
