# Lab 7 – Vector Calculator Updates

## Overview
This project extends the **Vector Calculator** program by adding two major features:
1. The ability to **load and save vectors** to and from files.
2. Support for **dynamic memory allocation**, allowing the program to store an “unlimited” number of vectors (up to 52, corresponding to variable names `a–z` and `A–Z`).

---

## Description
Building on the code from **Lab 5**, this version introduces dynamic memory so that the calculator can store more than 10 vectors.  

The program can now:
- Automatically reallocate memory as more vectors are created.
- Save vector data to a `.csv` file for viewing in applications like Excel.
- Load vector data from existing files.

---

## Dynamic memory usage
This program utilizes dynamic memory by using a dynamic array to store the vector of the program instead of the 
original size of 10, and everytime that the current size of the array is full, the array reallocs to twice the original
size to accommadate more vectors while there is still availible memory space or there are still availible names for 
vectors availible to be assigned.

---

## Commands supported by the program
- var = x y z        | create vector
- var1 + var2        | add vectors
- var1 - var2        | subtract vectors
- var * num          | scalar multiply
- result = a + b     | assign result
- load <file>        | load vectors from CSV file
- save <file>        | save vectors to CSV file
- list, clear, quit  | manage program

---

## Compilation and Execution

### Command Line
```bash
gcc -o vector_main vector_main.c vector_math.c vector_info.c vector_data.c
./vector_main

