/**
 * @file vector_data.c
 * @brief defines the functions for storing, clearing, finding and listing vectors
 * 
 * Course: CPE2600
 * Section: 111
 * Assignment: Lab 5
 * Name: Walker Williams
 * 
 * //Data is not storing more than one variable at a time right now.
 */
#include "vector.h"

#define MAX_VECTORS 10

static Vector vectors[MAX_VECTORS];

/**
 * @brief Clears vector from the array
 */
void clear_vectors() {
    for (int i = 0; i < MAX_VECTORS; i++)
        vectors[i].active = 0;
    printf("All vectors cleared.\n");
}

/**
* @brief Adds vectors into the array
* @param v - vector to add to the array
* @return 1 if the vector is added into the array
* @return 0 if the array is full and vector not added
*/
int add_vector(Vector v) {
    // Replace existing vector if same name found
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (vectors[i].active && strcmp(vectors[i].name, v.name) == 0) {
            vectors[i] = v;
            return 1;
        }
    }

    // find first empty slot
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (!vectors[i].active) {
            vectors[i] = v;
            vectors[i].active = 1;
            return 1;
        }
    }

    // if ther is no more free slots in array
    printf("Memory full. Cannot store new vector.\n");
    return 0;
}

/**
* @brief Finds if a vector is in the array
* @param name the name of the vector being serched for
* @return the address of the vector if it exists
* @return null if the vector does not exist
*/
Vector *find_vector(const char *name) {
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (vectors[i].active && strcmp(vectors[i].name, name) == 0)
            return &vectors[i];
    }
    return NULL;
}

/**
* @brief Lists all of the vectors currently saved in the array
*/
void list_vectors() {
    printf("Stored Vectors:\n");
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (vectors[i].active)
            printf("%s = (%.2f, %.2f, %.2f)\n",
                   vectors[i].name, vectors[i].x, vectors[i].y, vectors[i].z);
    }
}
