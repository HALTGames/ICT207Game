#include "GameObjManager.h"

GameObjVector GameObjManager::objects;

int GameObjManager::AddObject(ObjectEnum type)
{
	switch(type)
	{
	case OBJ_PLAYER:
		objects.push_back(new PlayerObj());
		break;
	case OBJ_TERRAIN:
		objects.push_back(new TerrainObj());
		break;
	case OBJ_RETICULE:
		objects.push_back(new ReticuleObj());
	}

	return objects.size() - 1;
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

void GameObjManager::Delete()
{
	for(CItrGameObj itr = objects.begin(); itr != objects.end(); ++itr)
	{
		RemoveObject(itr);
	}

	objects.clear();
}