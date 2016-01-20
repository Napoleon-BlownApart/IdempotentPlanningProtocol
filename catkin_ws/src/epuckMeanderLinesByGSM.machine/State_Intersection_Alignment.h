//
// State_Intersection_Alignment.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckMeanderLinesByGSM_State_Intersection_Alignment_h
#define clfsm_epuckMeanderLinesByGSM_State_Intersection_Alignment_h

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
            class Intersection_Alignment: public CLState
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
                    Transition_0(int toState = 17): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                class Transition_1: public CLTransition
                {
                public:
                    Transition_1(int toState = 20): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[2];

                public:
                    Intersection_Alignment(const char *name = "Intersection_Alignment");
                    virtual ~Intersection_Alignment();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 2; }

#                   include "State_Intersection_Alignment_Variables.h"
            };
        }
      }
    }
}

#endif
