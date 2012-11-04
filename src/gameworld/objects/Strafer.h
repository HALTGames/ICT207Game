#include "AIObject.h"

//#include "State.h"
//#include "../StateMachine.h"
#include "../Behaviours/StrafeandSeek.h"


/**
 *\class Strafer
 *\brief Strafer class implementation.
 *
 *This is the child class of AIobject 
 *for the Strafer AI
 *
 *
 *\author Arran Ford
 */
class Strafer: public AIObject
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
	///Deconstructer for Strafer
	~Strafer(){}
	///Constructer for Strafer
	Strafer();
	///overloaded constructer for Strafer
	Strafer(const Vector3 pos, char* modelFile, const string collideType):AIObject(pos, modelFile, collideType)
	{
	
		Health =100;
		MaxSpeed =0.0001;
	
	}
	///Overloaded assignment operator
	Strafer &operator=(const Strafer &rhs);
	///Overloaded comparisson operator
    int operator==(const Strafer &rhs) const;
	 ///Overloaded less than operator
    int operator<(const Strafer &rhs) const;

};