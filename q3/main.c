/*3. Mini Math Module using Pointers and Make (Patrick, 1 point)
Create a module called pmath.h comprised of three functions for adding, multiplying, and
taking the absolute value of a number.
- void add(int* num1, int* num2, int* res)
- void multiply(int* num1, int* num2, int* res)
- void absolute(int* num)
Have these functions called in main.c and create a Makefile that compiles the pmath.c
and main.c files and produces an output file. All of the object files should be automatically
stored in a build folder. The make clean command should remove the build folder and the
output file. Below is the main function you can use to support your answer.*/

#include <stdio.h>
#include <stdlib.h>
#include "pmath.h"


/* Do later:
1. figure out what to put in main
2. finish makefile

*/

int main() {
    
    // starting values
    int a = 2;
    int b = 5;
    int c = 0;
    int d = -10;
    
    
    add (&a, &b, &c);
    printf ("The value of c after adding is %d\n", c);
    multiply (&a, &b, &c);
    printf ("The value of c after multiplying is %d\n", c);
    printf ("The value of d before taking the absolute value %d\n", d);
    absolute (&d);
    printf ("The value of d after taking the absolute value %d\n", d);
    return 0;


}