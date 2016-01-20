//
// State_Is_Array_Full.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckPlanManagerByGSM_State_Is_Array_Full_h
#define clfsm_epuckPlanManagerByGSM_State_Is_Array_Full_h

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMepuckPlanManagerByGSM
      {
        namespace State
        {
            class Is_Array_Full: public CLState
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

                class Transition_1: public CLTransition
                {
                public:
                    Transition_1(int toState = 13): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[2];

                public:
                    Is_Array_Full(const char *name = "Is_Array_Full");
                    virtual ~Is_Array_Full();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 2; }

#                   include "State_Is_Array_Full_Variables.h"
            };
        }
      }
    }
}

#endif
