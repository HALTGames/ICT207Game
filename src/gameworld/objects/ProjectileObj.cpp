#include "ProjectileObj.h"


ProjectileObj::ProjectileObj(double x1, double z1, double x2, double z2)
{
	model.LoadModel("./models/proj.obj");

	speed = 1.0;

	double deltaX = x2 - x1;
	double deltaZ = z2 - z1;
	double len = sqrt(deltaX * deltaX + deltaZ * deltaZ);

	movement = Vector3((deltaX * speed)/ len, 0.0, (deltaZ * speed)/ len);

	SetPosition(Vector3(x1, 0.0, z1));

	startTime = glutGet(GLUT_ELAPSED_TIME);
	length = 20.0;
}

void ProjectileObj::Display()
{
	double deltaTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	Vector3 len = movement * deltaTime;
	if(len.Length() < length){}

	ChangePosition(movement);
	GameObj::Display();

}