#include "AIObject.h"

//#include "State.h"
//#include "../StateMachine.h"
#include "../Behaviours/Seek.h"



/**
 *\class Bird
 *\brief Bird class implementation.
 *
 *This is the child class of AIobject 
 *for the Bird AI
 *
 *
 *\author Arran Ford
 */
class Bird: public AIObject
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
	///Deconstructer for Bird
	~Bird(){}
	///Constructer for Bird
	Bird();

	///overloaded constructer for Bird
	Bird(const Vector3 pos, char* modelFile, const string collideType):AIObject(pos, modelFile, collideType)
	{
	
		Health =100;
		MaxSpeed =0.0001;

	}

	///Overloaded assignment operator
	Bird &operator=(const Bird &rhs);
	///Overloaded comparisson operator
	int operator==(const Bird &rhs) const;
	 ///Overloaded less than operator
	int operator<(const Bird &rhs) const;

};