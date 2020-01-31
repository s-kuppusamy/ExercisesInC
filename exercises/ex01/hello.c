#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("%i\n",y); //need a format string to actually display the value.
    return 0;
}

// subq	$16, %rsp and movl	$5, -4(%rbp), lines 17-18, are the corresponding
// lines to int x = 5; I found this out by comparing the program with the new
// line and without to see what lines were added.

// When optimized, it becomes shorter and adds more stuff to the .LCO: part.

// it changes the string"" to %i\n from helloWorld!\n in .LCO:
// when optimized, it is shorter again and stores the value until printed (the
// line stays).

// It has the string "%i\n" in .LCO: section, and 	movl	-8(%rbp), %eax,
// addl	$1, %eax, and movl	%eax, -4(%rbp) are added to the assembly code.
// Again, the optimized code is shorter and more concise. It no longer stores
// the x value and merely has a line to add, 	addq	$8, %rsp. However, it does
//still stores the y value until printed.

// Optimization eliminates additional lines or values that aren't needed as
// soon as they are used. It gives the most necessary information only.
