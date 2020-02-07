/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void print_address(int var){ // function to print address of local variable
  printf ("Address of var is %p\n", &var);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    char *s = "Hello, World";
    void *q = malloc(50); // adds another call to malloc
    void *t = malloc (6);
    void *u = malloc(6);


    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    print_address(var2); // calls function to print address of var2
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);
    printf ("q points to %p\n", q);
    printf ("t points to %p\n", t);
    printf ("u points to %p\n", u);

    return 0;
}

//Q1:
//picture is included in the folder


//Q4:
//yes, it grows up toward larger addresses. The new variable q, where
//malloc is called again, is in the same area of memory but is at a slightly
//larger address. If you call realloc for the same variable p, the heap
//does not grow toward larger addresses because p is a pointer and the
//place it points remains the same, only the value changes.

//Q5:
//yes, the stack grows down when it is printed by calling the function vs.
//when it is printed from within main().

//Q6:
//0x20 is how much space there is between the two.
