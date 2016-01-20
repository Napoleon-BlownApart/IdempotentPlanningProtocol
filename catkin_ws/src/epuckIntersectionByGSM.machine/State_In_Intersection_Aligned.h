//
// State_In_Intersection_Aligned.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckIntersectionByGSM_State_In_Intersection_Aligned_h
#define clfsm_epuckIntersectionByGSM_State_In_Intersection_Aligned_h

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
            class In_Intersection_Aligned: public CLState
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

                CLTransition *_transitions[1];

                public:
                    In_Intersection_Aligned(const char *name = "In_Intersection_Aligned");
                    virtual ~In_Intersection_Aligned();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_In_Intersection_Aligned_Variables.h"
            };
        }
      }
    }
}

#endif
