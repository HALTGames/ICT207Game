#include "GameObjManager.h"


GameObjManager::~GameObjManager(void)
{
	objects.clear();
}

void GameObjManager::AddObject(GameObj* obj)
{
	objects[obj->GetIdentificationNumber()] = obj;
}

void GameObjManager::UpdateObjects()
{
	for(CItrGameObj itr = objects.begin(); itr != objects.end(); itr++)
	{
		if((itr->second)->GetDeleteThis())
		{
			objects.erase(itr);
		}

		(itr->second)->Display();
	}
}

void GameObjManager::RemoveObject(int idnum)
{
	objects.erase(idnum);
}

GameObj* GameObjManager::GetObject(int idnum)
{
	return objects.at(idnum);
}