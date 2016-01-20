//
// State_Record_Obstacle.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"
#include "State_Record_Obstacle.h"

#include "State_Record_Obstacle_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckPlanManagerByGSM;
using namespace State;

Record_Obstacle::Record_Obstacle(const char *name): CLState(name, *new Record_Obstacle::OnEntry, *new Record_Obstacle::OnExit, *new Record_Obstacle::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

Record_Obstacle::~Record_Obstacle()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
}

void Record_Obstacle::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Record_Obstacle_VarRefs.mm"
#	include "State_Record_Obstacle_OnEntry.mm"
}

void Record_Obstacle::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Record_Obstacle_VarRefs.mm"
#	include "State_Record_Obstacle_OnExit.mm"
}

void Record_Obstacle::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Record_Obstacle_VarRefs.mm"
#	include "State_Record_Obstacle_Internal.mm"
}

bool Record_Obstacle::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Record_Obstacle_VarRefs.mm"

	return
	(
#		include "State_Record_Obstacle_Transition_0.expr"
	);
}

bool Record_Obstacle::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Record_Obstacle_VarRefs.mm"

	return
	(
#		include "State_Record_Obstacle_Transition_1.expr"
	);
}
