#pragma once

//-----------------------------------------------------------------------------

#include <math.h>

//-----------------------------------------------------------------------------

/**
 * A structure to represent 3D vectors.
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
};

//-----------------------------------------------------------------------------