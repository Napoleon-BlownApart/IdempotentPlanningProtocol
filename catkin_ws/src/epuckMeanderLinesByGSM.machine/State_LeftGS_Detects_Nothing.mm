//
// State_LeftGS_Detects_Nothing.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_LeftGS_Detects_Nothing.h"

#include "State_LeftGS_Detects_Nothing_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

LeftGS_Detects_Nothing::LeftGS_Detects_Nothing(const char *name): CLState(name, *new LeftGS_Detects_Nothing::OnEntry, *new LeftGS_Detects_Nothing::OnExit, *new LeftGS_Detects_Nothing::Internal)
{
	_transitions[0] = new Transition_0();
}

LeftGS_Detects_Nothing::~LeftGS_Detects_Nothing()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
}

void LeftGS_Detects_Nothing::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_LeftGS_Detects_Nothing_VarRefs.mm"
#	include "State_LeftGS_Detects_Nothing_OnEntry.mm"
}

void LeftGS_Detects_Nothing::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_LeftGS_Detects_Nothing_VarRefs.mm"
#	include "State_LeftGS_Detects_Nothing_OnExit.mm"
}

void LeftGS_Detects_Nothing::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_LeftGS_Detects_Nothing_VarRefs.mm"
#	include "State_LeftGS_Detects_Nothing_Internal.mm"
}

bool LeftGS_Detects_Nothing::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_LeftGS_Detects_Nothing_VarRefs.mm"

	return
	(
#		include "State_LeftGS_Detects_Nothing_Transition_0.expr"
	);
}
