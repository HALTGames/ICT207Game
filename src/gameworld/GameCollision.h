#pragma once

#include <iostream>
#include <map>
#include <list>
#include "../modelimporter/GameModel.h"
#include "GameObj.h"

using namespace std;

typedef enum collidableType {
	PLAYER,
	ENEMY,
	TERRAIN,
	ENEMYPROJECTILE,
	PLAYERPROJECTILE
};

typedef list<GameObj*> objList;
typedef objList::iterator ItrObjList;
typedef objList::const_iterator CItrObjList;

typedef map<collidableType, objList > collisionMap;
typedef collisionMap::iterator ItrCollMap;
typedef collisionMap::const_iterator CItrCollMap;

class GameCollision
{
public:
	GameCollision(void);
	~GameCollision(void);

	static bool AddCollidable(collidableType type, GameObj* obj);

	static bool CollidesWith(CollisionSphere* sphere, collidableType type);

	static bool RemoveCollidable(collidableType type, int objectNum);

private:
	static collisionMap objCollision;

	static bool CheckCollision(CollisionSphere* sphere1, 
								CollisionSphere* sphere2);
};

