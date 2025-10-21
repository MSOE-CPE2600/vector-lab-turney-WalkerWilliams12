/**
 * @file vector_math.c
 * @brief defines all the math functions for vectors
 * 
 * Course: CPE2600
 * Section: 111
 * Assignment: Lab 5
 * Name: Walker Williams
 * 
 */
#include "vector.h"

/**
 * @brief Adds 2 vectors together
 * @param a - first vector to add to
 * @param b - second vector to add magnitudes to vector a
 * @return the resulting vector from adding a and b
 */
Vector add(Vector a, Vector b) 
{
    Vector r = {"", a.x + b.x, a.y + b.y, a.z + b.z, 1};
    return r;
}

/**
 * @brief Subtracts one vector from another
 * @param a - the initial vector to be subtracted from
 * @param b - the vector values to subtract from a
 * @return the resulting vector from subtracting b from a
 */
Vector subtract(Vector a, Vector b) 
{
    Vector r = {"", a.x - b.x, a.y - b.y, a.z - b.z, 1};
    return r;
}

/**
 * @brief Multiplies a vector by a scalar value
 * @param v - vector to multiply
 * @param scalar - value to multiply v by
 * @return the resulting vector from multiplying v by the scalar
 */
Vector scalar_multiply(Vector v, double scalar) 
{
    Vector r = {"", v.x * scalar, v.y * scalar, v.z * scalar, 1};
    return r;
}
