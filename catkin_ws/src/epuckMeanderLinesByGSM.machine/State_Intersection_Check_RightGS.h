//
// State_Intersection_Check_RightGS.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckMeanderLinesByGSM_State_Intersection_Check_RightGS_h
#define clfsm_epuckMeanderLinesByGSM_State_Intersection_Check_RightGS_h

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
            class Intersection_Check_RightGS: public CLState
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
                    Transition_1(int toState = 16): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                class Transition_2: public CLTransition
                {
                public:
                    Transition_2(int toState = 27): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[3];

                public:
                    Intersection_Check_RightGS(const char *name = "Intersection_Check_RightGS");
                    virtual ~Intersection_Check_RightGS();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 3; }

#                   include "State_Intersection_Check_RightGS_Variables.h"
            };
        }
      }
    }
}

#endif
