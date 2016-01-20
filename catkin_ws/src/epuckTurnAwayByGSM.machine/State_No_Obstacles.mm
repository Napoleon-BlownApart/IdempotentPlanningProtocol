//
// State_No_Obstacles.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckTurnAwayByGSM_Includes.h"
#include "epuckTurnAwayByGSM.h"
#include "State_No_Obstacles.h"

#include "State_No_Obstacles_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckTurnAwayByGSM;
using namespace State;

No_Obstacles::No_Obstacles(const char *name): CLState(name, *new No_Obstacles::OnEntry, *new No_Obstacles::OnExit, *new No_Obstacles::Internal)
{
	_transitions[0] = new Transition_0();
}

No_Obstacles::~No_Obstacles()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void No_Obstacles::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnAwayByGSM_VarRefs.mm"
#	include "State_No_Obstacles_VarRefs.mm"
#	include "State_No_Obstacles_OnEntry.mm"
}

void No_Obstacles::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnAwayByGSM_VarRefs.mm"
#	include "State_No_Obstacles_VarRefs.mm"
#	include "State_No_Obstacles_OnExit.mm"
}

void No_Obstacles::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnAwayByGSM_VarRefs.mm"
#	include "State_No_Obstacles_VarRefs.mm"
#	include "State_No_Obstacles_Internal.mm"
}

bool No_Obstacles::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckTurnAwayByGSM_VarRefs.mm"
#	include "State_No_Obstacles_VarRefs.mm"

	return
	(
#		include "State_No_Obstacles_Transition_0.expr"
	);
}
