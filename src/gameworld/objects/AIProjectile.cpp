#include "AIProjectile.h"

AIProjectile::AIProjectile(double x1, double z1, double x2, double z2)
{

	model.LoadModel("./models/proj.obj");

	speed = 0.4;
	SetScale(0.5,0.5,0.5);
	double deltaX = x2 - x1;
	double deltaZ = z2 - z1;
	double len = sqrt(deltaX * deltaX + deltaZ * deltaZ);

	movement = Vector3((deltaX * speed)/ len, 0.0, (deltaZ * speed)/ len);

	SetPosition(Vector3(x1, 0.0, z1));

	startTime = glutGet(GLUT_ELAPSED_TIME);
	length = 20.0;
}

