#pragma once

#include <map>

#include "GameObj.h"

typedef map<int, GameObj*> MapGameObj;
typedef MapGameObj::iterator ItrGameObj;
typedef MapGameObj::const_iterator CItrGameObj;

class GameObjManager
{
public:
	~GameObjManager(void);

	void AddObject(GameObj* obj);

	void UpdateObjects();

	void RemoveObject(int idnum);

	GameObj* GetObject(int idnum);
private:
	MapGameObj objects;
};

