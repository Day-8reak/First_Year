#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randfrom(double min, double max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}

// Modified to accept already allocated matrix
void generateMatrix(double **matrix, int rows, int cols) {
    double **matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = randfrom(-10, 10);
        }
    }
}

void addMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M1]) {
    //looping through the rows and columns
    for (int i = 0; i < N1; i++){
        *result = (double**)malloc(M1 * sizeof(double*));
        for (int j = 0; j < M1; j++){
            // adding the a and b value of 2 different matrices  
            (*result)[i][j] = A[i][j] + B[i][j];
        } 
    }
}

void freeMatrix(double **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int rows = 5, cols = 5;
    double ** matrix;
 /*   double **matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(cols * sizeof(double));
    } */

    generateMatrix(matrix, rows, cols);

    // Print the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%6.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    freeMatrix(matrix, rows);

    return 0;
}