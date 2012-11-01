#include "TerrainModel.h"

//-----------------------------------------------------------------------------

TerrainModel::TerrainModel(void)
{
	terrainIndex = 0;
}


bool TerrainModel::LoadModel(char* fileName)
{
	Model::LoadModel(fileName);

	DefineTerrain();

	return true;
}

bool TerrainModel::DrawModel()
{
	Model::DrawModel();

	//DrawTerrain();

	return true;
}

void TerrainModel::InitBox(TriangleApprox *b)
{
	b->min.x = 100000;
	b->min.y = 100000;
	b->min.z = 100000;

	b->max.x = -100000;
	b->max.y = -100000;
	b->max.z = -100000;
}

void TerrainModel::DefineTerrain()
{
	for(int i = 0; i < mod->numtriangles; i++)
	{
		TriangleApprox* tri = new TriangleApprox;
		InitBox(tri);

		GLfloat x = mod->triangles[i].vindices[0];
		GLfloat y = mod->triangles[i].vindices[1];
		GLfloat z = mod->triangles[i].vindices[2];

		if (tri->min.x>x) tri->min.x = x;
		if (tri->min.y>y) tri->min.y = y;
		if (tri->min.z>z) tri->min.z = z;

		if (tri->max.x<x) tri->max.x = x;
		if (tri->max.y<y) tri->max.y = y;
		if (tri->max.z<z) tri->max.z = z;

		tri->tr_index = i;
		terrain[terrainIndex++] = tri;
	}
}

void TerrainModel::DrawTerrain()
{
	glLineWidth(5);

	glColor4f(1.0, 0.0, 0.0, 1.0);

	for(int i = 0; i < terrainIndex; i++)
	{

		glBegin (GL_LINE_LOOP); 
		glVertex3f(terrain[i]->max.x, terrain[i]->max.y, terrain[i]->min.z); // 0
		glVertex3f(terrain[i]->min.x, terrain[i]->max.y, terrain[i]->min.z); // 1
		glVertex3f(terrain[i]->min.x, terrain[i]->min.y, terrain[i]->min.z); // 2
		glVertex3f(terrain[i]->max.x, terrain[i]->min.y, terrain[i]->min.z); // 3
		glEnd();

		glBegin (GL_LINE_LOOP); 
		glVertex3f(terrain[i]->max.x, terrain[i]->min.y, terrain[i]->max.z); // 4
		glVertex3f(terrain[i]->max.x, terrain[i]->max.y, terrain[i]->max.z); // 5
		glVertex3f(terrain[i]->min.x, terrain[i]->max.y, terrain[i]->max.z); // 6
		glVertex3f(terrain[i]->min.x, terrain[i]->min.y, terrain[i]->max.z); // 7
		glEnd();

		glBegin (GL_LINE_LOOP); 
		glVertex3f(terrain[i]->max.x, terrain[i]->max.y, terrain[i]->min.z); // 0
		glVertex3f(terrain[i]->max.x, terrain[i]->max.y, terrain[i]->max.z); // 5
		glVertex3f(terrain[i]->min.x, terrain[i]->max.y, terrain[i]->max.z); // 6
		glVertex3f(terrain[i]->min.x, terrain[i]->max.y, terrain[i]->min.z); // 1
		glEnd();

		glBegin (GL_LINE_LOOP); 
		glVertex3f(terrain[i]->max.x, terrain[i]->min.y, terrain[i]->max.z); // 4
		glVertex3f(terrain[i]->min.x, terrain[i]->min.y, terrain[i]->max.z); // 7
		glVertex3f(terrain[i]->min.x, terrain[i]->min.y, terrain[i]->min.z); // 2 
		glVertex3f(terrain[i]->max.x, terrain[i]->min.y, terrain[i]->min.z); // 3

		glEnd();

	}

	glColor4f(1.0, 1.0, 1.0, 1.0);
}

bool TerrainModel::IsOver(TriangleApprox *b,GLfloat x, GLfloat y, GLfloat z)
{
	return x <= b->max.x && x >= b->min.x &&
		z <= b->max.z && z >= b->min.z;
}

TriangleApprox* TerrainModel::FindTerrainBox(float x, float y, float z)
{
	for(int i = 0; i < terrainIndex; i++)
	{
		if(IsOver(terrain[i], x, y, z))
		{
			return terrain[i];
		}
	}

	return 0;
}

float TerrainModel::CalculateTerrainCollisions(GLMmodel *model, float px, float py, float pz)
{
	int y = -300;

	TriangleApprox *b = FindTerrainBox(px, y, pz);

	if(!b) return -1000000; //point is not on map

	int index = model->triangles[b->tr_index].vindices[0];

	float x1 = model->vertices[index*3+0];
	float y1 = model->vertices[index*3+1];
	float z1 = model->vertices[index*3+2];

	index = model->triangles[b->tr_index].vindices[1];
	float x2 = model->vertices[index*3+0];
	float y2 = model->vertices[index*3+1];
	float z2 = model->vertices[index*3+2];

	index = model->triangles[b->tr_index].vindices[2];
	float x3 = model->vertices[index*3+0];
	float y3 = model->vertices[index*3+1];
	float z3 = model->vertices[index*3+2];

	// calculate the plane using the equation Ax + By + Cz + D = 0
	float A = y1 *(z2 - z3) + y2 *(z3 - z1) + y3 *(z1 - z2);
	float B = z1 *(x2 - x3) + z2 *(x3 - x1) + z3 *(x1 - x2);
	float C = x1 *(y2 - y3) + x2 *(y3 - y1) + x3 *(y1 - y2);
	float D = -(x1 *(y2* z3 - y3* z2) + x2 *(y3* z1 - y1* z3) + x3 *(y1 *z2 - y2 *z1)); 

	if (B==0) B=0.1;

	return (D+A*px+C*pz)/B; //height_of_character - (D+A*px+C*pz)/B;
}