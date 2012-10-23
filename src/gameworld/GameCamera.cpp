#include "GameCamera.h"

GameCamera::GameCamera()
{
	m_height = 20;
	m_behind = 5;
}

bool GameCamera::SetHeight(double height)
{
	m_height = height;
}

bool GameCamera::SetBehind(double behind)
{
	m_behind = behind;
}

void GameCamera::Render(const Vector3 position)
{
	gluLookAt(position.x - m_behind, position.y + m_height, position.z, 
			position.x, position.y, position.z, 
			1.0, 0.0, 0.0);
}