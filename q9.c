#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 150
#define COLS 150

void generateRandomArray(double matrix[ROWS][COLS]) {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX * 100; // Random double between 0 and 100
        }
    }
}

double findMaxInColumn(double matrix[ROWS][COLS], int col) {
    double max = matrix[0][col];
    for (int i = 1; i < ROWS; i++) {
        if (matrix[i][col] > max) {
            max = matrix[i][col];
        }
    }
    return max;
}

double findMaxInRow(double matrix[ROWS][COLS], int row) {
    double max = matrix[row][0];
    for (int j = 1; j < COLS; j++) {
        if (matrix[row][j] > max) {
            max = matrix[row][j];
        }
    }
    return max;
}

double findMaxInMatrix(double matrix[ROWS][COLS]) {
    double max = matrix[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

double findAverageInColumn(double matrix[ROWS][COLS], int col) {
    double sum = 0;
    for (int i = 0; i < ROWS; i++) {
        sum += matrix[i][col];
    }
    return sum / ROWS;
}

double findAverageInRow(double matrix[ROWS][COLS], int row) {
    double sum = 0;
    for (int j = 0; j < COLS; j++) {
        sum += matrix[row][j];
    }
    return sum / COLS;
}

double findAverageInMatrix(double matrix[ROWS][COLS]) {
    double sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += matrix[i][j];
        }
    }
    return sum / (ROWS * COLS);
}

int main() {
    int m = 150, n = 150;
    double arr[ROWS][COLS];
    int columns = 8, rows = 5;

    generateRandomArray(arr);

    printf("Maximum value in column %d: %.6f\n", columns, findMaxInColumn(arr, columns));
    printf("Maximum value in row %d: %.6f\n", rows, findMaxInRow(arr, rows));
    printf("Maximum value in the entire matrix: %.6f\n", findMaxInMatrix(arr));
    printf("Average value in column %d: %.6f\n", columns, findAverageInColumn(arr, columns));
    printf("Average value in row %d: %.6f\n", rows, findAverageInRow(arr, rows));
    printf("Average value in the entire matrix: %.6f\n", findAverageInMatrix(arr));

    return 0;
}
