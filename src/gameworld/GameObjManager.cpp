#include "GameObjManager.h"

MapGameObj GameObjManager::objects;

void GameObjManager::Exit(void)
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
			delete (itr->second);
			objects.erase(itr);
		}

		(itr->second)->Display();
	}
}

void GameObjManager::RemoveObject(int idnum)
{
	delete objects.at(idnum);
	objects.erase(idnum);
}

GameObj* GameObjManager::GetObject(int idnum)
{
	return objects.at(idnum);
}