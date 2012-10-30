#include "AIObject.h"

//#include "State.h"
//#include "../StateMachine.h"
#include "../Behaviours/Seek.h"
#include "../Behaviours/SeekandShoot.h"



class Shooter: public AIObject
{
private:
	
	
		
	//StateMachine<AIObject>* ThisStateMachine;
	double temp;



public:
	//void Init();
	
	void Update(Vector3 PlayPos);
	~Shooter(){/*delete ThisStateMachine;*/}
	Shooter();

	Shooter(const Vector3 pos, char* modelFile, const string collideType):AIObject(pos, modelFile, collideType)
	{
	
		Health =100;
		MaxSpeed =0.0001;
	// ThisStateMachine = new StateMachine<AIObject>(this);
	// ThisStateMachine->SetCurrentState(Seek::Instance());


	}

		Shooter &operator=(const Shooter &rhs);

      int operator==(const Shooter &rhs) const;

      int operator<(const Shooter &rhs) const;

};