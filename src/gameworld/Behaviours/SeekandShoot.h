#ifndef SEEK_SHOOT_H
#define SEEK_SHOOT_H

#include "../State.h"
#include "../objects/AIObject.h"
#include <iostream>
#include <time.h>

/**
 *\class SeekandShoot
 *\brief SeekandShoot class implementation.
 *
 *This class handles the seek and shoot behaviour
 *for one of the game game AI. This class is a singleton
 *
 *\author Arran Ford
 */
class SeekandShoot: public State<AIObject>
{
private:
	///Constructer
	SeekandShoot(){}
	///seconds integer used in timing
	int seconds;
	
public:
	///creates a static instance of seek and shoot
	static SeekandShoot* Instance();
	///Enter function
	virtual void Enter(AIObject* AI);
	/**
	*\brief execute function for seek and shoot function
	*
	*function works similar to seek but when close to the player
	*will move past will shooting at the player
	*
	*\param AIObject AI
	*/
	virtual void Execute(AIObject* AI);
	///Exit function
	virtual void Exit(AIObject* AI);


};



#endif