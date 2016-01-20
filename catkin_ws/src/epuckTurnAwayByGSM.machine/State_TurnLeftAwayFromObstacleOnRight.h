//
// State_TurnLeftAwayFromObstacleOnRight.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckTurnAwayByGSM_State_TurnLeftAwayFromObstacleOnRight_h
#define clfsm_epuckTurnAwayByGSM_State_TurnLeftAwayFromObstacleOnRight_h

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
            class TurnLeftAwayFromObstacleOnRight: public CLState
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
                    TurnLeftAwayFromObstacleOnRight(const char *name = "TurnLeftAwayFromObstacleOnRight");
                    virtual ~TurnLeftAwayFromObstacleOnRight();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_TurnLeftAwayFromObstacleOnRight_Variables.h"
            };
        }
      }
    }
}

#endif
