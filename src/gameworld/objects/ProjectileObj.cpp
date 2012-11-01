#include "ProjectileObj.h"


ProjectileObj::ProjectileObj(double x1, double z1, double x2, double z2)
{
	model.LoadModel("./models/proj.obj");

	speed = 1.0;

	movement = Vector3(x2 - x1, 0.0, z2 - z1).Normalise();
	//movement = movement * speed;

	SetPosition(Vector3(x1, 0.0, z1));

	length = 20.0;
}

void ProjectileObj::Display()
{
	ChangePosition(movement);
	GameObj::Display();
}