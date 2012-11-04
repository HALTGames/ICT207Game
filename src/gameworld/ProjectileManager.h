#pragma once

#include <list>

#include "objects\ProjectileObj.h"
#include "objects\AIProjectile.h"
#include "objects\PlayerProj.h"

typedef std::list<ProjectileObj*> ProjectileList;
typedef ProjectileList::iterator ItrProjectileList;
typedef ProjectileList::const_iterator CItrProjectileList;

enum ProjectileEnum
{
	PROJECTILE,
	AIPROJECTILE,
	PLAYER_PROJECTILE
};

class ProjectileManager
{
public:
	static void AddProjectile(ProjectileEnum type, double startX, double startZ,
							double endX, double endZ);

	static void UpdateProjectiles();

	static Vector3 GetCurrentPosition(CItrProjectileList index);

	static int GetNumProjectiles();

	static ProjectileList projectiles; 

	static ProjectileList GetList();
private:
	

	static void RemoveProjectile(CItrProjectileList index);
};