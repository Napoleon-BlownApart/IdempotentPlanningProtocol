//
// State_Output_Obstacles.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"
#include "State_Output_Obstacles.h"

#include "State_Output_Obstacles_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckPlanManagerByGSM;
using namespace State;

Output_Obstacles::Output_Obstacles(const char *name): CLState(name, *new Output_Obstacles::OnEntry, *new Output_Obstacles::OnExit, *new Output_Obstacles::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

Output_Obstacles::~Output_Obstacles()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void Output_Obstacles::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Output_Obstacles_VarRefs.mm"
#	include "State_Output_Obstacles_OnEntry.mm"
}

void Output_Obstacles::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Output_Obstacles_VarRefs.mm"
#	include "State_Output_Obstacles_OnExit.mm"
}

void Output_Obstacles::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Output_Obstacles_VarRefs.mm"
#	include "State_Output_Obstacles_Internal.mm"
}

bool Output_Obstacles::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Output_Obstacles_VarRefs.mm"

	return
	(
#		include "State_Output_Obstacles_Transition_0.expr"
	);
}

bool Output_Obstacles::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Output_Obstacles_VarRefs.mm"

	return
	(
#		include "State_Output_Obstacles_Transition_1.expr"
	);
}

bool Output_Obstacles::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckPlanManagerByGSM_VarRefs.mm"
#	include "State_Output_Obstacles_VarRefs.mm"

	return
	(
#		include "State_Output_Obstacles_Transition_2.expr"
	);
}
