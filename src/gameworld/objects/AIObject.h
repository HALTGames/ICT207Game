#ifndef AI_OBJECT_H
#define AI_OBJECT_H
#include "../GameObj.h"
#include "../StateMachine.h"
//#include "../Behaviours/Seek.h"
#include <math.h>
#include "../../SoundControl/sounds.h"
//#include "AIProjectile.h"
#include "../GameCollision.h"
#include "PlayerObj.h"
#include "../ProjectileManager.h"



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
	bool collision;
	double CollDistance;


	
	
	
private:
	PlayerObj Player;
	int RandomAI;


public:
	int DamageSeconds;
	void PickAIPos();
	bool TakeDamage();
	void DealDamage();
	bool Collide();
	sounds soundcontroller;
	~AIObject(){delete[] ThisStateMachine;}
	int seconds;


	///variable used in AI behaviour
	int checker;

	///Counter used to limit fire rate for AI
	int GunSeconds;

	///Getter for finite state machine
	StateMachine<AIObject>*  GetFSM()const{return ThisStateMachine;}

	///Constructer for AIObject
	AIObject();

	/**
	*\brief movement function
	*
	*Calls the GameObj change position function
	*and passes in the direction Vector
	*
	*/
	void Move();

	/**
	*\brief works out the direction vector between AI and object
	*
	*first this function works out the magnitude of the vector
	*between the ai and player, this value is then checked to see if there
	*is a collision between AI and player lastly the value is used to get
	*the unit vector of the vector between AI and player, this vector is the multiplied
	*by the AI speed.
	*
	*\param Vector3 direction, Vector3 other
	*
	*/
	void SetVector(Vector3 dir, Vector3 other);

	/**
	*\brief sets angle for AI model
	*
	*The function works out the angle between AI
	*model starting look vector and the vector between
	*AI and object and then sets the angle value so that the
	*model faces in the correct direction
	*
	*\param Vector3 direction, Vector3 other
	*
	*/
	virtual	void SetAngle(Vector3 dir, Vector3 other);
	

	void Update(Vector3 PlayPos);

	/**
	*\brief function for lowering health
	*
	*takes in an integer and minuses it from
	*AI's health
	*
	*\param int minus
	*/
	void SubtractHealth(int minus);


	void Fire();
	double GetMag(Vector3 pass);
	double GetDistanceFrom();
	int GetHealth();
	Vector3 GetPlayerPos();
	Vector3 GetDirection();

	virtual void ChangePosition(const Vector3 pos);

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