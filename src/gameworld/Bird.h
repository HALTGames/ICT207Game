#include "GameObj.h"
#include "State.h"
#include "StateMachine.h"

class Bird: public GameObj
{
private:
	int Health;
	float MaxSpeed;
	float MaxForce;
	StateMachine<Bird>* ThisStateMachine;

public:
	//void Init();
	void Update();
	Bird();

	Bird(const Vector3 pos, char* modelFile, const string collideType):GameObj(pos, modelFile, collideType), Health(100), MaxSpeed(10), MaxForce(10)
	{}

};