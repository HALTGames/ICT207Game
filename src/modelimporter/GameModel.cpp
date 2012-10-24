#include "GameModel.h"

//-----------------------------------------------------------------------------

GameModel::GameModel()
{
	sphere = new CollisionSphere();

	Model::Model();
}

//-----------------------------------------------------------------------------

GameModel::~GameModel(void)
{
	delete sphere;
	sphere = NULL;

	Model::~Model();
}

//-----------------------------------------------------------------------------

bool GameModel::LoadModel(char* fileName)
{
	Model::LoadModel(fileName);

	return CreateCollisionSphere();
}

//-----------------------------------------------------------------------------

bool GameModel::DrawModel()
{
	DrawSphere();

	return Model::DrawModel();	
}

//-----------------------------------------------------------------------------

void GameModel::DrawSphere()
{
	glLineWidth(5);

	glColor4f(1.0, 0.0, 0.0, 1.0);
	
	glPushMatrix();
		glTranslatef(sphere->center.x, sphere->center.y, sphere->center.z);
		glutWireSphere(sphere->radius, 8, 8);
	glPopMatrix();
}

//-----------------------------------------------------------------------------

bool GameModel::CreateCollisionSphere()
{
	double minx, miny, minz = 1000000;
	double maxx, maxy, maxz = -1000000;

	for(int i = 0; i < mod->numvertices; i++)
	{		
		GLfloat x = mod->vertices[i * 3 + 0];
		GLfloat y = mod->vertices[i * 3 + 1];
		GLfloat z = mod->vertices[i * 3 + 2];

		if(minx > x) minx = x;
		if(miny > y) miny = y;
		if(minz > z) minz = z;

		if(maxx < x) maxx = x;
		if(maxy < y) maxy = y;
		if(maxz < z) maxz = z;
	}

	double average = ((maxx - minx) + (maxy - miny) + (maxz - minz)) / 3;

	sphere->radius = average;

	return true;
}

//-----------------------------------------------------------------------------