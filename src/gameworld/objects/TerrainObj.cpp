#include "TerrainObj.h"

TerrainObj::TerrainObj()
{	
	SetPosition(Vector3(-25.0, 0.0, -14.0));
	model.GetCollisionSphere()->ScaleSphere(13.0);

	GameCollision::AddCollidable(TERRAIN, this);
}

void TerrainObj::Display()
{
	glPushMatrix();
	GameObj::Display();
	glPopMatrix();
}