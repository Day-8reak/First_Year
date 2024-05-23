#include <stdio.h>
#include <string.h>

int main () {


    int num1 = 10;
    int num2 = 20;
    char letter = 'A';
    char name [] = " John ";


    // Task 1
    printf (" Task 1: %d %d %c %s \n",num1, num2, letter, name);
    // Your Task 1 code goes here
    // Task 2
    num1 = 15;
    printf (" nTask 2: %d \n",num1);
    // Your Task 2 code goes here
    // Task 3
    char result[3];
    sprintf(result, "%c%d",letter, num2);
    printf (" nTask 3: %s\n", result);
    // Your Task 3 code goes here
    // Task 4
    int asciiLetter = (int)letter;

    printf (" nTask 4: %ld \n",letter);
    // Your Task 4 code goes here
}