#include "GameCamera.h"

//-----------------------------------------------------------------------------

GameCamera::GameCamera()
{
	height = 30;
	behind = 7;
}

//-----------------------------------------------------------------------------

bool GameCamera::SetHeight(const double hght)
{
	if(height >= 0)
	{
		height = hght;
		return true;
	}

	return false;
}

//-----------------------------------------------------------------------------

bool GameCamera::SetBehind(const double bhnd)
{
	if(behind >= 0)
	{
		behind = bhnd;
		return true;
	}

	return false;
}

//-----------------------------------------------------------------------------

void GameCamera::Render(const Vector3 position) const
{
	gluLookAt(position.x - behind, position.y + height, position.z, 
			position.x, position.y, position.z, 
			1.0, 0.0, 0.0);
}

//-----------------------------------------------------------------------------

void GameCamera::ChangeHeight(const double hght)
{
	height += hght;
}

//-----------------------------------------------------------------------------

void GameCamera::ChangeBehind(const double bhnd)
{
	behind += bhnd;
}

//-----------------------------------------------------------------------------