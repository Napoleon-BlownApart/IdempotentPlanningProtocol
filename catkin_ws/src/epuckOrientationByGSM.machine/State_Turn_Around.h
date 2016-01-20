//
// State_Turn_Around.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckOrientationByGSM_State_Turn_Around_h
#define clfsm_epuckOrientationByGSM_State_Turn_Around_h

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
                    Transition_0(int toState = 4): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    Turn_Around(const char *name = "Turn_Around");
                    virtual ~Turn_Around();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_Turn_Around_Variables.h"
            };
        }
      }
    }
}

#endif
