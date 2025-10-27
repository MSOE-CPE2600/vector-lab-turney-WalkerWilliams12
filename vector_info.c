/**
 * @file vector_info.c
 * @brief defines functions to show vectors on the console and run the program
 * 
 * Course: CPE2600
 * Section: 111
 * Assignment: Lab 5
 * Name: Walker Williams
 * 
 */
#include "vector.h"

/**
* @brief Prints the vector information
* @param name - name of the vector
* @param v - vector for data access
*/
static void display_vector(const char *name, Vector v) {
    printf("%s = (%.2f, %.2f, %.2f)\n", name, v.x, v.y, v.z);
}

/**
* @brief checks if input is a number
* @param s string input from user
* @return if input was number or not
*/
static int is_number(const char *s) {
    char *end;
    strtod(s, &end);
    return *end == '\0';
}

/**
* @brief function that runs the entire base of the vector calculator
*/
void vector_program() {
    char input[100];
    printf("Welcome to MiniMat Vector Calculator.\nType 'help' for commands.\n");
    
    // Initialize dynamic array
    Vector *vectors = NULL;
    int capacity = 0;
    int count = 0;
    storage(&vectors, &capacity, &count);

    while (1) {
        printf("minimat> ");
        if (!fgets(input, sizeof(input), stdin)) break;

        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "quit") == 0) break;
        if (strcmp(input, "help") == 0) { display_help(); continue; }
        if (strcmp(input, "clear") == 0) { clear_vectors(vectors, &count); continue; }
        if (strcmp(input, "list") == 0) { list_vectors(vectors, count); continue; }

        // File operations
        char cmd[10], filename[100];
        if (sscanf(input, "%s %s", cmd, filename) == 2) {
            if (strcmp(cmd, "load") == 0) {
                load_vectors(filename, &vectors, &capacity, &count);
                continue;
            } else if (strcmp(cmd, "save") == 0) {
                save_vectors(filename, vectors, count);
                continue;
            }
        }

        // Vector assignment
        char var1[20], op[5], var2[20], var3[20];
        double a, b, c;
        if (sscanf(input, "%s = %lf %lf %lf", var1, &a, &b, &c) == 4 ||
            sscanf(input, "%s = %lf,%lf,%lf", var1, &a, &b, &c) == 4) {
            Vector v = {"", a, b, c, 1};
            strcpy(v.name, var1);
            if (add_vector(v, &vectors, &capacity, &count)) {
                display_vector(v.name, v);
            }
            continue;
        }

        // Operation with assignment (c = a + b)
        if (sscanf(input, "%s = %s %s %s", var1, var2, op, var3) == 4) {
            Vector *v1 = find_vector(var2, vectors, count);
            Vector *v2 = find_vector(var3, vectors, count);
            if (!v1 || !v2) { printf("Error: Unknown vector.\n"); continue; }
            Vector result;
            if (strcmp(op, "+") == 0) result = add(*v1, *v2);
            else if (strcmp(op, "-") == 0) result = subtract(*v1, *v2);
            else { printf("Unknown operator.\n"); continue; }
            strcpy(result.name, var1);
            if (add_vector(result, &vectors, &capacity, &count)) {
                display_vector(result.name, result);
            }
            continue;
        }

        // Simple operations without assignment (a + b)
        if (sscanf(input, "%s %s %s", var1, op, var2) == 3) {
            Vector *v1 = find_vector(var1, vectors, count);
            Vector *v2 = find_vector(var2, vectors, count);
            if (v1 && v2) {
                Vector res;
                if (strcmp(op, "+") == 0) res = add(*v1, *v2);
                else if (strcmp(op, "-") == 0) res = subtract(*v1, *v2);
                else { printf("Unknown operator.\n"); continue; }
                display_vector("ans", res);
            } else if (v1 && is_number(var2) && strcmp(op, "*") == 0) {
                Vector res = scalar_multiply(*v1, atof(var2));
                display_vector("ans", res);
            } else if (is_number(var1) && v2 && strcmp(op, "*") == 0) {
                Vector res = scalar_multiply(*v2, atof(var1));
                display_vector("ans", res);
            } else {
                printf("Invalid operation.\n");
            }
            continue;
        }

        // Display single vector
        Vector *v = find_vector(input, vectors, count);
        if (v) {
            display_vector(v->name, *v);
            continue;
        }

        printf("Invalid command. Type 'help' for list of commands.\n");
    }

    // Free memory
    free_storage(&vectors, &capacity, &count);
    printf("Goodbye!\n");
}

/**
* @brief Prints list of commands to be used in program
*/
void display_help() {
    printf("Commands:\n");
    printf("  var = x y z        | create vector\n");
    printf("  var1 + var2        | add vectors\n");
    printf("  var1 - var2        | subtract vectors\n");
    printf("  var * num          | scalar multiply\n");
    printf("  result = a + b     | assign result\n");
    printf("  load <file>        | load vectors from CSV file\n");
    printf("  save <file>        | save vectors to CSV file\n");
    printf("  list, clear, quit  | manage program\n");
}