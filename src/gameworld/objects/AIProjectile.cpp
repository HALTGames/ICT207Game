
#include "AIProjectile.h"






AIProjectile::AIProjectile(double x1, double z1, double x2, double z2)
{
	model.LoadModel("./models/proj.obj");
			
	speed = 1.0;
	time = 1000; // lasts for 10 seconds

	speed = 0.4;
	scale = 0.5;

	double deltaX = x2 - x1;
	double deltaZ = z2 - z1;
	double len = sqrt(deltaX * deltaX + deltaZ * deltaZ);

	direction = Vector3((deltaX * speed)/ len, 0.0, (deltaZ * speed)/ len);
	position = Vector3(x1, 0.0, z1);

	startTime = glutGet(GLUT_ELAPSED_TIME);

	scale = 0.6;

	deleteObject = false;
}


/*
	position = Vector3(x1, 0.0, z1);

	startTime = glutGet(GLUT_ELAPSED_TIME);


	deleteObject = false;
}*/


bool AIProjectile::CheckCollision()
{
	return false;

}

