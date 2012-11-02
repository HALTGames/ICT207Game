#pragma once

#include <vector>

#include "objects\ProjectileObj.h"
#include "objects\AIProjectile.h"

typedef std::vector<ProjectileObj*> ProjectileVector;
typedef ProjectileVector::iterator ItrProjectileVector;
typedef ProjectileVector::const_iterator CItrProjectileVector;

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
	static ProjectileVector projectiles;

	static void RemoveProjectileAt(CItrProjectileVector index);
};

