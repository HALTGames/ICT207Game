#include "GameObjManager.h"

GameObjVector GameObjManager::objects;

int GameObjManager::AddObject(ObjectEnum type)
{
	switch(type)
	{
	case PLAYER:
		objects.push_back(new PlayerObj());
		break;
	case TERRAIN:
		objects.push_back(new TerrainObj());
		break;
	}
}

GameObj* GameObjManager::GetObject(int idnum)
{
	return objects[idnum];
}

void GameObjManager::UpdateObjects()
{
	for(CItrGameObj itr = objects.begin(); itr != objects.end(); itr++)
	{
		if((*itr)->GetDeleteThis())
		{
			RemoveObject(itr);
		}
		else
		{
			(*itr)->Display();
		}
	}
}

void GameObjManager::RemoveObject(int idnum)
{
	delete objects[idnum];
	objects[idnum] = NULL;
}

void GameObjManager::RemoveObject(CItrGameObj index)
{
	delete *index;
	objects.erase(index);
}