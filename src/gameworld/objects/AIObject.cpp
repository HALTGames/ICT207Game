#include "AIObject.h"

AIObject::AIObject()
{
	seconds = 0;
	GunSeconds = 0;
}


void AIObject::SetVector(Vector3 New, Vector3 other)
{
	//cout<<<<"\n";
	//cout<<New.y-other.y<<"\n";
	//cout<<New.z-other.z<<"\n";
	temp = sqrt((New.x-other.x)*(New.x-other.x) + (New.y-other.y)*(New.y-other.y) + (New.z-other.z)*(New.z-other.z));
	
	if(temp>0.1)
	{
	Direction.x = (New.x-other.x)/temp;
	Direction.y = (New.y-other.y)/temp;
	Direction.z = (New.z-other.z)/temp;

	Direction.x = Direction.x*MaxSpeed;
	Direction.y = Direction.y*MaxSpeed;
	Direction.z = Direction.z*MaxSpeed;
	}
	else
	{
		Direction.x = 0;
		Direction.y = 0;
		Direction.z = 0;
	}

	
	

	
}

void  AIObject::Move()
{
	//cout<< Direction.x<<"    Move \n";
	ChangePosition(Direction);
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

AIObject& AIObject::operator=(const AIObject &rhs)

{

   this->position = rhs.position;

   this->Health = rhs.Health;

   this->MaxSpeed = rhs.MaxSpeed;

   return *this;

}

 

int AIObject::operator==(const AIObject &rhs) const

{

   if( this->Health != rhs.Health) return 0;

  // if( this->y != rhs.y) return 0;

  //if( this->z != rhs.z) return 0;

  return 1;

}

 

// This function is required for built-in STL list functions like sort

int AIObject::operator<(const AIObject &rhs) const

{

//   if( this->x == rhs.x && this->y == rhs.y && this->z < rhs.z) return 1;

 //  if( this->x == rhs.x && this->y < rhs.y) return 1;

   if( this->Health < rhs.Health ) return 1;

   return 0;

}

void AIObject::SubtractHealth(int minus)
{
	Health -= minus;
}

int AIObject::GetHealth()
{
	return Health;
}

double AIObject::GetDistanceFrom()
{
	temp = sqrt((PlayerPos.x-position.x)*(PlayerPos.x-position.x) + (PlayerPos.y-position.y)*(PlayerPos.y-position.y) + (PlayerPos.z-position.z)*(PlayerPos.z-position.z));
	return temp;
	/*
	if(temp<0.5)
		return true;
	else 
		return false;*/
}

void AIObject::Fire()
{
	cout<<"FIRING \n";
}