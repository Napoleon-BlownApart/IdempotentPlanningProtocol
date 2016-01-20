//
// State_epuckCourseLeg.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckCourseLeg.h"

#include "State_epuckCourseLeg_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckCourseLeg::epuckCourseLeg(const char *name): CLState(name, *new epuckCourseLeg::OnEntry, *new epuckCourseLeg::OnExit, *new epuckCourseLeg::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

epuckCourseLeg::~epuckCourseLeg()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void epuckCourseLeg::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCourseLeg_VarRefs.mm"
#	include "State_epuckCourseLeg_OnEntry.mm"
}

void epuckCourseLeg::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCourseLeg_VarRefs.mm"
#	include "State_epuckCourseLeg_OnExit.mm"
}

void epuckCourseLeg::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCourseLeg_VarRefs.mm"
#	include "State_epuckCourseLeg_Internal.mm"
}

bool epuckCourseLeg::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCourseLeg_VarRefs.mm"

	return
	(
#		include "State_epuckCourseLeg_Transition_0.expr"
	);
}

bool epuckCourseLeg::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCourseLeg_VarRefs.mm"

	return
	(
#		include "State_epuckCourseLeg_Transition_1.expr"
	);
}

bool epuckCourseLeg::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckCourseLeg_VarRefs.mm"

	return
	(
#		include "State_epuckCourseLeg_Transition_2.expr"
	);
}
