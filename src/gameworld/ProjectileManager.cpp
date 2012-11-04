#include "ProjectileManager.h"

//-----------------------------------------------------------------------------

ProjectileList ProjectileManager::projectiles;

//-----------------------------------------------------------------------------

ProjectileList ProjectileManager::GetList()
{
	return projectiles;
}

//-----------------------------------------------------------------------------


void ProjectileManager::AddProjectile(ProjectileEnum type, double startX,
	double startZ, double endX, double endZ)
{
	switch(type)
	{
	case PROJECTILE:
		projectiles.push_back(new ProjectileObj(startX, startZ, endX, endZ));
		break;
	case AIPROJECTILE:
		//projectiles.push_back(new AIProjectile(startX, startZ, endX, endZ));
		break;
	case PLAYER_PROJECTILE:
		{
		projectiles.push_back(new PlayerProj(startX, startZ, endX, endZ));
		
		break;
		}
	}
}

//-----------------------------------------------------------------------------

void ProjectileManager::UpdateProjectiles()
{
	for(CItrProjectileList itr = projectiles.begin(); 
		itr != projectiles.end(); ++itr)
	{
		if((*itr)->GetDeleteObject())
		{
			RemoveProjectile(itr);
			
		}
		else
		{
			(*itr)->Display();
		}
	}
}

//-----------------------------------------------------------------------------

Vector3 ProjectileManager::GetCurrentPosition(CItrProjectileList index)
{
	return (*index)->GetPosition();
}

//-----------------------------------------------------------------------------

int ProjectileManager::GetNumProjectiles()
{
	return projectiles.size();
}

//-----------------------------------------------------------------------------

void ProjectileManager::RemoveProjectile(CItrProjectileList index)
{
	delete *index;
	projectiles.erase(index);
}

//-----------------------------------------------------------------------------