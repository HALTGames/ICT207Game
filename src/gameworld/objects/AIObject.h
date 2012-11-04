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
 *\class AIObject
 *\brief AIObject class implementation.
 *
 *This class is the parent class for all AIobjects
 *it contains functions and variables required by all
 *AI's and Ai behaviours
 *
 *\author Arran Ford
 */
class AIObject: public GameObj
{
protected:
	///instance of statemachine for use in behaviours
	StateMachine<AIObject>* ThisStateMachine;
	///Integer the determines how much health an AI currently has
	int Health;
	///The maximum speed at which an AI can travel
	double MaxSpeed;
	///The current position the player object is at
	Vector3 PlayerPos;
	///The Vector between AI object and the player
	Vector3 Direction;
	///Same as other direction vector, needed two to avoid some conflicts
	Vector3 Direction2;
	///The direction which the AI model is looking in when spawned
	Vector3 AILookDirection;
	///a value used in multiple sums and functions
	double temp;
	///the amount of damage the AI can deal to player
	int Damage;
	///True for collision false for now collision with player
	bool collision;
	///distance between player and AI that is considered a collision
	double CollDistance;


	
	
	
private:
	///instance of the player obj
	PlayerObj Player;
	///integer used for selecting random spawn point
	int RandomAI;


public:
	///The counter used in checking if its okay for ai to be damaged
	int DamageSeconds;

	/**
	*\brief Picks a position for AI to spawn
	*
	*Uses a case statement and a random number generator
	*to pick a random spawn point in quadrants outside of the island
	*
	*/
	void PickAIPos();

	/**
	*\brief checks if AI should take damage
	*
	*this function gets the list of all projectiles
	*and checks if they are colliding with the AI position
	*if so the Ai takes damage and the function 
	*returns true.
	*
	*\retval bool
	*/
	bool TakeDamage();

	/**
	*\brief deals damage to player
	*
	*Calles the player modify health function
	*and passes in the AI damage variable to 
	*damage the player
	*
	*/
	void DealDamage();

	///Getter for the collide boolean variable
	bool Collide();

	///Instance of the sounds class
	sounds soundcontroller;

	///AI destructer, deletes statemachine
	~AIObject(){delete[] ThisStateMachine;}

	///Used in timing AI behaviours
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

	/**
	*\brief Shoots at the player
	*
	*Uses the projectile manager add projectile function
	*to send a projectile in the direction of the player
	*launches from infron of AI to avoid damaging self
	*
	*/
	void Fire();

	///Gets the magnitude of the vector passed in
	double GetMag(Vector3 pass);

	/**
	*\brief gets distance from player
	*
	*uses player and Ai location to work out the
	*magnitude of the vector between them
	*
	*\retval double
	*/
	double GetDistanceFrom();

	///Getter for health variable
	int GetHealth();

	///Getter for player position varibale
	Vector3 GetPlayerPos();

	///Getter for Direction variable
	Vector3 GetDirection();


	/**
	*\brief handles terrain collision
	*
	*if AI is going to collide with terrain the AI will not move instead
	*will stay not moving until the vector to the player is clear
	*
	*\param const Vector3 pos
	*/
	virtual void ChangePosition(const Vector3 pos);

	///Overloaded assignment operator
	AIObject &operator=(const AIObject &rhs);

	///overloaded comparisson operator
	int operator==(const AIObject &rhs) const;

	///Overloaded less than operator
	int operator<(const AIObject &rhs) const;
		
	///overloaded AI constructer
	AIObject(const Vector3 pos, char* modelFile, const string collideType):GameObj(pos, modelFile, collideType)
	{

	}



};

#endif