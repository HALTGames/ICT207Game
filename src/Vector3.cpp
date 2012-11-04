#include "Vector3.h"

void Vector3::Set( const double X, const double Y, const double Z)
{
	x = X;
	y = Y;
	z = Z;
}

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
const Vector3 Vector3::operator-(const Vector3& rhs)
{
	Vector3 Vec;

	Vec.x = x-rhs.x;
	Vec.y = y-rhs.y;
	Vec.z = z-rhs.z;

	return Vec;

}

const Vector3 Vector3::operator+(const Vector3 &other)
{
	Vector3 vec;

	vec.x = x + other.x;
	vec.y = y + other.y;
	vec.z = z + other.z;

	return vec;
}

const Vector3 Vector3::operator*(const double scalar)
{
	Vector3 vec;

	vec.x = x * scalar;
	vec.y = y * scalar;
	vec.z = z * scalar;

	return vec;
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

Vector3 Vector3::Cross(const Vector3& other) const
{
	Vector3 crossProduct;

	crossProduct.x = y * other.z - z * other.y;
	crossProduct.y = z * other.x - x * other.z;
	crossProduct.z = x * other.y - y * other.x;

	return crossProduct;
}