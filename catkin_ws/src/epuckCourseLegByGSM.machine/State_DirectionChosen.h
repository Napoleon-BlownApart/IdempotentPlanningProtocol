//
// State_DirectionChosen.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckCourseLegByGSM_State_DirectionChosen_h
#define clfsm_epuckCourseLegByGSM_State_DirectionChosen_h

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
            class DirectionChosen: public CLState
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
                    Transition_0(int toState = 9): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    DirectionChosen(const char *name = "DirectionChosen");
                    virtual ~DirectionChosen();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_DirectionChosen_Variables.h"
            };
        }
      }
    }
}

#endif
