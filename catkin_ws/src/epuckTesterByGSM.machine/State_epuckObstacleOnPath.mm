//
// State_epuckObstacleOnPath.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckObstacleOnPath.h"

#include "State_epuckObstacleOnPath_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckObstacleOnPath::epuckObstacleOnPath(const char *name): CLState(name, *new epuckObstacleOnPath::OnEntry, *new epuckObstacleOnPath::OnExit, *new epuckObstacleOnPath::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

epuckObstacleOnPath::~epuckObstacleOnPath()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void epuckObstacleOnPath::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckObstacleOnPath_VarRefs.mm"
#	include "State_epuckObstacleOnPath_OnEntry.mm"
}

void epuckObstacleOnPath::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckObstacleOnPath_VarRefs.mm"
#	include "State_epuckObstacleOnPath_OnExit.mm"
}

void epuckObstacleOnPath::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckObstacleOnPath_VarRefs.mm"
#	include "State_epuckObstacleOnPath_Internal.mm"
}

bool epuckObstacleOnPath::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckObstacleOnPath_VarRefs.mm"

	return
	(
#		include "State_epuckObstacleOnPath_Transition_0.expr"
	);
}

bool epuckObstacleOnPath::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckObstacleOnPath_VarRefs.mm"

	return
	(
#		include "State_epuckObstacleOnPath_Transition_1.expr"
	);
}

bool epuckObstacleOnPath::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckObstacleOnPath_VarRefs.mm"

	return
	(
#		include "State_epuckObstacleOnPath_Transition_2.expr"
	);
}
