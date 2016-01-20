//
// State_Observe_Intersection.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckObstacleOnPathByGSM_Includes.h"
#include "epuckObstacleOnPathByGSM.h"
#include "State_Observe_Intersection.h"

#include "State_Observe_Intersection_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckObstacleOnPathByGSM;
using namespace State;

Observe_Intersection::Observe_Intersection(const char *name): CLState(name, *new Observe_Intersection::OnEntry, *new Observe_Intersection::OnExit, *new Observe_Intersection::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

Observe_Intersection::~Observe_Intersection()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void Observe_Intersection::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Observe_Intersection_VarRefs.mm"
#	include "State_Observe_Intersection_OnEntry.mm"
}

void Observe_Intersection::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Observe_Intersection_VarRefs.mm"
#	include "State_Observe_Intersection_OnExit.mm"
}

void Observe_Intersection::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Observe_Intersection_VarRefs.mm"
#	include "State_Observe_Intersection_Internal.mm"
}

bool Observe_Intersection::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Observe_Intersection_VarRefs.mm"

	return
	(
#		include "State_Observe_Intersection_Transition_0.expr"
	);
}

bool Observe_Intersection::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Observe_Intersection_VarRefs.mm"

	return
	(
#		include "State_Observe_Intersection_Transition_1.expr"
	);
}

bool Observe_Intersection::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Observe_Intersection_VarRefs.mm"

	return
	(
#		include "State_Observe_Intersection_Transition_2.expr"
	);
}
