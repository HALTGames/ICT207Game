#ifndef SEEK_STRAFE_H
#define SEEK_STRAFE_H

#include "../State.h"
#include "../objects/AIObject.h"
#include <iostream>
#include <time.h>

/**
 *\class StrafeandSeek
 *\brief Strafeandseek class implementation.
 *
 *This class handles the strafe and seek behaviour
 *for one of the AI's
 *
 *\author Arran Ford
 */
class StrafeandSeek: public State<AIObject>
{
private:
	///Default constructer
	StrafeandSeek(){}
	///timer variable for some functions
	int seconds;
	
public:
	///Creates an instance of the strafe and seek class
	static StrafeandSeek* Instance();
	///Enter function
	virtual void Enter(AIObject* AI);
	/**
	*\brief execute function for strafe and seek behaviour
	*
	*another varient of seek, once close to the player
	*this AI will stop and start shooting at the player
	*until the player is out of range
	*
	*\param AIObject AI
	*/
	virtual void Execute(AIObject* AI);
	///Exit function
	virtual void Exit(AIObject* AI);


};



#endif