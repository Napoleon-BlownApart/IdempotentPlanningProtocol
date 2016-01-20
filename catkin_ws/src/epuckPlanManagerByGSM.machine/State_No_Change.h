//
// State_No_Change.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckPlanManagerByGSM_State_No_Change_h
#define clfsm_epuckPlanManagerByGSM_State_No_Change_h

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
            class No_Change: public CLState
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
                    No_Change(const char *name = "No_Change");
                    virtual ~No_Change();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_No_Change_Variables.h"
            };
        }
      }
    }
}

#endif
