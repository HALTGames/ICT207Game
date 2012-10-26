#include "GameCollision.h"

//collisionMap objCollision;

GameCollision::GameCollision()
{
}

bool GameCollision::AddCollidable(collidableType type, GameObj* obj)
{
	//objCollision[type].push_back(obj);

	return true;
}

bool GameCollision::CollidesWith(CollisionSphere* sphere, collidableType type)
{
	bool collision = false;


	return collision;
}

bool GameCollision::RemoveCollidable(collidableType type, int objectNum)
{


	return true;
}

bool GameCollision::CheckCollision(CollisionSphere* sphere1, 
									CollisionSphere* sphere2)
{
	Vector3 distance = sphere1->center - sphere2->center;

	double sumRadius = sphere1->radius + sphere2->radius;

	return (distance.Length() < sumRadius);
}