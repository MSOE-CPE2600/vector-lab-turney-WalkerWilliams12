/**
 * @file vector.h
 * @brief creates the prototypes for all the c files and stuct for the vector
 * 
 * Course: CPE2600
 * Section: 111
 * Assignment: Lab 5
 * Name: Walker Williams
 * 
 */
#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Inital array capacity
#define INITIAL_CAPACITY 10
// Max size of array for A-Z, a-z name system
#define MAX_CAPACITY 52

/**
 * @brief - creates a vector with a x, y, and z variable values
 * @property x - x magnitude of the vector
 * @property y - y magnitude of the vector
 * @property z - z magnitude of the vector
 * @property active - if the vector is being saved or deleted out of the array
 */
typedef struct {
    char name[20];
    double x, y, z;
    int active;
} Vector;

void storage(Vector **vectors, int *capacity, int *count);
void free_storage(Vector **vectors, int *capacity, int *count);
int load_vectors(const char *filename, Vector **vectors, int *capacity, int *count);
int save_vectors(const char *filename, Vector *vectors, int count);

Vector add(Vector a, Vector b);
Vector subtract(Vector a, Vector b);
Vector scalar_multiply(Vector v, double scalar);

void clear_vectors(Vector *vectors, int *count);
int add_vector(Vector v, Vector **vectors, int *capacity, int *count);
Vector *find_vector(const char *name, Vector *vectors, int count);
void list_vectors(Vector *vectors, int count);

void vector_program();
void display_help();

#endif

