#ifndef AI_OBJECT_H
#define AI_OBJECT_H
#include "../GameObj.h"


class AIObject: public GameObj
{
protected:
	int Health;
	float MaxSpeed;
	Vector3 PlayerPos;
	Vector3 Direction;
	double temp;
private:

public:
	void Move();
	void SetVector(Vector3 dir);
	void Update(Vector3 PlayPos);
	Vector3 GetPlayerPos();
	
	//void SetHealth(int health);
	//void SetMaxSpeed(float speed);
	//void SetPlayerPos(Vector3 pos);
	AIObject(const Vector3 pos, char* modelFile, const string collideType):GameObj(pos, modelFile, collideType)
	{

	}



};

#endif