#include "GameObj.h"
#include "State.h"
#include "StateMachine.h"

class Bird: public GameObj
{
private:
	int Health;
	float MaxSpeed;
	float MaxForce;
	double temp;
	StateMachine<Bird>* ThisStateMachine;
	Vector3 PlayerPos;
	Vector3 Direction;


public:
	//void Init();
	
	~Bird(){delete ThisStateMachine;}
	void SetVector(Vector3 New);
	void Move();
	
	void Update(Vector3 PlayPos);
	Bird();

	Bird(const Vector3 pos, char* modelFile, const string collideType):GameObj(pos, modelFile, collideType), Health(100), MaxSpeed(10), MaxForce(10)
	{
	
	 ThisStateMachine = new StateMachine<Bird>(this);


	}

};