//
// State_No_Obstacles.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckTurnAwayByGSM_State_No_Obstacles_h
#define clfsm_epuckTurnAwayByGSM_State_No_Obstacles_h

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMepuckTurnAwayByGSM
      {
        namespace State
        {
            class No_Obstacles: public CLState
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
                    Transition_0(int toState = 4): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    No_Obstacles(const char *name = "No_Obstacles");
                    virtual ~No_Obstacles();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_No_Obstacles_Variables.h"
            };
        }
      }
    }
}

#endif
