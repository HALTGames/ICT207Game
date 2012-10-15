#ifndef BIRD_STATES_H
#define BIRD_STATES_H

#include "State.h"
#include <iostream>

class Bird;

class Seek: public State<Bird>
{
private:
	Seek(){}
	//may need copy constructer, assignment operator and destructer here

public:
	static Seek* Instance();

	virtual void Enter(Bird* bird);
	virtual void Execute(Bird* bird);
	virtual void Exit(Bird* bird);


};



#endif