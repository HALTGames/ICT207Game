#include "Bird.h"
#include <math.h>




void Bird::Update(Vector3 PlayPos)
{
	//move somewhere
	//possibly generate random number that may change state

	//saves current position of player to the bird class so it can be accessed
	PlayerPos =PlayPos;
	ThisStateMachine->update();
}


