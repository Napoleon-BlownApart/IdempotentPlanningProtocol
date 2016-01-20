//
// State_Not_Detected_Intersection.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckCoordinatesByGSM_Includes.h"
#include "epuckCoordinatesByGSM.h"
#include "State_Not_Detected_Intersection.h"

#include "State_Not_Detected_Intersection_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckCoordinatesByGSM;
using namespace State;

Not_Detected_Intersection::Not_Detected_Intersection(const char *name): CLState(name, *new Not_Detected_Intersection::OnEntry, *new Not_Detected_Intersection::OnExit, *new Not_Detected_Intersection::Internal)
{
	_transitions[0] = new Transition_0();
}

Not_Detected_Intersection::~Not_Detected_Intersection()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Not_Detected_Intersection::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Not_Detected_Intersection_VarRefs.mm"
#	include "State_Not_Detected_Intersection_OnEntry.mm"
}

void Not_Detected_Intersection::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Not_Detected_Intersection_VarRefs.mm"
#	include "State_Not_Detected_Intersection_OnExit.mm"
}

void Not_Detected_Intersection::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Not_Detected_Intersection_VarRefs.mm"
#	include "State_Not_Detected_Intersection_Internal.mm"
}

bool Not_Detected_Intersection::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCoordinatesByGSM_VarRefs.mm"
#	include "State_Not_Detected_Intersection_VarRefs.mm"

	return
	(
#		include "State_Not_Detected_Intersection_Transition_0.expr"
	);
}
