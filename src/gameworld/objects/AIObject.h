#ifndef AI_OBJECT_H
#define AI_OBJECT_H
#include "../GameObj.h"
//#include "../Behaviours/Seek.h"



class AIObject: public GameObj
{
protected:
	int Health;
	double MaxSpeed;
	Vector3 PlayerPos;
	Vector3 Direction;
	double temp;
private:

public:
	AIObject();
	void Move();
	void SetVector(Vector3 dir, Vector3 other);
	void Update(Vector3 PlayPos);
	Vector3 GetPlayerPos();
	Vector3 GetDirection();
	
	//void SetHealth(int health);
	//void SetMaxSpeed(float speed);
	//void SetPlayerPos(Vector3 pos);
	AIObject(const Vector3 pos, char* modelFile, const string collideType):GameObj(pos, modelFile, collideType)
	{

	}



};

#endif