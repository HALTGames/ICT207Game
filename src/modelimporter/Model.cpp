#include "Model.h"

//-----------------------------------------------------------------------------

Model::Model(void)
{
	mod = new GLMmodel;
	mod = NULL;
}

//-----------------------------------------------------------------------------

Model::Model(char* fileName)
{
	mod = new GLMmodel;
	mod = NULL;

	LoadModel(fileName);
}

//-----------------------------------------------------------------------------

Model::~Model(void)
{
	delete mod;
	mod = NULL;
}

//-----------------------------------------------------------------------------

bool Model::LoadModel(char* fileName)
{
	if(mod)
	{
		delete mod;
		mod = NULL;

		mod = new GLMmodel;
		mod = NULL;
	}

	mod = glmReadOBJ(fileName);

	glmUnitize(mod);

	glmFacetNormals(mod); 
	glmVertexNormals(mod, 90.0);

	return true;
}

//-----------------------------------------------------------------------------

bool Model::DrawModel()
{
	if(!mod)
	{
		// model has not been loaded
		return false;
	}

	glmDraw(mod, GLM_SMOOTH | GLM_TEXTURE);

	return true;
}

//-----------------------------------------------------------------------------