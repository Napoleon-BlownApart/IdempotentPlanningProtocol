//
// State_May_Need_Align_In_Intersection.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckMeanderLinesByGSM_State_May_Need_Align_In_Intersection_h
#define clfsm_epuckMeanderLinesByGSM_State_May_Need_Align_In_Intersection_h

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
            class May_Need_Align_In_Intersection: public CLState
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
                    Transition_0(int toState = 18): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                class Transition_1: public CLTransition
                {
                public:
                    Transition_1(int toState = 29): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[2];

                public:
                    May_Need_Align_In_Intersection(const char *name = "May_Need_Align_In_Intersection");
                    virtual ~May_Need_Align_In_Intersection();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 2; }

#                   include "State_May_Need_Align_In_Intersection_Variables.h"
            };
        }
      }
    }
}

#endif
