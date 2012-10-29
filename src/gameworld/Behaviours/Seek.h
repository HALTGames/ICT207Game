#ifndef SEEK_H
#define SEEK_H

#include "../State.h"
#include "../objects/AIObject.h"
#include <iostream>
#include <time.h>

//class Bird;

class Seek: public State<AIObject>
{
private:
	Seek(){}
	int seconds;
	//may need copy constructer, assignment operator and destructer here

public:
	static Seek* Instance();

	virtual void Enter(AIObject* AI);
	virtual void Execute(AIObject* AI);
	virtual void Exit(AIObject* AI);


};



#endif