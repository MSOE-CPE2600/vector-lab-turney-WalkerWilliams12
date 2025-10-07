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

#define MAX_VECTORS 10

typedef struct {
    char name[20];
    double x, y, z;
    int active;
} Vector;

// ===== vector_math.c =====
Vector add(Vector a, Vector b);
Vector subtract(Vector a, Vector b);
Vector scalar_multiply(Vector v, double scalar);

// ===== vector_store.c =====
void clear_vectors();
int add_vector(Vector v);
Vector *find_vector(const char *name);
void list_vectors();

// ===== vector_ui.c =====
void run_ui();
void display_help();

#endif
