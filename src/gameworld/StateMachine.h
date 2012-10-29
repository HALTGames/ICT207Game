#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
#include "State.h"


template<class entity_type>
class StateMachine
{
private:

	//object that owns this instance
	entity_type* Owner;

	State<entity_type>* CurrentState;

	State<entity_type>* PreviousState;

	//State<entity_type>* GlobalState

public:

	StateMachine(entity_type* owner):Owner(owner), CurrentState(NULL), PreviousState(NULL)
	{}

	
	//initialize methods
	void SetCurrentState(State<entity_type>* s){CurrentState = s;}
	void SetPreviousState(State<entity_type>* s){PreviousState = s;}

	void update()const
	{
		
		if(CurrentState) CurrentState->Execute(Owner);
		
	}


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

	void RevertToPreviousState()
	{
		ChangeState(PreviousState);
	}

	//Getters
	//State<entity_type>* CurrentState() const{return CurrentState;}
	//State<entity_type>* PreviousState() const{return PreviousState;}
	


};

#endif