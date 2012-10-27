#include "TerrainObj.h"

TerrainObj::TerrainObj()
{
	model.LoadModel("./models/billboard.obj");
	position = Vector3(0.0, 0.0, 0.0);
	angle = 0.0;

	GameCollision::AddCollidable(TERRAIN, this);
}

void TerrainObj::Display()
{
	glPushMatrix();
	GameObj::Display();
	glPopMatrix();
}