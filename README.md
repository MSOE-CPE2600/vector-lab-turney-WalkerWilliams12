*************************************************************************************************************************
README File: Lab 5 - Vector Calculator 
*************************************************************************************************************************
    A)  This program will be like a C version of MatLab by taking in vector inputs from the user and preformaning 
        operations on the vectors that the user chooses. There will be a storage of 10 vectors in the program which allows the user to perform the operations of vector addition and subtraction, and scaler multiplication. The program also needs to be able to clear the storage so the user can add new vector, otherwise if full the new vector input will not be saved. There should be a command 'help' to show all of the availible commands in the program, list: shows all vectors, clear: clears vectors, quit: ends program. 

    B)  Create a struct named Vector for the vector element that has 3 compents for the x,y,z values. Make a static a
        static array with a set size of 10 for the storage of the vectors along with the prototypes for all of the nessary opperations, calculations and formatting of the vectors, make a main file that bring all of the code together and runs the program with all of the described requirements. 
    
    C)  The program can be compiled by using:
            Command Line: gcc -o vector_main vector_main.c vector_math.c vector_info.c vector_data.c
                          ./vector_main
            Makefile: make 
                      ./vector_main
        
    D)  Commands supported by the program:
            var = x y z        | create vector
            var1 + var2        | add vectors
            var1 - var2        | subtract vectors
            var * num          | scalar multiply
            result = a + b     | assign result
            list, clear, quit  | manage program
            

