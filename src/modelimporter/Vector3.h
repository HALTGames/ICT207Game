#pragma once

struct Vector3
{
	double x;
	double y;
	double z;

	Vector3():x(0.0), y(0.0), z(0.0) {}
	Vector3(double X, double Y, double Z):x(X), y(Y), z(Z) {}

	double Length() const;

	void Normalise();
};

