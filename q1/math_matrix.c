// Code: Include necessary libraries
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));

    // Check if the number of arguments is correct
    if (argc < 6 || argc > 7) {
        printf("Usage: %s nrows_A ncols_A nrows_B ncols_B <operation> [print]\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    int nrows_A = atoi(argv[1]);
    int ncols_A = atoi(argv[2]);
    int nrows_B = atoi(argv[3]);
    int ncols_B = atoi(argv[4]);
    char *operation = argv[5];
    int print = (argc == 7 && strcmp(argv[6], "print") == 0) ? 1 : 0;

    // Check if matrix dimensions are valid
    if (ncols_A != nrows_B && strcmp(operation, "multiply") == 0) {
        printf("Error: Matrix dimensions are incompatible for multiplication.\n");
        return 1;
    }

    // Declare matrices A, B, and result
    double **A, **B, **result;
    clock_t start, end;
    double cpu_time_used_total = 0.0;

    start = clock(); // Start measuring CPU time

    generateMatrix(&A, nrows_A, ncols_A); // New generation of matrices using the new function
    generateMatrix(&B, nrows_B, ncols_B);

    if (strcmp(operation, "solve") != 0) {
        result = (double **)malloc(nrows_A * sizeof(double *));
        if (result == NULL) {
            printf("Memory allocation failed for result matrix.\n");
            deallocateMatrix(A, nrows_A);
            deallocateMatrix(B, nrows_B);
            return 1;
        }
        for (int i = 0; i < nrows_A; i++) {
            result[i] = (double *)malloc(ncols_B * sizeof(double));
            if (result[i] == NULL) {
                printf("Memory allocation failed for result matrix.\n");
                deallocateMatrix(A, nrows_A);
                deallocateMatrix(B, nrows_B);
                deallocateMatrix(result, nrows_A);
                return 1;
            }
        }
    }

    // Perform the requested operation
    if (strcmp(operation, "add") == 0) {
        addMatrices(nrows_A, ncols_A, A, nrows_B, ncols_B, B, result);
    } else if (strcmp(operation, "subtract") == 0) {
        subtractMatrices(nrows_A, ncols_A, A, nrows_B, ncols_B, B, result);
    } else if (strcmp(operation, "multiply") == 0) {
        multiplyMatrices(nrows_A, ncols_A, A, nrows_B, ncols_B, B, result);
    } else if (strcmp(operation, "solve") == 0) {
        if (nrows_A != ncols_A || nrows_A != nrows_B || ncols_B != 1) {
            printf("Error: Invalid dimensions for solving linear system.\n");
            deallocateMatrix(A, nrows_A);
            deallocateMatrix(B, nrows_B);
            return 1;
        }
        double **x;
        x = (double **)malloc(nrows_A * sizeof(double *));
        if (x == NULL) {
            printf("Memory allocation failed for result matrix.\n");
            deallocateMatrix(A, nrows_A);
            deallocateMatrix(B, nrows_B);
            return 1;
        }
        for (int i = 0; i < nrows_A; i++) {
            x[i] = (double *)malloc(ncols_B * sizeof(double));
            if (x[i] == NULL) {
                printf("Memory allocation failed for result matrix.\n");
                deallocateMatrix(A, nrows_A);
                deallocateMatrix(B, nrows_B);
                deallocateMatrix(x, nrows_A);
                return 1;
            }
        }
        solveLinearSystem(nrows_A, ncols_A, A, nrows_B, ncols_B, B, x);
        // Print the result
        printf("Solution of Ax = B:\n");
        printMatrix(x, nrows_A, ncols_B);
        // Free memory for x
        deallocateMatrix(x, nrows_A);
    } else {
        printf("Error: Invalid operation.\n");
        deallocateMatrix(A, nrows_A);
        deallocateMatrix(B, nrows_B);
        if (result != NULL) {
            deallocateMatrix(result, nrows_A);
        }
        return 1;
    }

    end = clock(); // Stop measuring CPU time
    cpu_time_used_total = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Total CPU time: %f seconds\n", cpu_time_used_total);

    // Free memory for matrices A, B, and result
    deallocateMatrix(A, nrows_A);
    deallocateMatrix(B, nrows_B);
    if (result != NULL) {
        deallocateMatrix(result, nrows_A);
    }

    return 0;
}