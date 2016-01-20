//
// State_Not_Ready.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckChooseDirectionByGSM_Includes.h"
#include "epuckChooseDirectionByGSM.h"
#include "State_Not_Ready.h"

#include "State_Not_Ready_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckChooseDirectionByGSM;
using namespace State;

Not_Ready::Not_Ready(const char *name): CLState(name, *new Not_Ready::OnEntry, *new Not_Ready::OnExit, *new Not_Ready::Internal)
{
	_transitions[0] = new Transition_0();
}

Not_Ready::~Not_Ready()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Not_Ready::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckChooseDirectionByGSM_VarRefs.mm"
#	include "State_Not_Ready_VarRefs.mm"
#	include "State_Not_Ready_OnEntry.mm"
}

void Not_Ready::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckChooseDirectionByGSM_VarRefs.mm"
#	include "State_Not_Ready_VarRefs.mm"
#	include "State_Not_Ready_OnExit.mm"
}

void Not_Ready::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckChooseDirectionByGSM_VarRefs.mm"
#	include "State_Not_Ready_VarRefs.mm"
#	include "State_Not_Ready_Internal.mm"
}

bool Not_Ready::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckChooseDirectionByGSM_VarRefs.mm"
#	include "State_Not_Ready_VarRefs.mm"

	return
	(
#		include "State_Not_Ready_Transition_0.expr"
	);
}
