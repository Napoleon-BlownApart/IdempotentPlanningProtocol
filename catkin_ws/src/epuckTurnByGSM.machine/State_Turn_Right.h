//
// State_Turn_Right.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckTurnByGSM_State_Turn_Right_h
#define clfsm_epuckTurnByGSM_State_Turn_Right_h

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
            class Turn_Right: public CLState
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
                    Transition_0(int toState = 11): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    Turn_Right(const char *name = "Turn_Right");
                    virtual ~Turn_Right();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_Turn_Right_Variables.h"
            };
        }
      }
    }
}

#endif
