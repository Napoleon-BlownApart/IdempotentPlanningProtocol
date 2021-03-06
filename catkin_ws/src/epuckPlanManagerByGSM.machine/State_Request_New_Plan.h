//
// State_Request_New_Plan.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckPlanManagerByGSM_State_Request_New_Plan_h
#define clfsm_epuckPlanManagerByGSM_State_Request_New_Plan_h

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
            class Request_New_Plan: public CLState
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
                    Request_New_Plan(const char *name = "Request_New_Plan");
                    virtual ~Request_New_Plan();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_Request_New_Plan_Variables.h"
            };
        }
      }
    }
}

#endif
