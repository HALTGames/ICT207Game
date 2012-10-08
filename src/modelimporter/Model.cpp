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
	if(!mod)
	{
		mod = glmReadOBJ(fileName);

		glmUnitize(mod);

		glmFacetNormals(mod); 
		glmVertexNormals(mod, 90.0);

		return true;
	}

	// model with this name has already been loaded
	return false;
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