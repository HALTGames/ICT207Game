#include "AIObject.h"

//#include "State.h"
//#include "../StateMachine.h"
#include "../Behaviours/Seek.h"


/**
 *\class Alligator
 *\brief Alligator class implementation.
 *
 *This is the child class of AIobject 
 *for the alligator AI
 *
 *
 *\author Arran Ford
 */
class Alligator: public AIObject
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

	///Deconstructer for Alligator
	~Alligator(){}

	///Constructer for Alligator
	Alligator();

	///overloaded constructer for Alligator
	Alligator(const Vector3 pos, char* modelFile, const string collideType):AIObject(pos, modelFile, collideType)
	{
		Health =1000;
		MaxSpeed =0.0001;
	}

	///Overloaded assignment operator
	Alligator &operator=(const Alligator &rhs);

	///Overloaded comparisson operator
	int operator==(const Alligator &rhs) const;

	///Overloaded less than operator
	int operator<(const Alligator &rhs) const;

};