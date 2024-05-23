#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void generateMatrix(double ***matrix, int rows, int cols) {
    *matrix = (double **)malloc(rows * sizeof(double *));
    if (*matrix == NULL) {
        printf("Memory allocation failed for matrix.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = (double *)malloc(cols * sizeof(double));
        if ((*matrix)[i] == NULL) {
            printf("Memory allocation failed for matrix.\n");
            exit(EXIT_FAILURE);
        }
        for (int j = 0; j < cols; j++) {
            // Generate random numbers between -10 and 10
            (*matrix)[i][j] = (double)(rand() % 2001 - 1000) / 100.0;
        }
    }
}

void printMatrix(double **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.6f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int N1, int M1, double **A, int N2, int M2, double **B, double **result) {
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < M1; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int N1, int M1, double **A, int N2, int M2, double **B, double **result) {
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < M1; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int N1, int M1, double **A, int N2, int M2, double **B, double **result) {
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < M2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < M1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void solveLinearSystem(int N1, int M1, double **A, int N2, int M2, double **B, double **x) {
    // Gaussian elimination with back substitution
    for (int i = 0; i < N1; i++) {
        // Find pivot row and swap
        int maxRow = i;
        for (int j = i + 1; j < N1; j++) {
            if (fabs(A[j][i]) > fabs(A[maxRow][i])) {
                maxRow = j;
            }
        }
        // Swap rows i and maxRow
        for (int k = 0; k < N1; k++) {
            double temp = A[i][k];
            A[i][k] = A[maxRow][k];
            A[maxRow][k] = temp;
        }
        double temp = B[i][0];
        B[i][0] = B[maxRow][0];
        B[maxRow][0] = temp;

        // Perform forward elimination
        for (int j = i + 1; j < N1; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k < N1; k++) {
                A[j][k] -= factor * A[i][k];
            }
            B[j][0] -= factor * B[i][0];
        }
    }

    // Back substitution
    for (int i = N1 - 1; i >= 0; i--) {
        x[i][0] = B[i][0];
        for (int j = i + 1; j < N1; j++) {
            x[i][0] -= A[i][j] * x[j][0];
        }
        x[i][0] /= A[i][i];
    }
}

void deallocateMatrix(double **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}