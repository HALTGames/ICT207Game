#include "GameCamera.h"

void GameCamera::rotateX(double amount)
{
}

void GameCamera::rotateY(double amount)
{
	Vector3 target = m_target;
	Vector3 right = m_right;
 
	amount /= 57.2957795f;
 
	m_target.x = (cos(1.5708f + amount) * target.x) + (cos(amount) * right.x);
 
	m_target.y = (cos(1.5708f + amount) * target.y) + (cos(amount) * right.y);
 
	m_target.z = (cos(1.5708f + amount) * target.z) + (cos(amount) * right.z);
 
	m_right.x  = (cos(amount) * target.x) + (cos(1.5708f - amount) * right.x);
 
	m_right.y  = (cos(amount) * target.y) + (cos(1.5708f - amount) * right.y);
 
	m_right.z  = (cos(amount) * target.z) + (cos(1.5708f - amount) * right.z);
 
	m_target = m_target.Normalise();
	m_right = m_right.Normalise();
}

void GameCamera::rotateZ(double amount)
{

}

void GameCamera::moveForward(double amount)
{
	m_position += m_target.Normalise() * amount;
}

void GameCamera::moveLeft(double amount)
{
	m_position += m_right.Normalise() * -amount;
}

void GameCamera::moveRight(double amount)
{
	m_position += m_right.Normalise() * amount;
}

void GameCamera::SetTarget(Vector3 target)
{
	Vector3 projectedTarget;
	 
	target = target - m_position;
	projectedTarget = target;
		 
	if(fabs(target.x) < 0.00001 && fabs(target.z) < 0.00001) {  // YZ plane
	 
		projectedTarget.x = 0.0f;
		projectedTarget.Normalise();
		 
		m_right = Vector3(1.0, 0.0, 0.0);
		m_up = projectedTarget.Cross(m_right);
			 
		m_target = target;
		m_right = m_target.Cross(m_up);

		m_right = m_right * -1;
	}
		 
	else {                                      // XZ plane
			 
		projectedTarget.y = 0.0;
		projectedTarget.Normalise();
		 
		m_up = Vector3(0.0f, 1.0f, 0.0f);
		m_right = projectedTarget.Cross(m_up);
		m_right = m_right * -1;
	 
		m_target = target;
		m_up = m_target.Cross(m_right);
	}
	 
	m_target.Normalise();
	m_right.Normalise();
	m_up.Normalise();
}

void GameCamera::SetPosition(Vector3 position)
{
	m_position = position;
}

void GameCamera::SetUp(Vector3 up)
{
	m_up = up;
}