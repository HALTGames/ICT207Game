#include "ProjectileObj.h"

ProjectileObj::ProjectileObj()
{
	ProjectileObj(0, 0, 10, 10);
}

ProjectileObj::ProjectileObj(double x1, double z1, double x2, double z2)
{
	model.LoadModel("./models/proj.obj");

	speed = 1.0;
	time = 1000; // lasts for 10 seconds

	double deltaX = x2 - x1;
	double deltaZ = z2 - z1;
	double len = sqrt(deltaX * deltaX + deltaZ * deltaZ);

	direction = Vector3((deltaX * speed)/ len, 0.0, (deltaZ * speed)/ len);
	currentPosition = Vector3(x1, 0.0, z1);

	startTime = glutGet(GLUT_ELAPSED_TIME);

	scale = 1.0;
}

ProjectileObj::~ProjectileObj()
{
}

void ProjectileObj::Display()
{
	currentPosition += direction;
	model.GetCollisionSphere()->SetCenter(currentPosition);
	
	glPushMatrix();
		glTranslatef(currentPosition.x, currentPosition.y, currentPosition.z);
		glScalef(scale, scale, scale);
		model.DrawModel();
	glPopMatrix();
}

Vector3 ProjectileObj::GetCurrentPosition()
{
	return currentPosition;
}

Vector3 ProjectileObj::GetDirection()
{
	return direction;
}

bool ProjectileObj::CheckTime()
{
	int currentTime = glutGet(GLUT_ELAPSED_TIME);

	return (currentTime - startTime > time);
}

void ProjectileObj::Scale(double factor)
{
	scale = factor;
	model.GetCollisionSphere()->ScaleSphere(scale);
}