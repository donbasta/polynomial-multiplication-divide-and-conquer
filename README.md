# polynomial-multiplication-divide-and-conquer

This project is written in C++ and is done to fulfill the task given in course IF2211 (Strategi Algoritma/Algorithm Strategy) in Institut Teknologi Bandung.

`bin` contains binary file.
`src` contains source code of polynomial library and main function.

## Compilation:

`g++ -o [BINARY_FILE_NAME] main.cpp Polinom.cpp`

## Description:

Basically, this project compares the running time of brute force polynomial multiplication and the other method, which uses divide and conquer (dnc) approach. Due to the slow nature of calling recursive function, which is required to break down the polynomials into smaller degree, the dnc algo somehow runs slower than the brute force one. 
