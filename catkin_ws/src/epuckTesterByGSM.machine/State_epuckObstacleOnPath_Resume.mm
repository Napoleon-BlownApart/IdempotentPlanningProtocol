//
// State_epuckObstacleOnPath_Resume.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTesterByGSM_Includes.h"
#include "epuckTesterByGSM.h"
#include "State_epuckObstacleOnPath_Resume.h"

#include "State_epuckObstacleOnPath_Resume_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTesterByGSM;
using namespace State;

epuckObstacleOnPath_Resume::epuckObstacleOnPath_Resume(const char *name): CLState(name, *new epuckObstacleOnPath_Resume::OnEntry, *new epuckObstacleOnPath_Resume::OnExit, *new epuckObstacleOnPath_Resume::Internal)
{
	_transitions[0] = new Transition_0();
}

epuckObstacleOnPath_Resume::~epuckObstacleOnPath_Resume()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void epuckObstacleOnPath_Resume::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckObstacleOnPath_Resume_VarRefs.mm"
#	include "State_epuckObstacleOnPath_Resume_OnEntry.mm"
}

void epuckObstacleOnPath_Resume::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckObstacleOnPath_Resume_VarRefs.mm"
#	include "State_epuckObstacleOnPath_Resume_OnExit.mm"
}

void epuckObstacleOnPath_Resume::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckObstacleOnPath_Resume_VarRefs.mm"
#	include "State_epuckObstacleOnPath_Resume_Internal.mm"
}

bool epuckObstacleOnPath_Resume::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTesterByGSM_VarRefs.mm"
#	include "State_epuckObstacleOnPath_Resume_VarRefs.mm"

	return
	(
#		include "State_epuckObstacleOnPath_Resume_Transition_0.expr"
	);
}
