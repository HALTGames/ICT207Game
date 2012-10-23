#include "../GameObj.h"
//#include "State.h"
#include "../StateMachine.h"
#include "AlligatorStates.h"


class Alligator: public GameObj
{
private:
	int Health;
	float MaxSpeed;
	float MaxForce;
	double temp;
	StateMachine<Alligator>* ThisStateMachine;



public:
	//void Init();
	
	~Alligator(){delete ThisStateMachine;}
	void SetVector(Vector3 New);
	void Move();
	Vector3 PlayerPos;
	Vector3 Direction;
	
	void Update(Vector3 PlayPos);
	Alligator();

	Alligator(const Vector3 pos, char* modelFile, const string collideType):GameObj(pos, modelFile, collideType), Health(400), MaxSpeed(1), MaxForce(10)
	{
	
	 ThisStateMachine = new StateMachine<Alligator>(this);
	 ThisStateMachine->SetCurrentState(AlligatorSeek::Instance());


	}

};