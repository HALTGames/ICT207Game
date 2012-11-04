#include "AIObject.h"

//#include "State.h"
//#include "../StateMachine.h"
#include "../Behaviours/Seek.h"
#include "../Behaviours/SeekandShoot.h"


/**
 *\Shooter
 *\brief Shooter class implementation.
 *
 *This is the child class of AIobject 
 *for the Shooter AI
 *
 *
 *\author Arran Ford
 */
class Shooter: public AIObject
{
private:
	
	///temp variable used in calculations
	double temp;



public:

	/**
	*\brief update function
	*
	*Updates the alligators variable that
	*dictates current player position
	*and updates the statemachine
	*
	*\param Vector3 PlayPos
	*/
	void Update(Vector3 PlayPos);
	///Deconstructer for Shooter
	~Shooter(){}
	///Constructer for Shooter
	Shooter();

	///overloaded constructer for Shooter
	Shooter(const Vector3 pos, char* modelFile, const string collideType):AIObject(pos, modelFile, collideType)
	{
	
		Health =100;
		MaxSpeed =0.0001;
	

	}

	///Overloaded assignment operator
	Shooter &operator=(const Shooter &rhs);
	///Overloaded comparisson operator
	int operator==(const Shooter &rhs) const;
	///Overloaded less than operator
	int operator<(const Shooter &rhs) const;

};