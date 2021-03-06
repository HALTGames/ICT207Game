#include "PlayerProj.h"

PlayerProj::PlayerProj(double x1, double z1, double x2, double z2)
{
	model.LoadModel("./models/proj.obj");

	speed = 0.5;
	time = 1000; // lasts for 10 seconds

	double deltaX = x2 - x1;
	double deltaZ = z2 - z1;
	double len = sqrt(deltaX * deltaX + deltaZ * deltaZ);

	direction = Vector3((deltaX * speed)/ len, 0.0, (deltaZ * speed)/ len);
	position = Vector3(x1, 0.0, z1);

	startTime = glutGet(GLUT_ELAPSED_TIME);

	scale = 0.6;

	deleteObject = false;

	//GameCollision::AddCollidable(PLAYERPROJECTILE, this);
}

bool PlayerProj::CheckCollision()
{
	return false;
}