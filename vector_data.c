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
#include <stdlib.h>

/**
 * @brief Initializes vector storage
 */
void storage(Vector **vectors, int *capacity, int *count) {
    *capacity = INITIAL_CAPACITY;
    *count = 0;
    *vectors = malloc(*capacity * sizeof(Vector));
    if (*vectors == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    clear_vectors(*vectors, count);
}

/**
 * @brief Frees vector storage
 * @param vectors array to get vectors from
 * @param capacity current capacity of vectors
 * @param count number of vector in the array
 */
void free_storage(Vector **vectors, int *capacity, int *count) 
{
    if (*vectors != NULL) 
    {
        free(*vectors);
        *vectors = NULL;
    }
    *capacity = 0;
    *count = 0;
}

/**
 * @brief Clears vector from the array
 * @param vectors array to get vectors from
 * @param count number of vector in the array
 */
void clear_vectors(Vector *vectors, int *count) 
{
    for (int i = 0; i < *count; i++) 
    {
        vectors[i].active = 0;
    }
    *count = 0;
    printf("All vectors cleared.\n");
}


/**
* @brief Adds vectors into the array
* @param v - vector to add to the array
* @param vectors - dynamic array
* @param capacity - current capacity of vectors
* @param count - number of vector in the array
* @return 1 if the vector is added into the array
* @return 0 if the array is full and vector not added
*/
int add_vector(Vector v, Vector **vectors, int *capacity, int *count) {
    // Check if vector with same name exists and replace it
    for (int i = 0; i < *count; i++) {
        if ((*vectors)[i].active && strcmp((*vectors)[i].name, v.name) == 0) {
            (*vectors)[i] = v;
            return 1;
        }
    }
    
    // Check if capacity needs to be increased
    if (*count >= *capacity && *capacity < MAX_CAPACITY) {
        int new_capacity = (*capacity * 2 <= MAX_CAPACITY) ? (*capacity * 2) : MAX_CAPACITY;
        Vector *new_vectors = realloc(*vectors, new_capacity * sizeof(Vector));
        if (new_vectors == NULL) {
            printf("Failed to expand vector storage.\n");
            return 0;
        }
        *vectors = new_vectors;
        *capacity = new_capacity;
    }
    
    // Add new vector
    if (*count < *capacity) {
        (*vectors)[*count] = v;
        (*vectors)[*count].active = 1;
        (*count)++;
        return 1;
    }
    
    //If 52 vectors have been reached
    printf("Maximum amount of vectors reached. Cannot store new vector.\n");
    return 0;
}

/**
* @brief Finds if a vector is in the array
* @param name the name of the vector being serched for
* @param vectors array to get vectors from
* @param count number of vector in the array
* @return the address of the vector if it exists
* @return null if the vector does not exist
*/
Vector *find_vector(const char *name, Vector *vectors, int count) 
{
    for (int i = 0; i < count; i++) 
    {
        if (vectors[i].active && strcmp(vectors[i].name, name) == 0)
            return &vectors[i];
    }
    return NULL;
}

/**
* @brief Lists all of the vectors currently saved in the array
* @param vectors array to get vectors from
* @param count number of vector in the array
*/
void list_vectors(Vector *vectors, int count) {
    if (count == 0) {
        printf("No vectors stored.\n");
        return;
    }
    
    printf("Stored Vectors (%d total):\n", count);
    for (int i = 0; i < count; i++) {
        if (vectors[i].active)
            printf("%s = (%.2f, %.2f, %.2f)\n",
                   vectors[i].name, vectors[i].x, vectors[i].y, vectors[i].z);
    }
}

/**
 * @brief Loads vectors from CSV file
 * @param filename name of file to load from
 * @param vectors array to get vectors from
 * @param capacity current size of vectors
 * @param count number of vector in the array
 */
int load_vectors(const char *filename, Vector **vectors, int *capacity, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file '%s'\n", filename);
        return 0;
    }
    
    char line[256];
    int loaded = 0;
    
    while (fgets(line, sizeof(line), file)) {
        // Remove newline characters
        line[strcspn(line, "\r\n")] = 0;
        
        // Skip empty lines
        if (strlen(line) == 0) continue;
        
        char name[20];
        double x, y, z;
        
        // Parse CSV line
        if (sscanf(line, "%19[^,],%lf,%lf,%lf", name, &x, &y, &z) == 4) {
            Vector v = {"", x, y, z, 1};
            strcpy(v.name, name);
            
            if (add_vector(v, vectors, capacity, count)) {
                loaded++;
            }
        } else {
            printf("Warning: Skipping malformed line: %s\n", line);
        }
    }
    
    fclose(file);
    printf("Loaded %d vectors from '%s'\n", loaded, filename);
    return loaded;
}

/**
 * @brief Saves vectors to CSV file
 * @param filename name of file to save to
 * @param vectors array to get vectors from
 * @param count number of vector in the array
 */
int save_vectors(const char *filename, Vector *vectors, int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Cannot create file '%s'\n", filename);
        return 0;
    }
    
    int saved = 0;
    for (int i = 0; i < count; i++) {
        if (vectors[i].active) {
            fprintf(file, "%s,%.6f,%.6f,%.6f\n", 
                    vectors[i].name, vectors[i].x, vectors[i].y, vectors[i].z);
            saved++;
        }
    }
    
    fclose(file);
    printf("Saved %d vectors to '%s'\n", saved, filename);
    return saved;
}

