#include "TerrainObj.h"

//-----------------------------------------------------------------------------

TerrainObj::TerrainObj()
{	
	SetPosition(Vector3(-27.2, 0.0, -14.2));
	model.GetCollisionSphere()->ScaleSphere(11.2);

	GameCollision::AddCollidable(TERRAIN, this);
}

//-----------------------------------------------------------------------------

void TerrainObj::Display()
{
	glPushMatrix();
	GameObj::Display();
	glPopMatrix();
}