#include "ProjectileObj.h"


ProjectileObj::ProjectileObj(Vector3 strt, Vector3 end)
{
	speed = 1.0;
	length = 20.0;

	start = strt;
	position = strt;

	direction = end - strt;
	direction = direction.Normalise();

	beginTime = glutGet(GLUT_ELAPSED_TIME);
}

void ProjectileObj::Display()
{
	int timeDifference = (glutGet(GLUT_ELAPSED_TIME) - beginTime) / 1000;
	double speedTime = speed * timeDifference;

	position = direction * speedTime;

	double distanceTravelled = (position - start).Length();

	if(distanceTravelled < length)
	{
		GameObj::Display();
	}
	else
	{
		//destroy this object
	}
}