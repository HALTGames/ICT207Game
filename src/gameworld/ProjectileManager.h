#pragma once

#include <list>

#include "objects\ProjectileObj.h"
#include "objects\AIProjectile.h"

typedef std::list<ProjectileObj*> ProjectileList;
typedef ProjectileList::iterator ItrProjectileList;
typedef ProjectileList::const_iterator CItrProjectileList;

enum ProjectileEnum
{
	PROJECTILE,
	AIPROJECTILE
};

class ProjectileManager
{
public:
	static void AddProjectile(ProjectileEnum type, double startX, double startZ,
							double endX, double endZ);

	static void UpdateProjectiles();

private:
	static ProjectileList projectiles;

	static void RemoveProjectile(CItrProjectileList index);
};