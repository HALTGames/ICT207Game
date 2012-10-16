#ifndef BIRD_STATES_H
#define BIRD_STATES_H

#include "State.h"
#include <iostream>

class Bird;

class BirdSeek: public State<Bird>
{
private:
	BirdSeek(){}
	//may need copy constructer, assignment operator and destructer here

public:
	static BirdSeek* Instance();

	virtual void Enter(Bird* bird);
	virtual void Execute(Bird* bird);
	virtual void Exit(Bird* bird);


};



#endif