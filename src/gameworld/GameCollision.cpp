#include "GameCollision.h"

//-----------------------------------------------------------------------------

collisionMap GameCollision::objCollision;

//-----------------------------------------------------------------------------

void GameCollision::AddCollidable(collidableType type, GameObj* obj)
{
	objCollision[type].push_back(obj);
}

//-----------------------------------------------------------------------------

bool GameCollision::CollidesWith(CollisionSphere* sphere, collidableType type)
{
	bool collision = false;

	for(CItrObjList itr = objCollision[type].begin(); itr != objCollision[type].end(); itr++)
	{
		if((*itr)->GetCollisionSphere() == sphere) {}
		else {

			if(CheckCollision((*itr)->GetCollisionSphere(), sphere))
			{
				collision = true;
			}
		}
	}

	return collision;
}

//-----------------------------------------------------------------------------

bool GameCollision::CheckCollision(CollisionSphere* sphere1, 
									CollisionSphere* sphere2)
{
	Vector3 distance = sphere1->center - sphere2->center;

	double sumRadius = sphere1->radius + sphere2->radius;

	return (distance.Length() <= sumRadius);
}

//-----------------------------------------------------------------------------