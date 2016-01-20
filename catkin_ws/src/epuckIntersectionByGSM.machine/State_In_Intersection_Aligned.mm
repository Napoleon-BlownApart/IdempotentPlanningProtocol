//
// State_In_Intersection_Aligned.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckIntersectionByGSM_Includes.h"
#include "epuckIntersectionByGSM.h"
#include "State_In_Intersection_Aligned.h"

#include "State_In_Intersection_Aligned_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckIntersectionByGSM;
using namespace State;

In_Intersection_Aligned::In_Intersection_Aligned(const char *name): CLState(name, *new In_Intersection_Aligned::OnEntry, *new In_Intersection_Aligned::OnExit, *new In_Intersection_Aligned::Internal)
{
	_transitions[0] = new Transition_0();
}

In_Intersection_Aligned::~In_Intersection_Aligned()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void In_Intersection_Aligned::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_In_Intersection_Aligned_VarRefs.mm"
#	include "State_In_Intersection_Aligned_OnEntry.mm"
}

void In_Intersection_Aligned::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_In_Intersection_Aligned_VarRefs.mm"
#	include "State_In_Intersection_Aligned_OnExit.mm"
}

void In_Intersection_Aligned::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_In_Intersection_Aligned_VarRefs.mm"
#	include "State_In_Intersection_Aligned_Internal.mm"
}

bool In_Intersection_Aligned::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_In_Intersection_Aligned_VarRefs.mm"

	return
	(
#		include "State_In_Intersection_Aligned_Transition_0.expr"
	);
}
