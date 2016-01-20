//
// State_Last_Obstacle_Only.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"
#include "State_Last_Obstacle_Only.h"

#include "State_Last_Obstacle_Only_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckPlanManagerByGSM;
using namespace State;

Last_Obstacle_Only::Last_Obstacle_Only(const char *name): CLState(name, *new Last_Obstacle_Only::OnEntry, *new Last_Obstacle_Only::OnExit, *new Last_Obstacle_Only::Internal)
{
	_transitions[0] = new Transition_0();
}

Last_Obstacle_Only::~Last_Obstacle_Only()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Last_Obstacle_Only::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Last_Obstacle_Only_VarRefs.mm"
#	include "State_Last_Obstacle_Only_OnEntry.mm"
}

void Last_Obstacle_Only::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Last_Obstacle_Only_VarRefs.mm"
#	include "State_Last_Obstacle_Only_OnExit.mm"
}

void Last_Obstacle_Only::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Last_Obstacle_Only_VarRefs.mm"
#	include "State_Last_Obstacle_Only_Internal.mm"
}

bool Last_Obstacle_Only::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Last_Obstacle_Only_VarRefs.mm"

	return
	(
#		include "State_Last_Obstacle_Only_Transition_0.expr"
	);
}
