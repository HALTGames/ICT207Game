#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
#include "State.h"


/**
 *\class StateMachine
 *\brief StateMachine class implementation.
 *
 *This is a class that handles all statemachine
 *functions such as storing states and switching states
 *
 *\author Arran Ford
 */
template<class entity_type>
class StateMachine
{
private:

	///object that owns this instance
	entity_type* Owner;

	///Machine is in
	State<entity_type>* CurrentState;

	///Previous state machine was in
	State<entity_type>* PreviousState;
		
public:

	///Statemachine constructer
	StateMachine(entity_type* owner):Owner(owner), CurrentState(NULL), PreviousState(NULL)
	{}

	
	///Function for setting current state
	void SetCurrentState(State<entity_type>* s){CurrentState = s;}
	///Function for setting previous state
	void SetPreviousState(State<entity_type>* s){PreviousState = s;}

	/**
	*\brief update function
	*
	*this function calls the execute function
	*of the current state if it exists
	*
	*/
	void update()const
	{
		if(CurrentState) CurrentState->Execute(Owner);
	}

	/**
	*\brief new state function
	*
	*This function saves the current state as the previous state
	*and sets the new state as current state
	*
	*\param State<entity_Type>* NewState
	*/
	void ChangeState(State<entity_type>* NewState)
	{
		assert(NewState && "<StateMachine::ChangeState>: trying to change to a null state");
		
		//save the previous state
		PreviousState = CurrentState;

		//Exit the current state
		CurrentState->Exit(Owner);

		//switch states
		CurrentState = NewState;

		//Enter new state
		CurrentState->Enter(Owner);
	}


	///Function sets current state to previous state
	void RevertToPreviousState()
	{
		ChangeState(PreviousState);
	}

	
};

#endif