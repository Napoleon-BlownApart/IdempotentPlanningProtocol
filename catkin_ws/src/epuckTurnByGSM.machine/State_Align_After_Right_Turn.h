//
// State_Align_After_Right_Turn.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckTurnByGSM_State_Align_After_Right_Turn_h
#define clfsm_epuckTurnByGSM_State_Align_After_Right_Turn_h

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
            class Align_After_Right_Turn: public CLState
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
                    Transition_0(int toState = 10): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                class Transition_1: public CLTransition
                {
                public:
                    Transition_1(int toState = 12): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[2];

                public:
                    Align_After_Right_Turn(const char *name = "Align_After_Right_Turn");
                    virtual ~Align_After_Right_Turn();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 2; }

#                   include "State_Align_After_Right_Turn_Variables.h"
            };
        }
      }
    }
}

#endif
