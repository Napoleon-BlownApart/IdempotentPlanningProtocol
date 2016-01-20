//
// State_LeftGS_Detects_Intersection.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckIntersectionByGSM_Includes.h"
#include "epuckIntersectionByGSM.h"
#include "State_LeftGS_Detects_Intersection.h"

#include "State_LeftGS_Detects_Intersection_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckIntersectionByGSM;
using namespace State;

LeftGS_Detects_Intersection::LeftGS_Detects_Intersection(const char *name): CLState(name, *new LeftGS_Detects_Intersection::OnEntry, *new LeftGS_Detects_Intersection::OnExit, *new LeftGS_Detects_Intersection::Internal)
{
	_transitions[0] = new Transition_0();
}

LeftGS_Detects_Intersection::~LeftGS_Detects_Intersection()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void LeftGS_Detects_Intersection::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_LeftGS_Detects_Intersection_VarRefs.mm"
#	include "State_LeftGS_Detects_Intersection_OnEntry.mm"
}

void LeftGS_Detects_Intersection::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_LeftGS_Detects_Intersection_VarRefs.mm"
#	include "State_LeftGS_Detects_Intersection_OnExit.mm"
}

void LeftGS_Detects_Intersection::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_LeftGS_Detects_Intersection_VarRefs.mm"
#	include "State_LeftGS_Detects_Intersection_Internal.mm"
}

bool LeftGS_Detects_Intersection::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckIntersectionByGSM_VarRefs.mm"
#	include "State_LeftGS_Detects_Intersection_VarRefs.mm"

	return
	(
#		include "State_LeftGS_Detects_Intersection_Transition_0.expr"
	);
}
