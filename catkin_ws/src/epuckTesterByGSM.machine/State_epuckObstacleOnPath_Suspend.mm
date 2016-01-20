//
// State_epuckObstacleOnPath_Suspend.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckObstacleOnPath_Suspend.h"

#include "State_epuckObstacleOnPath_Suspend_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckObstacleOnPath_Suspend::epuckObstacleOnPath_Suspend(const char *name): CLState(name, *new epuckObstacleOnPath_Suspend::OnEntry, *new epuckObstacleOnPath_Suspend::OnExit, *new epuckObstacleOnPath_Suspend::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckObstacleOnPath_Suspend::~epuckObstacleOnPath_Suspend()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckObstacleOnPath_Suspend::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckObstacleOnPath_Suspend_VarRefs.mm"
#	include "State_epuckObstacleOnPath_Suspend_OnEntry.mm"
}

void epuckObstacleOnPath_Suspend::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckObstacleOnPath_Suspend_VarRefs.mm"
#	include "State_epuckObstacleOnPath_Suspend_OnExit.mm"
}

void epuckObstacleOnPath_Suspend::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckObstacleOnPath_Suspend_VarRefs.mm"
#	include "State_epuckObstacleOnPath_Suspend_Internal.mm"
}

bool epuckObstacleOnPath_Suspend::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckObstacleOnPath_Suspend_VarRefs.mm"

	return
	(
#		include "State_epuckObstacleOnPath_Suspend_Transition_0.expr"
	);
}
