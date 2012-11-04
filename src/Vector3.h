#pragma once

//-----------------------------------------------------------------------------

#include <cmath>

//-----------------------------------------------------------------------------

/**
 * \file Vector3.h Vector3.cpp
 * \class Vector3 struct
 * \brief A structure to represent 3D vectors.
 *
 * Sets up a vector with 3 components x, y and z.
 *
 * \author Timothy Veletta, Arran Ford
 * \date 08/10/12
 * \version 01 - Timothy Veletta, 08/10/12
 *		Created initial version with constructors, +=, -= operators and the dot
 *		product and length functions.
 * \version 02 - Arran Ford, 15/10/12
 *		Added +, -, == and != operators.
 * \version 03 - Timothy Veletta, 23/10/12
 *		Added Cross product function.
 */
struct Vector3
{
	double x; /**< the x component */
	double y; /**< the y component */
	double z; /**< the z component */

	/**
	 * \brief The default constructor.
	 *
	 * Initialises the vector to zero.
	 */
	Vector3():x(0.0), y(0.0), z(0.0) {}

	/**
	 * \brief Sets the vector.
	 *
	 *  Sets the x, y and z components of the vector.
	 *
	 * \param X	the x component
	 * \param Y the y component
	 * \param Z the z component
	 */
	Vector3(const double X, const double Y, const double Z):x(X), y(Y), z(Z) {}

	/**
	 * \brief Copy constructor.
	 *
	 *  Copies the input Vector3 to this one.
	 *
	 * \param other the vector to copy from
	 */
	Vector3(const Vector3& other):x(other.x), y(other.y), z(other.z) {}

	/**
	 * \brief Assignment operator.
	 *
	 * Assigns the values for x, y and z in the input vector to the current
	 * vector.
	 *
	 * \other the vector to assign from
	 * \retval a reference to this
	 */
	Vector3& operator=(const Vector3& other);

	/**
	 * \brief Sets the vector.
	 *
	 *  Sets the x, y and z components of the vector.
	 *
	 * \param X	the x component
	 * \param Y the y component
	 * \param Z the z component
	 */
	void Set(const double X, const double Y, const double Z);

	/**
	 * \brief Adds two vectors.
	 *
	 * Adds two vectors together.
	 *
	 * \param rhs the other vector to add
	 * \retval the sum of the two vectors
	 */
	const Vector3& operator+=(const Vector3& rhs);

	/**
	 * \brief Subtracts two vectors.
	 *
	 * Subtracts two vectors from each other
	 *
	 * \param rhs the other vector to subtract
	 * \retval the result of subtracting the two vectors
	 */
	const Vector3& operator-=(const Vector3& rhs);

	/**
	 * \brief Subtracts two vectors.
	 *
	 * Subtracts two vectors from each other
	 * overloads only the minus operator, not combined with equals
	 *
	 * \param rhs the other vector to subtract
	 * \retval the result of subtracting the two vectors
	 */
	const Vector3 operator-(const Vector3& rhs);

	/**
	 * \brief Adds two vectors.
	 *
	 * Adds two vectors together using component-wise addition. i.e. x
	 * component of this vector gets added to x component of the other vector.
	 *
	 * \param rhs the other vector to add
	 * \retval the result of adding the two vectors
	 */
	const Vector3 operator+(const Vector3 &other);

	/**
	 * \brief Multiplies a vector.
	 *
	 * Multiplies a vector with a scalar.
	 *
	 * \param scalar the amount to multiply the vector by
	 * \retval the result of scaling the vector
	 */
	const Vector3 operator*(const double scalar);

	/**
	 * \brief Equlity operator.
	 *
	 * Returns whether or not the two vectors are equal.
	 * 
	 * \param rhs the vector to compare with
	 * \retval whether or not the two vectors are equal
	 */
	bool operator==(const Vector3& rhs) const;

	/**
	 * \brief Inequality operator.
	 *
	 * Returns whether or not the two vectors are not equal
	 *
	 * \param rhs the vector to compare with
	 * \retval whether or not the two vectors are not equal
	 */
	bool operator!=(const Vector3& rhs) const;

	/**
	 * \brief Returns the length of the vector.
	 *
	 * Returns the length of the vector as a scalar value.
	 *
	 * \retval the scalar length of the vector
	 */
	double Length() const;

	/**
	 * \brief Normalises the vector.
	 *
	 * Returns the normalised unit vector of this vector.
	 *
	 * \retval the normalised unit vector
	 */
	Vector3& Normalise() const;

	/**
	 * \brief The dot product.
	 *
	 * Returns the scalar dot product of this vector and an input vector.
	 *
	 * \param other the other vector 
	 * \retval the scalar dot product of the two vectors
	 */
	double Dot(const Vector3& other) const;

	/**
	 * \brief The cross product.
	 *
	 * Returns the result of the vector cross product between this vector
	 * and the input vector.
	 *
	 * \param other the other vector
	 * \retval the vector cross product of the two vectors
	 */
	Vector3 Cross(const Vector3& other) const;
};

//-----------------------------------------------------------------------------