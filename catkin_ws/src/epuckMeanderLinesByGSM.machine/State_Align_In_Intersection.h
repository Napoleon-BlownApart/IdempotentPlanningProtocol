//
// State_Align_In_Intersection.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckMeanderLinesByGSM_State_Align_In_Intersection_h
#define clfsm_epuckMeanderLinesByGSM_State_Align_In_Intersection_h

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMepuckMeanderLinesByGSM
      {
        namespace State
        {
            class Align_In_Intersection: public CLState
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
                    Transition_0(int toState = 29): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    Align_In_Intersection(const char *name = "Align_In_Intersection");
                    virtual ~Align_In_Intersection();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_Align_In_Intersection_Variables.h"
            };
        }
      }
    }
}

#endif
