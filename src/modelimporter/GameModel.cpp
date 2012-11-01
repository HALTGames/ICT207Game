#include "GameModel.h"

//-----------------------------------------------------------------------------

GameModel::GameModel()
{
	sphere = new CollisionSphere(Vector3(0, 0, 0), 1);

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
	glLineWidth(2);

	glColor4f(1.0, 1.0, 1.0, 1.0);
	
	glPushMatrix();
		glTranslatef(0, 0, 0);
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
		if(minz > z) minz = z;
		if(miny > y) miny = y;

		if(maxx < x) maxx = x;
		if(maxy < y) maxy = y;
		if(maxz < z) maxz = z;
	}

	std::cout << minx << std::endl;
	std::cout << miny << std::endl;
	std::cout << minz << std::endl;
	std::cout << maxx << std::endl;
	std::cout << maxy << std::endl;
	std::cout << maxz << std::endl;

	double average = ((maxx - minx) + (maxy - miny) + (maxz - minz)) / 3;

	std::cout << "Average: " << average << std::endl;

	sphere->radius = average;

	std::cout << "Radius: " << sphere->radius << std::endl;

	return true;
}

//-----------------------------------------------------------------------------

CollisionSphere* GameModel::GetCollisionSphere()
{
	return sphere;
}