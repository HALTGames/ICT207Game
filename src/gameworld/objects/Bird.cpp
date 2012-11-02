#include "Bird.h"
#include <math.h>

Bird::Bird()
{
	model.LoadModel("./models/bird.obj");
	//collidableType = "Player";
	position = Vector3(2.0, 0.0, 2.0);
	angle = 0.0;
	Health =20;
	MaxSpeed =0.09;
	ThisStateMachine = new StateMachine<AIObject>(this);
	ThisStateMachine->SetCurrentState(Seek::Instance());
	SetScale(1,1,1);
	AILookDirection.x = 1;
	AILookDirection.y = 0;
	AILookDirection.z = 0;
	//SetScaleSphere(0.0001);
	Damage = -10;
	


	
}


void Bird::Update(Vector3 PlayPos)
{
	//cout<<"update \n";
	//move somewhere
	//possibly generate random number that may change state

	//saves current position of player to the bird class so it can be accessed
	PlayerPos =PlayPos;
	ThisStateMachine->update();
	angle+=90;
	
	
	
}


Bird& Bird::operator=(const Bird &rhs)

{

   this->position = rhs.position;

   this->Health = rhs.Health;

   this->MaxSpeed = rhs.MaxSpeed;

   return *this;

}

 

int Bird::operator==(const Bird &rhs) const

{

   if( this->Health != rhs.Health) return 0;

  // if( this->y != rhs.y) return 0;

  //if( this->z != rhs.z) return 0;

  return 1;

}

 

// This function is required for built-in STL list functions like sort

int Bird::operator<(const Bird &rhs) const

{

//   if( this->x == rhs.x && this->y == rhs.y && this->z < rhs.z) return 1;

 //  if( this->x == rhs.x && this->y < rhs.y) return 1;

   if( this->Health < rhs.Health ) return 1;

   return 0;

}

