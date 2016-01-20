//
// State_Check_If_Ready.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckChooseDirectionByGSM_Includes.h"
#include "epuckChooseDirectionByGSM.h"
#include "State_Check_If_Ready.h"

#include "State_Check_If_Ready_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckChooseDirectionByGSM;
using namespace State;

Check_If_Ready::Check_If_Ready(const char *name): CLState(name, *new Check_If_Ready::OnEntry, *new Check_If_Ready::OnExit, *new Check_If_Ready::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

Check_If_Ready::~Check_If_Ready()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void Check_If_Ready::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckChooseDirectionByGSM_VarRefs.mm"
#	include "State_Check_If_Ready_VarRefs.mm"
#	include "State_Check_If_Ready_OnEntry.mm"
}

void Check_If_Ready::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckChooseDirectionByGSM_VarRefs.mm"
#	include "State_Check_If_Ready_VarRefs.mm"
#	include "State_Check_If_Ready_OnExit.mm"
}

void Check_If_Ready::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckChooseDirectionByGSM_VarRefs.mm"
#	include "State_Check_If_Ready_VarRefs.mm"
#	include "State_Check_If_Ready_Internal.mm"
}

bool Check_If_Ready::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckChooseDirectionByGSM_VarRefs.mm"
#	include "State_Check_If_Ready_VarRefs.mm"

	return
	(
#		include "State_Check_If_Ready_Transition_0.expr"
	);
}

bool Check_If_Ready::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckChooseDirectionByGSM_VarRefs.mm"
#	include "State_Check_If_Ready_VarRefs.mm"

	return
	(
#		include "State_Check_If_Ready_Transition_1.expr"
	);
}

bool Check_If_Ready::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckChooseDirectionByGSM_VarRefs.mm"
#	include "State_Check_If_Ready_VarRefs.mm"

	return
	(
#		include "State_Check_If_Ready_Transition_2.expr"
	);
}
