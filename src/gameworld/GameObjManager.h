#pragma once

#include <vector>

#include "GameObj.h"

// Objects
#include "objects\PlayerObj.h"
#include "objects\TerrainObj.h"
#include "objects\ReticuleObj.h"

typedef std::vector<GameObj*> GameObjVector;
typedef GameObjVector::iterator ItrGameObj;
typedef GameObjVector::const_iterator CItrGameObj;

enum ObjectEnum
{
	OBJ_PLAYER,
	OBJ_TERRAIN,
	OBJ_RETICULE
};

class GameObjManager
{
public:
	static int AddObject(ObjectEnum type);

	static GameObj* GetObject(int idnum);

	static void UpdateObjects();

	static void RemoveObject(int idnum);
	static void RemoveObject(CItrGameObj index);

	static void Delete();
private:
	static GameObjVector objects;
};

