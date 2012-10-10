#include "Vector3.h"

//-----------------------------------------------------------------------------

const Vector3& Vector3::operator+=(const Vector3& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;

	return *this;
}

//-----------------------------------------------------------------------------

const Vector3& Vector3::operator-=(const Vector3& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;

	return *this;
}

//-----------------------------------------------------------------------------

bool Vector3::operator==(const Vector3& rhs) const
{
	return  x == rhs.x &&
			y == rhs.y &&
			z == rhs.z;
}

//-----------------------------------------------------------------------------

bool Vector3::operator!=(const Vector3& rhs) const
{
	return	x != rhs.x ||
			y != rhs.y ||
			z != rhs.z;
}

//-----------------------------------------------------------------------------

double Vector3::Length() const
{
	return sqrt((x*x) + (y*y) + (z*z));
}

//-----------------------------------------------------------------------------

Vector3& Vector3::Normalise() const
{
	double length = Length();

	return Vector3(x / length, y / length, z / length);
}

//-----------------------------------------------------------------------------

double Vector3::Dot(const Vector3& other) const
{
	return x * other.x + y * other.y + z * other.z;
}

//-----------------------------------------------------------------------------