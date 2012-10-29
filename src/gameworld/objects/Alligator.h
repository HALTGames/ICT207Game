#include "AIObject.h"

//#include "State.h"
#include "../StateMachine.h"
#include "../Behaviours/Seek.h"



class Alligator: public AIObject
{
private:
	
	
		
	StateMachine<AIObject>* ThisStateMachine;
	double temp;



public:
	//void Init();
	
	void Update(Vector3 PlayPos);
	~Alligator(){delete ThisStateMachine;}
	Alligator();

	Alligator(const Vector3 pos, char* modelFile, const string collideType):AIObject(pos, modelFile, collideType)
	{
	
		Health =1000;
		MaxSpeed =0.0001;
	 ThisStateMachine = new StateMachine<AIObject>(this);
	 ThisStateMachine->SetCurrentState(Seek::Instance());


	}

		Alligator &operator=(const Alligator &rhs);

      int operator==(const Alligator &rhs) const;

      int operator<(const Alligator &rhs) const;

};