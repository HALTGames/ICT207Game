#include "ProjectileObj.h"

//-----------------------------------------------------------------------------

ProjectileObj::ProjectileObj()
{
	ProjectileObj(0, 0, 10, 10);
}

//-----------------------------------------------------------------------------

ProjectileObj::ProjectileObj(double x1, double z1, double x2, double z2)
{
	model.LoadModel("./models/proj.obj");

	speed = 0.4;
	time = 1000; // lasts for 10 seconds

	double deltaX = x2 - x1;
	double deltaZ = z2 - z1;
	double len = sqrt(deltaX * deltaX + deltaZ * deltaZ);

	direction = Vector3((deltaX * speed)/ len, 0.0, (deltaZ * speed)/ len);
	position = Vector3(x1, 0.0, z1);

	startTime = glutGet(GLUT_ELAPSED_TIME);

	scale = 0.6;

	deleteObject = false;
}

//-----------------------------------------------------------------------------

void ProjectileObj::Display()
{
	position += direction;
	model.GetCollisionSphere()->SetCenter(position);

	if(CheckTime() || CheckCollision())
	{
		deleteObject = true;
	}
	
	glPushMatrix();
		GameObj::Display();
	glPopMatrix();
}

//-----------------------------------------------------------------------------

Vector3 ProjectileObj::GetCurrentPosition()
{
	return position;
}

//-----------------------------------------------------------------------------

Vector3 ProjectileObj::GetDirection()
{
	return direction;
}

//-----------------------------------------------------------------------------

bool ProjectileObj::CheckTime() const
{
	int currentTime = glutGet(GLUT_ELAPSED_TIME);

	return (currentTime - startTime > time);
}

//-----------------------------------------------------------------------------

bool ProjectileObj::CheckCollision()
{
	if(GameCollision::CollidesWith(this->model.GetCollisionSphere(), TERRAIN))
	{
		return true;
	}

	return false;
}

//-----------------------------------------------------------------------------
