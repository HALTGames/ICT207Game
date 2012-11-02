#include "ProjectileManager.h"

ProjectileVector ProjectileManager::projectiles;

void ProjectileManager::AddProjectile(ProjectileEnum type, double startX,
	double startZ, double endX, double endZ)
{
	switch(type)
	{
	case PROJECTILE:
		projectiles.push_back(new ProjectileObj(startX, startZ, endX, endZ));
		break;
	case AIPROJECTILE:
		break;
		//projectiles.push_back(new AIProjectile(startX, startZ, endX, endZ));
	}
}

void ProjectileManager::UpdateProjectiles()
{
	for(CItrProjectileVector itr = projectiles.begin(); 
		itr != projectiles.end(); ++itr)
	{
		if((*itr)->CheckTime())
		{
			RemoveProjectileAt(itr);
		}
		else
		{
			(*itr)->Display();
		}
	}
}

void ProjectileManager::RemoveProjectileAt(CItrProjectileVector index)
{
	delete *index;
	projectiles.erase(index);
}