//
// State_epuckIntersection.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckIntersection.h"

#include "State_epuckIntersection_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckIntersection::epuckIntersection(const char *name): CLState(name, *new epuckIntersection::OnEntry, *new epuckIntersection::OnExit, *new epuckIntersection::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

epuckIntersection::~epuckIntersection()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void epuckIntersection::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckIntersection_VarRefs.mm"
#	include "State_epuckIntersection_OnEntry.mm"
}

void epuckIntersection::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckIntersection_VarRefs.mm"
#	include "State_epuckIntersection_OnExit.mm"
}

void epuckIntersection::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckIntersection_VarRefs.mm"
#	include "State_epuckIntersection_Internal.mm"
}

bool epuckIntersection::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckIntersection_VarRefs.mm"

	return
	(
#		include "State_epuckIntersection_Transition_0.expr"
	);
}

bool epuckIntersection::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckIntersection_VarRefs.mm"

	return
	(
#		include "State_epuckIntersection_Transition_1.expr"
	);
}

bool epuckIntersection::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckIntersection_VarRefs.mm"

	return
	(
#		include "State_epuckIntersection_Transition_2.expr"
	);
}
