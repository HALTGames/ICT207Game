#include "GameCollision.h"

GameCollision::GameCollision()
{
}

bool GameCollision::AddCollidable(collidableType type, GameObj* obj)
{
	return true;
}

bool GameCollision::CollidesWith(CollisionSphere* sphere, collidableType type)
{
	return true;
}

bool GameCollision::RemoveCollidable(collidableType type, int objectNum)
{
	return true;
}