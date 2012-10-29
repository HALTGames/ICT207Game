#include "AIObject.h"

//#include "State.h"
#include "../StateMachine.h"
#include "../Behaviours/Seek.h"



class Bird: public AIObject
{
private:
	
	
		
	StateMachine<AIObject>* ThisStateMachine;
	double temp;



public:
	//void Init();
	
	void Update(Vector3 PlayPos);
	~Bird(){delete ThisStateMachine;}
	Bird();

	Bird(const Vector3 pos, char* modelFile, const string collideType):AIObject(pos, modelFile, collideType)
	{
	
		Health =100;
		MaxSpeed =0.0001;
	 ThisStateMachine = new StateMachine<AIObject>(this);
	 ThisStateMachine->SetCurrentState(Seek::Instance());


	}

		Bird &operator=(const Bird &rhs);

      int operator==(const Bird &rhs) const;

      int operator<(const Bird &rhs) const;

};