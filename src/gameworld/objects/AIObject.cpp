#include "AIObject.h"

AIObject::AIObject()
{
	seconds = 0;
	GunSeconds = 0;
	checker = 0;
	AILookDirection.x = 1;
	AILookDirection.y = 0;
	AILookDirection.z = 0;
	soundcontroller.addSound("sounds/AISpell.mp3", "AISpell");
	
	
	
}

void AIObject::PickAIPos()
{
	RandomAI = rand() %4;
	switch(RandomAI)
	{
	case 0:
		{
	position.x = 60;
	position.y = 0;
	position.z = rand() %84-44;
	break;
		}
	case 1:
		{
	position.x = -60;
	position.y = 0;
	position.z = rand() %84-44;
	break;
		}
	case 2:
		{
	position.x = rand() %100-50;
	position.y = 0;
	position.z = 50;
	break;
		}
	case 3:
		{
	position.x = rand() %100-50;
	position.y = 0;
	position.z = -55;
	break;
		}
	}
}


void AIObject::TakeDamage()
{
	/*
	if(GameCollision::CollidesWith(this->model.GetCollisionSphere(), PLAYERPROJECTILE));
	{
		//Health-=10;
		//cout<<Health<< "   AI DAMAGE \n";
	}*/

}

void AIObject::DealDamage()
{

	Player.ModifyHealth(Damage);

}

double AIObject::GetMag(Vector3 pass)
{
	double tempmag;
	tempmag = sqrt((pass.x*pass.x)+(pass.y*pass.y)+(pass.z*pass.z));

	return tempmag;
}

void AIObject::SetAngle(Vector3 New, Vector3 other)
{
	
	temp = sqrt((New.x-other.x)*(New.x-other.x) + (New.y-other.y)*(New.y-other.y) + (New.z-other.z)*(New.z-other.z));
	Direction2.x = (New.x-other.x)/temp;
	Direction2.y = (New.y-other.y)/temp;
	Direction2.z = (New.z-other.z)/temp;

	
	temp = ((AILookDirection.x*Direction2.x)+(AILookDirection.y*Direction2.y)+(AILookDirection.z*Direction2.z));
	temp = (temp/1);   
	
	angle = -(acos(temp) * 57.2957795);
	if(Direction2.z < 0)
	{
		angle = -angle;
	}
}

void AIObject::SetVector(Vector3 New, Vector3 other)
{
	
	temp = sqrt((New.x-other.x)*(New.x-other.x) + (New.y-other.y)*(New.y-other.y) + (New.z-other.z)*(New.z-other.z));
	if(temp<CollDistance)
	{
		collision = true;
	}
	else 
	{
		collision = false;
	}
	
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
	
	ChangePosition(Direction);

}

bool AIObject::Collide()
{

	return collision;
	//return(GameCollision::CollidesWith(this->model.GetCollisionSphere(), PLAYER));
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
	//new ProjectileObj(position.x, position.z, Direction.x, Direction.z);
	ProjectileManager::AddProjectile(PROJECTILE, position.x, position.z, PlayerPos.x, PlayerPos.z);

	//cout<<"Firingmutherfucker!!!!!!!! \n";
}

void AIObject::ChangePosition(const Vector3 pos)
{
	Vector3 newPos = position + pos;
	model.GetCollisionSphere()->SetCenter(newPos);

	if(GameCollision::CollidesWith(this->model.GetCollisionSphere(), TERRAIN))
	{
		model.GetCollisionSphere()->SetCenter(position);
	}
	else
	{
		GameObj::ChangePosition(pos);
	}
}