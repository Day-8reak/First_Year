#include <stdio.h>
#include "pmath.h"
#include <stdlib.h>

void add(int* num1, int* num2, int* res){
    *res = *num1 + *num2;
}

void multiply(int* num1, int* num2, int* res){
    *res = *num1 * *num2;
}

void absolute(int* num){
    *num = abs(*num);
}
