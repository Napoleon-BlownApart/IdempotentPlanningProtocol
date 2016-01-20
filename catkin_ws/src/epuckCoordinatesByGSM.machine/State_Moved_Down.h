//
// State_Moved_Down.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckCoordinatesByGSM_State_Moved_Down_h
#define clfsm_epuckCoordinatesByGSM_State_Moved_Down_h

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMepuckCoordinatesByGSM
      {
        namespace State
        {
            class Moved_Down: public CLState
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
                    Moved_Down(const char *name = "Moved_Down");
                    virtual ~Moved_Down();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_Moved_Down_Variables.h"
            };
        }
      }
    }
}

#endif
