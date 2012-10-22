#include "Alligator.h"
#include <math.h>




void Alligator::Update(Vector3 PlayPos)
{
	//move somewhere
	//possibly generate random number that may change state

	//saves current position of player to the bird class so it can be accessed
	PlayerPos = PlayPos;
	ThisStateMachine->update();
}

void Alligator::SetVector(Vector3 New)
{
	temp = sqrt (New.x*New.x + New.y*New.y + New.z*New.z);
	Direction.x = New.x/temp;
	Direction.y = New.y/temp;
	Direction.z = New.z/temp;

	Direction.x = Direction.x*MaxSpeed;
	Direction.y = Direction.y*MaxSpeed;
	Direction.z = Direction.z*MaxSpeed;

}

void  Alligator::Move()
{
	GameObj::position += Direction;
}