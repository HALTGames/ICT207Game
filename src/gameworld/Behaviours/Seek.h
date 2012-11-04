#ifndef SEEK_H
#define SEEK_H

#include "../State.h"
#include "../objects/AIObject.h"
#include <iostream>
#include <time.h>


/**
 *\class Seek
 *\brief Seek class implementation.
 *
 *This class handles the seeking behaviour
 *for two of the game AI. This class is a singleton
 *
 *\author Arran Ford
 */
class Seek: public State<AIObject>
{
private:
	///Constructer
	Seek(){}
	///variable used in timing
	int seconds;


public:
	///creates a static instance of seek
	static Seek* Instance();
	///Enter function
	virtual void Enter(AIObject* AI);
	/**
	*\brief causes an AI object to seek the player
	*
	*Using the vector between player and AI
	*this function causes the AI to seek the player
	*also includes checking for collision.
	*
	*/
	virtual void Execute(AIObject* AI);
	///Exit function
	virtual void Exit(AIObject* AI);


};



#endif