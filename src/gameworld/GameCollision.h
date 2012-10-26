#pragma once

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

//typedef list<GameObj*> gameObjList;
//typedef gameObjList::iterator ItrGameObj;
//typedef gameObjList::const_iterator CItrGameObj;

//typedef map<collidableType, gameObjList > collisionMap;
//typedef collisionMap::iterator ItrCollMap;
//typedef collisionMap::const_iterator CItrCollMap;

class GameCollision
{
public:
	GameCollision(void);
	~GameCollision(void);

	static bool AddCollidable(collidableType type, GameObj* obj);

	static bool CollidesWith(CollisionSphere* sphere, collidableType type);

	static bool RemoveCollidable(collidableType type, int objectNum);

private:
	//static collisionMap objCollision;

	static bool CheckCollision(CollisionSphere* sphere1, 
								CollisionSphere* sphere2);
};

