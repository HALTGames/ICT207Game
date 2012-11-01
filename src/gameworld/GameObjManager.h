#pragma once

#include <map>

#include "GameObj.h"

typedef map<int, GameObj*> MapGameObj;
typedef MapGameObj::iterator ItrGameObj;
typedef MapGameObj::const_iterator CItrGameObj;

class GameObjManager
{
public:
	static void Exit(void);

	static void AddObject(GameObj* obj);

	static void UpdateObjects();

	static void RemoveObject(int idnum);

	static GameObj* GetObject(int idnum);
private:
	static MapGameObj objects;
};

