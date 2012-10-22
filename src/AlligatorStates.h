#ifndef BIRD_STATES_H
#define BIRD_STATES_H

#include "GameWorld/State.h"
#include <iostream>

class Alligator;

class AlligatorSeek: public State<Alligator>
{
private:
	AlligatorSeek(){}
	//may need copy constructer, assignment operator and destructer here

public:
	static AlligatorSeek* Instance();

	virtual void Enter(Alligator* alligator);
	virtual void Execute(Alligator* alligator);
	virtual void Exit(Alligator* alligator);


};



#endif