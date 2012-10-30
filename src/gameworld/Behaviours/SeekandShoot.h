#ifndef SEEK_SHOOT_H
#define SEEK_SHOOT_H

#include "../State.h"
#include "../objects/AIObject.h"
#include <iostream>
#include <time.h>

//class Bird;

class SeekandShoot: public State<AIObject>
{
private:
	SeekandShoot(){}
	int seconds;
	//may need copy constructer, assignment operator and destructer here

public:
	static SeekandShoot* Instance();

	virtual void Enter(AIObject* AI);
	virtual void Execute(AIObject* AI);
	virtual void Exit(AIObject* AI);


};



#endif