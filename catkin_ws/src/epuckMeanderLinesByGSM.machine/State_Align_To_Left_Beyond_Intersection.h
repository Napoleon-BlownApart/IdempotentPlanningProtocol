//
// State_Align_To_Left_Beyond_Intersection.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_epuckMeanderLinesByGSM_State_Align_To_Left_Beyond_Intersection_h
#define clfsm_epuckMeanderLinesByGSM_State_Align_To_Left_Beyond_Intersection_h

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMepuckMeanderLinesByGSM
      {
        namespace State
        {
            class Align_To_Left_Beyond_Intersection: public CLState
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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wzero-length-array"
                CLTransition *_transitions[0];

                public:
                    Align_To_Left_Beyond_Intersection(const char *name = "Align_To_Left_Beyond_Intersection");
                    virtual ~Align_To_Left_Beyond_Intersection();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 0; }

#                   include "State_Align_To_Left_Beyond_Intersection_Variables.h"
            };
        }
      }
    }
}

#endif
#pragma clang diagnostic pop
