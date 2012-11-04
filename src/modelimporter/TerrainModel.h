#pragma once

#include "../Vector3.h"
#include "Model.h"

struct TriangleApprox
{
	Vector3 max;
	Vector3 min;
	int tr_index;
};

class TerrainModel :
	public Model
{
public:
	TerrainModel(void);

	virtual bool LoadModel(char* fileName);

	virtual bool DrawModel();

	void InitBox(TriangleApprox *b);

	void DefineTerrain();

	void DrawTerrain();

	bool IsOver(TriangleApprox *b, GLfloat x, GLfloat y, GLfloat z);

	bool IsOn(GLfloat x, GLfloat z);

	TriangleApprox *FindTerrainBox(float x, float y, float z);

	float CalculateTerrainCollisions(GLMmodel *model, float px, float py, float pz);

private:
	TriangleApprox* terrain[100000];
	int terrainIndex;
};