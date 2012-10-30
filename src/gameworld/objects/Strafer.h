#include "AIObject.h"

//#include "State.h"
//#include "../StateMachine.h"
#include "../Behaviours/StrafeandSeek.h"



class Strafer: public AIObject
{
private:
	
	
		
	//StateMachine<AIObject>* ThisStateMachine;
	double temp;



public:
	//void Init();
	
	void Update(Vector3 PlayPos);
	~Strafer(){/*delete ThisStateMachine;*/}
	Strafer();

	Strafer(const Vector3 pos, char* modelFile, const string collideType):AIObject(pos, modelFile, collideType)
	{
	
		Health =100;
		MaxSpeed =0.0001;
	// ThisStateMachine = new StateMachine<AIObject>(this);
	// ThisStateMachine->SetCurrentState(Seek::Instance());


	}

		Strafer &operator=(const Strafer &rhs);

      int operator==(const Strafer &rhs) const;

      int operator<(const Strafer &rhs) const;

};