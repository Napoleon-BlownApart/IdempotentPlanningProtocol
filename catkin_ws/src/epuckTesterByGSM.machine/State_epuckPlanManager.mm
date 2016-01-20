//
// State_epuckPlanManager.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckPlanManager.h"

#include "State_epuckPlanManager_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckPlanManager::epuckPlanManager(const char *name): CLState(name, *new epuckPlanManager::OnEntry, *new epuckPlanManager::OnExit, *new epuckPlanManager::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

epuckPlanManager::~epuckPlanManager()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void epuckPlanManager::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckPlanManager_VarRefs.mm"
#	include "State_epuckPlanManager_OnEntry.mm"
}

void epuckPlanManager::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckPlanManager_VarRefs.mm"
#	include "State_epuckPlanManager_OnExit.mm"
}

void epuckPlanManager::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckPlanManager_VarRefs.mm"
#	include "State_epuckPlanManager_Internal.mm"
}

bool epuckPlanManager::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckPlanManager_VarRefs.mm"

	return
	(
#		include "State_epuckPlanManager_Transition_0.expr"
	);
}

bool epuckPlanManager::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckPlanManager_VarRefs.mm"

	return
	(
#		include "State_epuckPlanManager_Transition_1.expr"
	);
}

bool epuckPlanManager::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckPlanManager_VarRefs.mm"

	return
	(
#		include "State_epuckPlanManager_Transition_2.expr"
	);
}
