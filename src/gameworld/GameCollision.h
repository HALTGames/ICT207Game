#pragma once

#include <map>
#include <list>
#include "../modelimporter/GameModel.h"
#include "GameObj.h"

typedef enum collidableType {
	PLAYER,
	ENEMY,
	TERRAIN,
	ENEMYPROJECTILE,
	PLAYERPROJECTILE
};

using namespace std;

typedef map<collidableType, list<GameObj*> > collisionMap;


class GameCollision
{
public:
	GameCollision(void);
	~GameCollision(void);

	bool AddCollidable(collidableType type, GameObj* obj);

	bool CollidesWith(CollisionSphere* sphere, collidableType type);

	bool RemoveCollidable(collidableType type, int objectNum);
};

