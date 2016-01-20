//
// State_epuckOrientation.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckOrientation.h"

#include "State_epuckOrientation_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckOrientation::epuckOrientation(const char *name): CLState(name, *new epuckOrientation::OnEntry, *new epuckOrientation::OnExit, *new epuckOrientation::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

epuckOrientation::~epuckOrientation()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void epuckOrientation::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckOrientation_VarRefs.mm"
#	include "State_epuckOrientation_OnEntry.mm"
}

void epuckOrientation::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckOrientation_VarRefs.mm"
#	include "State_epuckOrientation_OnExit.mm"
}

void epuckOrientation::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckOrientation_VarRefs.mm"
#	include "State_epuckOrientation_Internal.mm"
}

bool epuckOrientation::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckOrientation_VarRefs.mm"

	return
	(
#		include "State_epuckOrientation_Transition_0.expr"
	);
}

bool epuckOrientation::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckOrientation_VarRefs.mm"

	return
	(
#		include "State_epuckOrientation_Transition_1.expr"
	);
}

bool epuckOrientation::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckOrientation_VarRefs.mm"

	return
	(
#		include "State_epuckOrientation_Transition_2.expr"
	);
}
