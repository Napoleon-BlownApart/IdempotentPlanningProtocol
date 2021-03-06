//
// State_Entering_Intersection.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckCoordinatesByGSM_Includes.h"
#include "epuckCoordinatesByGSM.h"
#include "State_Entering_Intersection.h"

#include "State_Entering_Intersection_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckCoordinatesByGSM;
using namespace State;

Entering_Intersection::Entering_Intersection(const char *name): CLState(name, *new Entering_Intersection::OnEntry, *new Entering_Intersection::OnExit, *new Entering_Intersection::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

Entering_Intersection::~Entering_Intersection()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void Entering_Intersection::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Entering_Intersection_VarRefs.mm"
#	include "State_Entering_Intersection_OnEntry.mm"
}

void Entering_Intersection::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Entering_Intersection_VarRefs.mm"
#	include "State_Entering_Intersection_OnExit.mm"
}

void Entering_Intersection::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Entering_Intersection_VarRefs.mm"
#	include "State_Entering_Intersection_Internal.mm"
}

bool Entering_Intersection::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Entering_Intersection_VarRefs.mm"

	return
	(
#		include "State_Entering_Intersection_Transition_0.expr"
	);
}

bool Entering_Intersection::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Entering_Intersection_VarRefs.mm"

	return
	(
#		include "State_Entering_Intersection_Transition_1.expr"
	);
}
