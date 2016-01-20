//
// epuckPlanManagerByGSM.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "epuckPlanManagerByGSM_Includes.h"
#include "epuckPlanManagerByGSM.h"

#include "State_InitialPseudoState.h"
#include "State_Initial.h"
#include "State_Observe.h"
#include "State_Output_Obstacles.h"
#include "State_Receive_New_Plan.h"
#include "State_Set_Next_Goal.h"
#include "State_Record_Obstacle.h"
#include "State_Save_Obstacles.h"
#include "State_Plan_Settings.h"
#include "State_Load_Obstacles.h"
#include "State_Is_This_The_End.h"
#include "State_Last_Obstacle_Only.h"
#include "State_Is_Array_Full.h"
#include "State_Add_Next_Obstacle.h"
#include "State_Get_A_Portion.h"
#include "State_Send_Obstacles.h"
#include "State_No_Change.h"
#include "State_Request_New_Plan.h"

using namespace FSM;
using namespace CLM;

extern "C"
{
	epuckPlanManagerByGSM *CLM_Create_epuckPlanManagerByGSM(int mid, const char *name)
	{
		return new epuckPlanManagerByGSM(mid, name);
	}
}

epuckPlanManagerByGSM::epuckPlanManagerByGSM(int mid, const char *name): CLMachine(mid, name)
{
	_states[0] = new FSMepuckPlanManagerByGSM::State::InitialPseudoState;
	_states[1] = new FSMepuckPlanManagerByGSM::State::Initial;
	_states[2] = new FSMepuckPlanManagerByGSM::State::Observe;
	_states[3] = new FSMepuckPlanManagerByGSM::State::Output_Obstacles;
	_states[4] = new FSMepuckPlanManagerByGSM::State::Receive_New_Plan;
	_states[5] = new FSMepuckPlanManagerByGSM::State::Set_Next_Goal;
	_states[6] = new FSMepuckPlanManagerByGSM::State::Record_Obstacle;
	_states[7] = new FSMepuckPlanManagerByGSM::State::Save_Obstacles;
	_states[8] = new FSMepuckPlanManagerByGSM::State::Plan_Settings;
	_states[9] = new FSMepuckPlanManagerByGSM::State::Load_Obstacles;
	_states[10] = new FSMepuckPlanManagerByGSM::State::Is_This_The_End;
	_states[11] = new FSMepuckPlanManagerByGSM::State::Last_Obstacle_Only;
	_states[12] = new FSMepuckPlanManagerByGSM::State::Is_Array_Full;
	_states[13] = new FSMepuckPlanManagerByGSM::State::Add_Next_Obstacle;
	_states[14] = new FSMepuckPlanManagerByGSM::State::Get_A_Portion;
	_states[15] = new FSMepuckPlanManagerByGSM::State::Send_Obstacles;
	_states[16] = new FSMepuckPlanManagerByGSM::State::No_Change;
	_states[17] = new FSMepuckPlanManagerByGSM::State::Request_New_Plan;

	setInitialState(_states[0]);            // set initial state
}

epuckPlanManagerByGSM::~epuckPlanManagerByGSM()
{
	delete _states[0];
	delete _states[1];
	delete _states[2];
	delete _states[3];
	delete _states[4];
	delete _states[5];
	delete _states[6];
	delete _states[7];
	delete _states[8];
	delete _states[9];
	delete _states[10];
	delete _states[11];
	delete _states[12];
	delete _states[13];
	delete _states[14];
	delete _states[15];
	delete _states[16];
	delete _states[17];
}
