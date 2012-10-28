#include "AIObject.h"

AIObject::AIObject()
{
}


void AIObject::SetVector(Vector3 New, Vector3 other)
{
	//cout<<<<"\n";
	//cout<<New.y-other.y<<"\n";
	//cout<<New.z-other.z<<"\n";
	temp = sqrt((New.x-other.x)*(New.x-other.x) + (New.y-other.y)*(New.y-other.y) + (New.z-other.z)*(New.z-other.z));
	
	
	Direction.x = (New.x-other.x)/temp;
	Direction.y = (New.y-other.y)/temp;
	Direction.z = (New.z-other.z)/temp;

	Direction.x = Direction.x*MaxSpeed;
	Direction.y = Direction.y*MaxSpeed;
	Direction.z = Direction.z*MaxSpeed;

	

	
}

void  AIObject::Move()
{
	//cout<< Direction.x<<"    Move \n";
	//ChangePosition(Direction);
//	position.x = position.x + Direction.x;
//	position.y = position.y + Direction.y;
//	position.z = position.z + Direction.z;
	//position += Direction;aaa
}

Vector3 AIObject::GetDirection()
{
	return Direction;
}
Vector3 AIObject::GetPlayerPos()
{
	return PlayerPos;
}