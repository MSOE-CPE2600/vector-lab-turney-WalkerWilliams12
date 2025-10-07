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

Vector add(Vector a, Vector b) {
    Vector r = {"", a.x + b.x, a.y + b.y, a.z + b.z, 1};
    return r;
}

Vector subtract(Vector a, Vector b) {
    Vector r = {"", a.x - b.x, a.y - b.y, a.z - b.z, 1};
    return r;
}

Vector scalar_multiply(Vector v, double scalar) {
    Vector r = {"", v.x * scalar, v.y * scalar, v.z * scalar, 1};
    return r;
}
