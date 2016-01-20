//
// State_Stop.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckCourseLegByGSM_Includes.h"
#include "epuckCourseLegByGSM.h"
#include "State_Stop.h"

#include "State_Stop_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckCourseLegByGSM;
using namespace State;

Stop::Stop(const char *name): CLState(name, *new Stop::OnEntry, *new Stop::OnExit, *new Stop::Internal)
{
	_transitions[0] = new Transition_0();
}

Stop::~Stop()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Stop::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCourseLegByGSM_VarRefs.mm"
#	include "State_Stop_VarRefs.mm"
#	include "State_Stop_OnEntry.mm"
}

void Stop::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCourseLegByGSM_VarRefs.mm"
#	include "State_Stop_VarRefs.mm"
#	include "State_Stop_OnExit.mm"
}

void Stop::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCourseLegByGSM_VarRefs.mm"
#	include "State_Stop_VarRefs.mm"
#	include "State_Stop_Internal.mm"
}

bool Stop::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckCourseLegByGSM_VarRefs.mm"
#	include "State_Stop_VarRefs.mm"

	return
	(
#		include "State_Stop_Transition_0.expr"
	);
}
