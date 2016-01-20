//
// State_Have_Obstacle.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckObstacleOnPathByGSM_Includes.h"
#include "epuckObstacleOnPathByGSM.h"
#include "State_Have_Obstacle.h"

#include "State_Have_Obstacle_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckObstacleOnPathByGSM;
using namespace State;

Have_Obstacle::Have_Obstacle(const char *name): CLState(name, *new Have_Obstacle::OnEntry, *new Have_Obstacle::OnExit, *new Have_Obstacle::Internal)
{
	_transitions[0] = new Transition_0();
}

Have_Obstacle::~Have_Obstacle()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Have_Obstacle::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Have_Obstacle_VarRefs.mm"
#	include "State_Have_Obstacle_OnEntry.mm"
}

void Have_Obstacle::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Have_Obstacle_VarRefs.mm"
#	include "State_Have_Obstacle_OnExit.mm"
}

void Have_Obstacle::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Have_Obstacle_VarRefs.mm"
#	include "State_Have_Obstacle_Internal.mm"
}

bool Have_Obstacle::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckObstacleOnPathByGSM_VarRefs.mm"
#	include "State_Have_Obstacle_VarRefs.mm"

	return
	(
#		include "State_Have_Obstacle_Transition_0.expr"
	);
}
