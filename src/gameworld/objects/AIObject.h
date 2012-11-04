#ifndef AI_OBJECT_H
#define AI_OBJECT_H
#include "../GameObj.h"
#include "../StateMachine.h"
//#include "../Behaviours/Seek.h"
#include <math.h>
#include "../../SoundControl/sounds.h"
#include "AIProjectile.h"
#include "../GameCollision.h"
#include "PlayerObj.h"
#include "../ProjectileManager.h"

/**
*\brief Parent object for all AI objects
*\class AIObject
*
*This class inherites from gameobj and adds all the functions
*and variables required by the AIObjects, including but not limited to
*functions for shooting, taking damage and variables for damage dealt
*and amount of health.
*
*\author Arran Ford
*
*
*/



class AIObject: public GameObj
{
protected:
	///instance of state machine created for use by this AI object
	StateMachine<AIObject>* ThisStateMachine;

	///The amount of health the AI currently has
	int Health;

	///The speed at which the AI object can move
	double MaxSpeed;

	///The current known position of the player
	Vector3 PlayerPos;

	///The vector between AI and player
	Vector3 Direction;

	///Another Vector between AI and player, using one was causing conflicts
	Vector3 Direction2;

	///The direction the AI model is looking in when spawned
	Vector3 AILookDirection;

	///a temp value used vector math
	double temp;

	///The amount of damage the AI can deal to the player
	int Damage;

	///True if the ai is colliding with the player, else false
	bool collision;

	///Value for distance bellow which it is considered a collision between AI and player
	double CollDistance;


	
	
	
private:

	///an instance of the player object for accessing its static variables
	PlayerObj Player;

	///Variable used in picking random AI starting position
	int RandomAI;


public:

	/**
	*\brief function used to randomise AI starting position
	*
	*This function uses a random number to pick a random case
	*depending on the case statement called a range will be set
	*and the AI starting position will be at a random spot within
	*this range
	*
	*/
	void PickAIPos();

	/**
	*\brief function that reduces AI health
	*
	*function called to deal damage to the player by subtracting
	*from heatlh variable
	*
	*/
	void TakeDamage();

	/**
	*\brief Function for dealing damage
	*
	*Calls the player obj function modify health and passes in
	*the Damage value
	*
	*/
	void DealDamage();

	///Getter for the collide variable
	bool Collide();

	///object of type sounds for controlling AI sounds
	sounds soundcontroller;

	///AI destructer
	~AIObject(){delete[] ThisStateMachine;}

	///number of seconds passed since program start
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