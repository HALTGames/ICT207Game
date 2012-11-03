#include "GameCamera.h"

GameCamera::GameCamera()
{
	m_height = 40;
	m_behind = 5;
}

bool GameCamera::SetHeight(double height)
{
	if(height >= 0)
	{
		m_height = height;
		return true;
	}

	return false;
}

bool GameCamera::SetBehind(double behind)
{
	if(behind >= 0)
	{
		m_behind = behind;
		return true;
	}

	return false;
}

void GameCamera::Render(const Vector3 position)
{
	gluLookAt(position.x - m_behind, position.y + m_height, position.z, 
			position.x, position.y, position.z, 
			1.0, 0.0, 0.0);
}

bool GameCamera::ChangeHeight(double height)
{
	m_height += height;

	return true;
}

bool GameCamera::ChangeBehind(double behind)
{
	m_behind += behind;

	return true;
}