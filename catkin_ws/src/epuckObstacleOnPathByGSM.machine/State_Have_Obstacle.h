//
// State_Have_Obstacle.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckObstacleOnPathByGSM_State_Have_Obstacle_h
#define clfsm_epuckObstacleOnPathByGSM_State_Have_Obstacle_h

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMepuckObstacleOnPathByGSM
      {
        namespace State
        {
            class Have_Obstacle: public CLState
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
                    Transition_0(int toState = 5): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    Have_Obstacle(const char *name = "Have_Obstacle");
                    virtual ~Have_Obstacle();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_Have_Obstacle_Variables.h"
            };
        }
      }
    }
}

#endif
