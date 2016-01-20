//
// State_CentreGS_Detects_Intersection.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckNavigateGridByGSM_State_CentreGS_Detects_Intersection_h
#define clfsm_epuckNavigateGridByGSM_State_CentreGS_Detects_Intersection_h

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMepuckNavigateGridByGSM
      {
        namespace State
        {
            class CentreGS_Detects_Intersection: public CLState
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
                    Transition_0(int toState = 25): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    CentreGS_Detects_Intersection(const char *name = "CentreGS_Detects_Intersection");
                    virtual ~CentreGS_Detects_Intersection();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_CentreGS_Detects_Intersection_Variables.h"
            };
        }
      }
    }
}

#endif
