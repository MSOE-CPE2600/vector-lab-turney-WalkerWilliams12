/**
 * @file vector_main.c
 * @brief runs fake matlab vector program
 * 
 * Course: CPE2600
 * Section: 111
 * Assignment: Lab 5
 * Name: Walker Williams
 * 
 * Algorithm
 * -gets base of vector program form vector_info
 * -vector_info uses both vector_data and vector_math to handle vectors
 * -vector_math has all functions to operate with the vectors
 * -vector_data has all functions to handle the vector array
 * 
 * Compile: gcc -o minimat vector_main.c vector_math.c vector_data.c vector_info.c
 */
#include "vector.h"

/**
* @brief Runs vector calculator
* @param argc - not used
* @param argv - "-h" to print command list
* @return 0 to finish program
*/
//Main to run the entire program
int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "-h") == 0) 
    {
        display_help();
        return 0;
    }

    vector_program();
    return 0;
}
