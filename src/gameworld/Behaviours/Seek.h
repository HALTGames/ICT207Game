#ifndef SEEK_H
#define SEEK_H

#include "../State.h"
#include "../objects/AIObject.h"
#include <iostream>

//class Bird;

class Seek: public State<AIObject>
{
private:
	Seek(){}
	//may need copy constructer, assignment operator and destructer here

public:
	static Seek* Instance();

	virtual void Enter(AIObject* AI);
	virtual void Execute(AIObject* AI);
	virtual void Exit(AIObject* AI);


};



#endif