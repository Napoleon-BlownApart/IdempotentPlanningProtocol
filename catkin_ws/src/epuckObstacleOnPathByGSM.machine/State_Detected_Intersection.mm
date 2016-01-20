//
// State_Detected_Intersection.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckObstacleOnPathByGSM_Includes.h"
#include "epuckObstacleOnPathByGSM.h"
#include "State_Detected_Intersection.h"

#include "State_Detected_Intersection_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckObstacleOnPathByGSM;
using namespace State;

Detected_Intersection::Detected_Intersection(const char *name): CLState(name, *new Detected_Intersection::OnEntry, *new Detected_Intersection::OnExit, *new Detected_Intersection::Internal)
{
	_transitions[0] = new Transition_0();
}

Detected_Intersection::~Detected_Intersection()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Detected_Intersection::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Detected_Intersection_VarRefs.mm"
#	include "State_Detected_Intersection_OnEntry.mm"
}

void Detected_Intersection::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Detected_Intersection_VarRefs.mm"
#	include "State_Detected_Intersection_OnExit.mm"
}

void Detected_Intersection::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Detected_Intersection_VarRefs.mm"
#	include "State_Detected_Intersection_Internal.mm"
}

bool Detected_Intersection::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Detected_Intersection_VarRefs.mm"

	return
	(
#		include "State_Detected_Intersection_Transition_0.expr"
	);
}
