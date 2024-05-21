#include <stdio.h>
#include <stdbool.h> // import for bool
#include <math.h> // import for math library

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

bool isValid(int x, int y, int n, int grid[N][N])
{
    if (n > 9 || n < 1)
    {
        return false;
    }

    //checking column
    for (int i = 0; i < 9; i++)
    {
        if (n == grid[i][y])
        {
            return false;
        }
    }
    
    //checking row
    for (int i = 0; i < 9; i++)
    {
        if (n == grid[x][i])
        {
            return false;
        }
    }


    //checking subgrid
    int x0 = floor(x/3)*3;
    int y0 = floor(y/3)*3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[x0 + i][y0 + j] == n)
            {
                return false;
            }   
        }
    }
    /* Somehow we need to find out either where we are in the subgrid and
     then measure agains the other numbers in that subgrid
     OR
     We have to find out which grid we're in 
    */
    return true;
}


bool solveSudoku(int puzzle[][9], int row, int col)
{
    int i;
    if(row<9 && col<9)
    {
        if(puzzle[row][col] != 0)
        {
            if((col+1)<9) return solveSudoku(puzzle, row, col+1);
            else if((row+1)<9) return solveSudoku(puzzle, row+1, 0);
            else return 1;
        }
        else
        {
            for(i=0; i<9; ++i)
            {
                if(isValid(row, col, i+1, puzzle))
                {
                    puzzle[row][col] = i+1;
                    if((col+1)<9)
                    {
                        if(solveSudoku(puzzle, row, col +1)) return 1;
                        else puzzle[row][col] = false;
                    }
                    else if((row+1)<9)
                    {
                        if(solveSudoku(puzzle, row+1, 0)) return 1;
                        else puzzle[row][col] = false;
                    }
                    else return true;
                }
            }
        }
        return false;
    }
    else return true;
}

/* This is my second attempt at a solvesudoku function which didn't quite work

bool solveSudoku(int gridS[N][N], int r, int c)
{
    count = count + 1;
    if (r == 9)
    {
        return true;
    }
    else if (c == 9)
    {
        solveSudoku(gridS, r+1, 0);
    }
    else if (gridS[r][c] != 0)
    {
        solveSudoku(gridS, r, c+1);
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            if (isValid(r, c, i, gridS))
            {
                gridS[r][c] = i;
                if (solveSudoku(gridS, r, c+1))
                {
                    return true;
                }
                gridS[r][c] = 0;
            }
        }
        return false;
    } 



    /*This is my first attempt at a solvesudoku function
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (gridS[i][j] == 0)
            {
                for (int l = 1; l < 10; l++)
                {
                    if (isValid(i, j, l, gridS))
                    {
                        gridS[i][j] == l;
                        solveSudoku(gridS);
                        gridS[i][j] = 0;
                    }
                }
            }   
        }   
    } 
}
*/


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

    if (solveSudoku(grid, 0, 0))
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

So here's the plan:
A) make a function to check if inputting a value k into row R and column C is valid
If valid, return True if not valid return False

B) Make a function that goes through the entire sudoku puzzle line by line and uses
the is_valid function continously. If eventually placing a given value in a cell is 
impossible then we restart the function but with a new number in the firs tlsot

*/




/* If you have functions that are declared but 
not implemented, here is the implementation:

*/