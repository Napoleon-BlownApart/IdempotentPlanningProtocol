//
// State_Forward.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckMeanderLinesByGSM_Includes.h"
#include "epuckMeanderLinesByGSM.h"
#include "State_Forward.h"

#include "State_Forward_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMepuckMeanderLinesByGSM;
using namespace State;

Forward::Forward(const char *name): CLState(name, *new Forward::OnEntry, *new Forward::OnExit, *new Forward::Internal)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
	_transitions[3] = new Transition_3();
	_transitions[4] = new Transition_4();
	_transitions[5] = new Transition_5();
}

Forward::~Forward()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
	delete _transitions[3];
	delete _transitions[4];
	delete _transitions[5];
}

void Forward::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Forward_VarRefs.mm"
#	include "State_Forward_OnEntry.mm"
}

void Forward::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Forward_VarRefs.mm"
#	include "State_Forward_OnExit.mm"
}

void Forward::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Forward_VarRefs.mm"
#	include "State_Forward_Internal.mm"
}

bool Forward::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Forward_VarRefs.mm"

	return
	(
#		include "State_Forward_Transition_0.expr"
	);
}

bool Forward::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Forward_VarRefs.mm"

	return
	(
#		include "State_Forward_Transition_1.expr"
	);
}

bool Forward::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Forward_VarRefs.mm"

	return
	(
#		include "State_Forward_Transition_2.expr"
	);
}

bool Forward::Transition_3::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Forward_VarRefs.mm"

	return
	(
#		include "State_Forward_Transition_3.expr"
	);
}

bool Forward::Transition_4::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Forward_VarRefs.mm"

	return
	(
#		include "State_Forward_Transition_4.expr"
	);
}

bool Forward::Transition_5::check(CLMachine *_machine, CLState *_state) const
{
#	include "epuckMeanderLinesByGSM_VarRefs.mm"
#	include "State_Forward_VarRefs.mm"

	return
	(
#		include "State_Forward_Transition_5.expr"
	);
}
