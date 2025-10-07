/**
 * @file vector_main.c
 * @brief runs fake matlab vector program
 * 
 * Course: CPE2600
 * Section: 111
 * Assignment: Lab 5
 * Name: Walker Williams
 * 
 * 
 * Compile: gcc -o minimat vector_main.c vector_math.c vector_data.c vector_info.c
 */
#include "vector.h"

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "-h") == 0) {
        display_help();
        return 0;
    }

    run_ui();
    return 0;
}
