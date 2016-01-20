//
// State_ChooseDirection.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckChooseDirectionByGSM_Includes.h"
#include "epuckChooseDirectionByGSM.h"
#include "State_ChooseDirection.h"

#include "State_ChooseDirection_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckChooseDirectionByGSM;
using namespace State;

ChooseDirection::ChooseDirection(const char *name): CLState(name, *new ChooseDirection::OnEntry, *new ChooseDirection::OnExit, *new ChooseDirection::Internal)
{
	_transitions[0] = new Transition_0();
}

ChooseDirection::~ChooseDirection()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void ChooseDirection::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckChooseDirectionByGSM_VarRefs.mm"
#	include "State_ChooseDirection_VarRefs.mm"
#	include "State_ChooseDirection_OnEntry.mm"
}

void ChooseDirection::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckChooseDirectionByGSM_VarRefs.mm"
#	include "State_ChooseDirection_VarRefs.mm"
#	include "State_ChooseDirection_OnExit.mm"
}

void ChooseDirection::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckChooseDirectionByGSM_VarRefs.mm"
#	include "State_ChooseDirection_VarRefs.mm"
#	include "State_ChooseDirection_Internal.mm"
}

bool ChooseDirection::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckChooseDirectionByGSM_VarRefs.mm"
#	include "State_ChooseDirection_VarRefs.mm"

	return
	(
#		include "State_ChooseDirection_Transition_0.expr"
	);
}
