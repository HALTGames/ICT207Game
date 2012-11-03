#include "Shooter.h"
#include <math.h>

Shooter::Shooter()
{
	model.LoadModel("./models/enemy.obj");
	//collidableType = "Player";
	position = Vector3(2.0, 0.0, 2.0);
	angle = 0.0;
	Health =30;
	MaxSpeed =0.12;
	ThisStateMachine = new StateMachine<AIObject>(this);
	ThisStateMachine->SetCurrentState(SeekandShoot::Instance());
	SetScale(1);
	PickAIPos();

	
}


void Shooter::Update(Vector3 PlayPos)
{
	//cout<<"update \n";
	//move somewhere
	//possibly generate random number that may change state

	//saves current position of player to the bird class so it can be accessed
	PlayerPos =PlayPos;
	
	
	ThisStateMachine->update();
	angle-=90;
	
	
	
}


Shooter& Shooter::operator=(const Shooter &rhs)

{

   this->position = rhs.position;

   this->Health = rhs.Health;

   this->MaxSpeed = rhs.MaxSpeed;

   return *this;

}

 

int Shooter::operator==(const Shooter &rhs) const

{

   if( this->Health != rhs.Health) return 0;

  // if( this->y != rhs.y) return 0;

  //if( this->z != rhs.z) return 0;

  return 1;

}

 

// This function is required for built-in STL list functions like sort

int Shooter::operator<(const Shooter &rhs) const

{

//   if( this->x == rhs.x && this->y == rhs.y && this->z < rhs.z) return 1;

 //  if( this->x == rhs.x && this->y < rhs.y) return 1;

   if( this->Health < rhs.Health ) return 1;

   return 0;

}