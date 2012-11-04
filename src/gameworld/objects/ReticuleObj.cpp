#include "ReticuleObj.h"


ReticuleObj::ReticuleObj(void)
{
	model.LoadModel("./models/reticule.obj");
}

void ReticuleObj::Display(void)
{
	GameObj::Display();
}