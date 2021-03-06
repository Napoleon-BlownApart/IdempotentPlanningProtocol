//
// State_At_Goal.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckCourseLegByGSM_State_At_Goal_h
#define clfsm_epuckCourseLegByGSM_State_At_Goal_h

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMepuckCourseLegByGSM
      {
        namespace State
        {
            class At_Goal: public CLState
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
                    At_Goal(const char *name = "At_Goal");
                    virtual ~At_Goal();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_At_Goal_Variables.h"
            };
        }
      }
    }
}

#endif
