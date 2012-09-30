#pragma once
#include "model.h"
#include "Vector3.h"

struct BoundingBox
{
	Vector3 max;
	Vector3 min;
};

class GameModel :
	public Model
{
public:
	GameModel();

	~GameModel(void);

	bool Collision(GLfloat x, GLfloat y, GLfloat z);

	virtual bool LoadModel(char* fileName);

	virtual bool DrawModel();

	void DrawBox();

	bool CreateCollisionBox();
private:
	BoundingBox* box;

	void InitBoundingBox();
};

