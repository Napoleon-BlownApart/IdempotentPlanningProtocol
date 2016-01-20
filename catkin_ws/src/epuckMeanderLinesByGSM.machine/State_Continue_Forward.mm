//
// State_Continue_Forward.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Continue_Forward.h"

#include "State_Continue_Forward_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Continue_Forward::Continue_Forward(const char *name): CLState(name, *new Continue_Forward::OnEntry, *new Continue_Forward::OnExit, *new Continue_Forward::Internal)
{
	_transitions[0] = new Transition_0();
}

Continue_Forward::~Continue_Forward()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void Continue_Forward::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Continue_Forward_VarRefs.mm"
#	include "State_Continue_Forward_OnEntry.mm"
}

void Continue_Forward::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Continue_Forward_VarRefs.mm"
#	include "State_Continue_Forward_OnExit.mm"
}

void Continue_Forward::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Continue_Forward_VarRefs.mm"
#	include "State_Continue_Forward_Internal.mm"
}

bool Continue_Forward::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Continue_Forward_VarRefs.mm"

	return
	(
#		include "State_Continue_Forward_Transition_0.expr"
	);
}
