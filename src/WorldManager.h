#pragma once

#include "World.h"

#include "shaysworld\ShaysWorld.h"
#include "gameworld\GameWorld.h"
#include "gamemenu\MenuWorld.h"

enum WorldEnum {
	SHAYSWORLD,
	GAMEWORLD,
	MENUWORLD
};


class WorldManager
{
public:
	WorldManager(void);
	~WorldManager(void);

	World* GetCurrentWorld() const;
	WorldEnum GetCurrentWorldEnum() const;

	void ChangeWorld(WorldEnum newWorld);
private:
	World* currentWorld;
	WorldEnum current;
};

