#include "Strafer.h"
#include <math.h>

Strafer::Strafer()
{
	model.LoadModel("./models/arrowman.obj");
	//collidableType = "Player";
	position = Vector3(2.0, 0.0, 2.0);
	angle = 0.0;
	Health =40;
	MaxSpeed =0.07;
	ThisStateMachine = new StateMachine<AIObject>(this);
	ThisStateMachine->SetCurrentState(StrafeandSeek::Instance());
	SetScale(10);
	PickAIPos();
	
}


void Strafer::Update(Vector3 PlayPos)
{
	//cout<<"update \n";
	//move somewhere
	//possibly generate random number that may change state

	//saves current position of player to the bird class so it can be accessed
	PlayerPos =PlayPos;
	
	
	ThisStateMachine->update();
	
	
	
}


Strafer& Strafer::operator=(const Strafer &rhs)

{

   this->position = rhs.position;

   this->Health = rhs.Health;

   this->MaxSpeed = rhs.MaxSpeed;

   return *this;

}

 

int Strafer::operator==(const Strafer &rhs) const

{

   if( this->Health != rhs.Health) return 0;

  // if( this->y != rhs.y) return 0;

  //if( this->z != rhs.z) return 0;

  return 1;

}

 

// This function is required for built-in STL list functions like sort

int Strafer::operator<(const Strafer &rhs) const

{

//   if( this->x == rhs.x && this->y == rhs.y && this->z < rhs.z) return 1;

 //  if( this->x == rhs.x && this->y < rhs.y) return 1;

   if( this->Health < rhs.Health ) return 1;

   return 0;

}