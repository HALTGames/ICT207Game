#include "WorldManager.h"

WorldManager::WorldManager(void)
{
	currentWorld = new GameWorld();
}

WorldManager::~WorldManager(void)
{
	delete currentWorld;
	currentWorld = NULL;
}

World* WorldManager::GetCurrentWorld() const
{
	return currentWorld;
}

WorldEnum WorldManager::GetCurrentWorldEnum() const
{
	return current;
}

void WorldManager::ChangeWorld(WorldEnum newWorld)
{
	delete currentWorld;
	currentWorld = NULL;

	switch (newWorld) {
		case SHAYSWORLD:
			{
			currentWorld = new ShaysWorld();
			break;
			}
		case GAMEWORLD:
			{
			currentWorld = new GameWorld();
			break;
			}
	}

	currentWorld->Init();
}