#include "Alligator.h"
#include <math.h>

Alligator::Alligator()
{
	model.LoadModel("./models/Ghost.obj");
	//collidableType = "Player";
	position = Vector3(2.0, 0.0, 2.0);
	angle = 0.0;
	Health =100;
	MaxSpeed =0.06;
	ThisStateMachine = new StateMachine<AIObject>(this);
	ThisStateMachine->SetCurrentState(Seek::Instance());
	SetScale(3);
	Damage = -50;
	PickAIPos();
	CollDistance = 3;
	
}


void Alligator::Update(Vector3 PlayPos)
{
	
	PlayerPos =PlayPos;
	ThisStateMachine->update();
<<<<<<< HEAD
	
	angle+=90;
	
=======
		
>>>>>>> d4d29de0091d14b8330358b3f9d5ac8b7d7fb78f
}


Alligator& Alligator::operator=(const Alligator &rhs)

{

   this->position = rhs.position;

   this->Health = rhs.Health;

   this->MaxSpeed = rhs.MaxSpeed;

   return *this;

}

 

int Alligator::operator==(const Alligator &rhs) const

{

   if( this->Health != rhs.Health) return 0;

  // if( this->y != rhs.y) return 0;

  //if( this->z != rhs.z) return 0;

  return 1;

}

 

// This function is required for built-in STL list functions like sort

int Alligator::operator<(const Alligator &rhs) const

{

//   if( this->x == rhs.x && this->y == rhs.y && this->z < rhs.z) return 1;

 //  if( this->x == rhs.x && this->y < rhs.y) return 1;

   if( this->Health < rhs.Health ) return 1;

   return 0;

}