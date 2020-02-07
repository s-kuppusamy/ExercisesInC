/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        //printf("%d\n", array[i]);
    }

    return 0;
}

//Q1:
// It is intended to create two arrays of size 5, one that has all elements
// equal to 42 and one that has each element being the index (0-4).
// The output should be the value of each element of the array created by
// calling foo on a new line (5 lines that say 42).

//Q2:
// The warning is 'function returns address of local variable.' Because it is
// returning an array, the warning message is saying that the function is
// actually returning the address of the array since for arrays, the arrays
// equals the address of the array. The intended output is the values stored
// in the array.

//Q3:
// I got two address outputs to the same address and then a segmentation fault.
// This is because the program is trying to access memory that it can't access.
// Array is a local variable, so the values or name of the variable
// is not stored beyond the function and thus is not availabe
// later when it is trying to be accessed. These addresses are only available
// within the scope of the function where it is printed.

//Q4:
// It no longer prints any addresses and only gives a segmentation fault.
// The reason for this is the same as above.

// If you comment out the print statement within main and not the ones in the
// function, then it prints 0x7ffde38359b0 and 0x7ffde38359b0.
