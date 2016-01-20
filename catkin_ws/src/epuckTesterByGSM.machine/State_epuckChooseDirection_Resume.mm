//
// State_epuckChooseDirection_Resume.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckChooseDirection_Resume.h"

#include "State_epuckChooseDirection_Resume_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckChooseDirection_Resume::epuckChooseDirection_Resume(const char *name): CLState(name, *new epuckChooseDirection_Resume::OnEntry, *new epuckChooseDirection_Resume::OnExit, *new epuckChooseDirection_Resume::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckChooseDirection_Resume::~epuckChooseDirection_Resume()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckChooseDirection_Resume::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckChooseDirection_Resume_VarRefs.mm"
#	include "State_epuckChooseDirection_Resume_OnEntry.mm"
}

void epuckChooseDirection_Resume::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckChooseDirection_Resume_VarRefs.mm"
#	include "State_epuckChooseDirection_Resume_OnExit.mm"
}

void epuckChooseDirection_Resume::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckChooseDirection_Resume_VarRefs.mm"
#	include "State_epuckChooseDirection_Resume_Internal.mm"
}

bool epuckChooseDirection_Resume::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckChooseDirection_Resume_VarRefs.mm"

	return
	(
#		include "State_epuckChooseDirection_Resume_Transition_0.expr"
	);
}
