#include <stdio.h>
#include <stdbool.h> // import for bool


// Code : Here include your necessary library(s)
// Code : Write your global variables here, like:
#define N 9

int count = 0;

/* Code: Write your functions here, or the declaration of the head/
For example write the recursive function solveSudoku(), like:
*/


void printGrid(int arr[N][N])
{
    int i;
    
	for(i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
        {
            printf("%d ", arr[i][j]);
            
            if (j % 3 == 2 && j != 0)
            {
                printf("| ");
            }
        }
        printf("\n----------------------- \n");
	}
}

bool solveSudoku(int gridS[N][N])
{
    count = count + 1;
    return false;
    // Code: count + 1, the number of times the function was called
    // Code: Here write the implementation of solveSudoku
}

int main()
{
    //This is hard coding to receive the "grid"
    int grid [N][N] = 
    {
        {0, 2, 0,    0, 0, 0,    0, 0, 0},
        {0, 0, 0,    6, 0, 0,    0, 0, 3},
        {0, 7, 4,    0, 8, 0,    0, 0, 0},
        
        {0, 0, 0,    0, 0, 3,    0, 0, 2},
        {0, 8, 0,    0, 4, 0,    0, 1, 0},
        {6, 0 ,0,    5, 0, 0,    0, 0, 0},
        
        {0, 0, 0,    0, 1, 0,    7, 8, 0},
        {5, 0, 0,    0, 0, 9,    0, 0, 0},
        {0, 0, 0,    0, 0, 0,    0, 4, 0},
    };


    printf("The input Sudoku puzzle: \n");
    // "Print is a function we define to print the grid"
    printGrid(grid);

    if (solveSudoku(grid))
    {
        // If the puzzle is solved then:
        printf("Solution found after %d iterations: \n", count);
        printGrid(grid);
    }
    else
    {
        printf("No solution exists. \n");
    }
    return 0;
}



/*Let's break down this problem into a bunch of sub-problems
1. Find the right type for the function solveSudoku
So, we define N = 9, and we also know that any input will be a 9 x 9 grid.
 - for now we've hard coded an instance of a sudoku board in. Which means we know the input is a
 an array of ints where the array is 9 integers wide and 9 integers tall. 
 
So i guess this is the input for the sudoku solver?
- Ok, thinking about it. We're gonna be using iteration right? and we're going to be editing the array every instance
This therefore means that the Type of the function isn't necessarily a 9x9 grid of ints, so the input to
 the function is a 9x9 array of ints. But considering how we use the function the 


2. So we have the output pattern we're supposed to have
Now we need to figure out how to ACTUALLY solve the sudoku thingy

How do you play sudoku? well each 3 x 3 square 
must only have 1 number between 1 - 9,
and also each column/row must also only have 1 number between 1 - 9

I CAN make a program to check for that But how do i make a program that solves a sudoku puzzle?




We know:
A) there are going to be some n number of iterations for the program to solve a sudoku puzzle
B) 
*/




/* If you have functions that are declared but 
not implemented, here is the implementation:

*/