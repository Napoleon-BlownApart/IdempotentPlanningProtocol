//
// State_epuckTurnAway_Resume.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckTesterByGSM_State_epuckTurnAway_Resume_h
#define clfsm_epuckTesterByGSM_State_epuckTurnAway_Resume_h

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMepuckTesterByGSM
      {
        namespace State
        {
            class epuckTurnAway_Resume: public CLState
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
                    Transition_0(int toState = 12): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    epuckTurnAway_Resume(const char *name = "epuckTurnAway_Resume");
                    virtual ~epuckTurnAway_Resume();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_epuckTurnAway_Resume_Variables.h"
            };
        }
      }
    }
}

#endif
