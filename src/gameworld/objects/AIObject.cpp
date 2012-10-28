#include "AIObject.h"



void AIObject::SetVector(Vector3 New)
{
	temp = sqrt (New.x*New.x + New.y*New.y + New.z*New.z);
	Direction.x = New.x/temp;
	Direction.y = New.y/temp;
	Direction.z = New.z/temp;

	Direction.x = Direction.x*MaxSpeed;
	Direction.y = Direction.y*MaxSpeed;
	Direction.z = Direction.z*MaxSpeed;

}

void  AIObject::Move()
{
	GameObj::position += Direction;
}