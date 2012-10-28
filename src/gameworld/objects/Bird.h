#include "AIObject.h"

//#include "State.h"
#include "../StateMachine.h"
#include "BirdStates.h"


class Bird: public AIObject
{
private:
	
	
		
	StateMachine<Bird>* ThisStateMachine;
	double temp;



public:
	//void Init();
	
	void Update(Vector3 PlayPos);
	~Bird(){delete ThisStateMachine;}
	Bird();

	Bird(const Vector3 pos, char* modelFile, const string collideType):AIObject(pos, modelFile, collideType)
	{
	
		Health =100;
		MaxSpeed =10;
	 ThisStateMachine = new StateMachine<Bird>(this);
	 ThisStateMachine->SetCurrentState(BirdSeek::Instance());


	}

};