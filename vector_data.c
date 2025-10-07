/**
 * @file vector_data.c
 * @brief defines the functions for storing, clearing, finding and listing vectors
 * 
 * Course: CPE2600
 * Section: 111
 * Assignment: Lab 5
 * Name: Walker Williams
 * 
 */
#include "vector.h"

static Vector vectors[MAX_VECTORS];

void clear_vectors() {
    for (int i = 0; i < MAX_VECTORS; i++)
        vectors[i].active = 0;
    printf("All vectors cleared.\n");
}

int add_vector(Vector v) {
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (vectors[i].active && strcmp(vectors[i].name, vectors[i].name) == 0) {
            vectors[i] = v;
            return 1;
        }
    }
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (!vectors[i].active) {
            vectors[i] = v;
            vectors[i].active = 1;
            return 1;
        }
    }
    printf("Memory full. Cannot store new vector.\n");
    return 0;
}

Vector *find_vector(const char *name) {
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (vectors[i].active && strcmp(vectors[i].name, name) == 0)
            return &vectors[i];
    }
    return NULL;
}

void list_vectors() {
    printf("Stored Vectors:\n");
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (vectors[i].active)
            printf("%s = (%.2f, %.2f, %.2f)\n",
                   vectors[i].name, vectors[i].x, vectors[i].y, vectors[i].z);
    }
}
