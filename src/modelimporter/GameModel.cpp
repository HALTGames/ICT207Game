#include "GameModel.h"


GameModel::GameModel()
{
	box = (BoundingBox*)malloc(sizeof(BoundingBox));

	InitBoundingBox();
}


GameModel::~GameModel(void)
{
}

bool GameModel::LoadModel(char* fileName)
{
	Model::LoadModel(fileName);

	CreateCollisionBox();

	return true;
}

bool GameModel::DrawModel()
{
	DrawBox();

	return Model::DrawModel();	
}

void GameModel::InitBoundingBox()
{
	box->min.x = 1000000;
	box->min.y = 1000000;
	box->min.z = 1000000;

	box->max.x = -1000000;
	box->max.y = -1000000;
	box->max.z = -1000000;
}

void GameModel::DrawBox()
{
	glLineWidth(5);

	glColor4f(1.0, 0.0, 0.0, 1.0);

	glBegin (GL_LINE_LOOP); 
	glVertex3f(box->max.x, box->max.y, box->min.z); // 0
	glVertex3f(box->min.x, box->max.y, box->min.z); // 1
	glVertex3f(box->min.x, box->min.y, box->min.z); // 2
	glVertex3f(box->max.x, box->min.y, box->min.z); // 3
	glEnd();

	glBegin (GL_LINE_LOOP); 
	glVertex3f(box->max.x, box->min.y, box->max.z); // 4
	glVertex3f(box->max.x, box->max.y, box->max.z); // 5
	glVertex3f(box->min.x, box->max.y, box->max.z); // 6
	glVertex3f(box->min.x, box->min.y, box->max.z); // 7
	glEnd();

	glBegin (GL_LINE_LOOP); 
	glVertex3f(box->max.x, box->max.y, box->min.z); // 0
	glVertex3f(box->max.x, box->max.y, box->max.z); // 5
	glVertex3f(box->min.x, box->max.y, box->max.z); // 6
	glVertex3f(box->min.x, box->max.y, box->min.z); // 1
	glEnd();

	glBegin (GL_LINE_LOOP); 
	glVertex3f(box->max.x, box->min.y, box->max.z); // 4
	glVertex3f(box->min.x, box->min.y, box->max.z); // 7
	glVertex3f(box->min.x, box->min.y, box->min.z); // 2 
	glVertex3f(box->max.x, box->min.y, box->min.z); // 3

	glEnd();

	glColor4f(1.0, 1.0, 1.0, 1.0);
}

bool GameModel::CreateCollisionBox()
{
	for(int i = 0; i < mod->numvertices; i++)
	{		
		GLfloat x = mod->vertices[i * 3 + 0];
		GLfloat y = mod->vertices[i * 3 + 1];
		GLfloat z = mod->vertices[i * 3 + 2];

		if(box->min.x > x) box->min.x = x;
		if(box->min.y > y) box->min.y = y;
		if(box->min.z > z) box->min.z = z;

		if(box->max.x < x) box->max.x = x;
		if(box->max.y < y) box->max.y = y;
		if(box->max.z < z) box->max.z = z;
	}
	return true;
}