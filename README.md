*********************************************
README File: Lab 7 - VectorCalculator Updates
*********************************************
    A)  This project will add two features to your vector calculator program - the ability to load and
        save vectors to and from files, and the ability to store “unlimited” vectors through the use
        of dynamic memory.

    B)  Using the code from Lab 5, you will be chaning that memory portion of the code so that the program
        can store more than 10 vectors (will max out at 52 when names a-z, A-Z), and also code into the main program 
        file creation and export the vector data into an .csv file to view from Excel.
    
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
    
    E)  This program utilizes dynamic memory by using a dynamic array to store the vector of the program instead of the 
        original size of 10, and everytime that the current size of the array is full, the array reallocs to twice the original
        size to accommadate more vectors while there is still availible memory space or there are still availible names for 
        vectors availible to be assigned.

