//
// State_VeeringLeft.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckFollowLineByGSM_State_VeeringLeft_h
#define clfsm_epuckFollowLineByGSM_State_VeeringLeft_h

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMepuckFollowLineByGSM
      {
        namespace State
        {
            class VeeringLeft: public CLState
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
                    Transition_0(int toState = 3): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                class Transition_1: public CLTransition
                {
                public:
                    Transition_1(int toState = 2): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[2];

                public:
                    VeeringLeft(const char *name = "VeeringLeft");
                    virtual ~VeeringLeft();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 2; }

#                   include "State_VeeringLeft_Variables.h"
            };
        }
      }
    }
}

#endif
