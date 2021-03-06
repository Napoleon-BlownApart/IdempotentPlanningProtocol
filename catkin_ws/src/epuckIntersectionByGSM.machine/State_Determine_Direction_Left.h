//
// State_Determine_Direction_Left.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckIntersectionByGSM_State_Determine_Direction_Left_h
#define clfsm_epuckIntersectionByGSM_State_Determine_Direction_Left_h

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
            class Determine_Direction_Left: public CLState
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
                    Transition_0(int toState = 22): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                class Transition_1: public CLTransition
                {
                public:
                    Transition_1(int toState = 23): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[2];

                public:
                    Determine_Direction_Left(const char *name = "Determine_Direction_Left");
                    virtual ~Determine_Direction_Left();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 2; }

#                   include "State_Determine_Direction_Left_Variables.h"
            };
        }
      }
    }
}

#endif
