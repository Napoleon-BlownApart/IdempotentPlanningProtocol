//
// State_Wait_4_Scan.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckCourseLegByGSM_State_Wait_4_Scan_h
#define clfsm_epuckCourseLegByGSM_State_Wait_4_Scan_h

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
            class Wait_4_Scan: public CLState
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
                    Wait_4_Scan(const char *name = "Wait_4_Scan");
                    virtual ~Wait_4_Scan();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_Wait_4_Scan_Variables.h"
            };
        }
      }
    }
}

#endif
