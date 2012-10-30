#ifndef SEEK_STRAFE_H
#define SEEK_STRAFE_H

#include "../State.h"
#include "../objects/AIObject.h"
#include <iostream>
#include <time.h>

//class Bird;

class StrafeandSeek: public State<AIObject>
{
private:
	StrafeandSeek(){}
	int seconds;
	//may need copy constructer, assignment operator and destructer here

public:
	static StrafeandSeek* Instance();

	virtual void Enter(AIObject* AI);
	virtual void Execute(AIObject* AI);
	virtual void Exit(AIObject* AI);


};



#endif