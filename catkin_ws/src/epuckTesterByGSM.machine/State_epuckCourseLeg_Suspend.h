//
// State_epuckCourseLeg_Suspend.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckTesterByGSM_State_epuckCourseLeg_Suspend_h
#define clfsm_epuckTesterByGSM_State_epuckCourseLeg_Suspend_h

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
            class epuckCourseLeg_Suspend: public CLState
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
                    Transition_0(int toState = 30): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    epuckCourseLeg_Suspend(const char *name = "epuckCourseLeg_Suspend");
                    virtual ~epuckCourseLeg_Suspend();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_epuckCourseLeg_Suspend_Variables.h"
            };
        }
      }
    }
}

#endif
