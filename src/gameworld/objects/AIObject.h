#ifndef AI_OBJECT_H
#define AI_OBJECT_H
#include "../GameObj.h"
#include "../StateMachine.h"
//#include "../Behaviours/Seek.h"
#include <math.h>
#include "../../SoundControl/sounds.h"
#include "AIProjectile.h"
#include "../GameObjManager.h"
#include "../GameCollision.h"
#include "PlayerObj.h"



class AIObject: public GameObj
{
protected:
	StateMachine<AIObject>* ThisStateMachine;
	int Health;
	double MaxSpeed;
	Vector3 PlayerPos;
	Vector3 Direction;
	Vector3 Direction2;
	Vector3 AILookDirection;
	double temp;
	int Damage;
	
	
	
private:
	PlayerObj Player;


public:
	
	void TakeDamage();
	void DealDamage();
	bool Collide();
	sounds soundcontroller;
	~AIObject(){delete[] ThisStateMachine;}
	int seconds;
	int checker;
	int GunSeconds;
	StateMachine<AIObject>*  GetFSM()const{return ThisStateMachine;}
	AIObject();
	void Move();
	void SetVector(Vector3 dir, Vector3 other);
virtual	void SetAngle(Vector3 dir, Vector3 other);
	void Update(Vector3 PlayPos);
	void SubtractHealth(int minus);
	void Fire();
	void Lunge();
	double GetMag(Vector3 pass);
	double GetDistanceFrom();
	int GetHealth();
	Vector3 GetPlayerPos();
	Vector3 GetDirection();

	AIObject &operator=(const AIObject &rhs);

      int operator==(const AIObject &rhs) const;

      int operator<(const AIObject &rhs) const;

	
	//void SetHealth(int health);
	//void SetMaxSpeed(float speed);
	//void SetPlayerPos(Vector3 pos);
	AIObject(const Vector3 pos, char* modelFile, const string collideType):GameObj(pos, modelFile, collideType)
	{

	}



};

#endif