//
// State_Add_Next_Obstacle.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckPlanManagerByGSM_State_Add_Next_Obstacle_h
#define clfsm_epuckPlanManagerByGSM_State_Add_Next_Obstacle_h

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
            class Add_Next_Obstacle: public CLState
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
                    Add_Next_Obstacle(const char *name = "Add_Next_Obstacle");
                    virtual ~Add_Next_Obstacle();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_Add_Next_Obstacle_Variables.h"
            };
        }
      }
    }
}

#endif
