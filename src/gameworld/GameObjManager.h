#pragma once

#include <vector>

#include "GameObj.h"

// Objects
#include "objects\PlayerObj.h"
#include "objects\TerrainObj.h"

typedef std::vector<GameObj*> GameObjVector;
typedef GameObjVector::iterator ItrGameObj;
typedef GameObjVector::const_iterator CItrGameObj;

enum ObjectEnum
{
	PLAYER,
	TERRAIN,
};

class GameObjManager
{
public:

	static int AddObject(ObjectEnum type);

	static GameObj* GetObject(int idnum);

	static void UpdateObjects();

	static void RemoveObject(int idnum);
	static void RemoveObject(CItrGameObj index);
private:
	static GameObjVector objects;
};

