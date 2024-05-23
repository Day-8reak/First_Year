#include <stdio.h>
#include <stdlib.h> // For atoi function

// Function prototype
int fibonacci(int n);

int main(int argc, char *argv[]) {
    // Check if the user has entered the correct number of arguments
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1; // Return an error code
    }

    // Convert the command-line argument to an integer
    int n = atoi(argv[1]);

    // Validate the input to ensure it's a non-negative integer
    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1; // Return an error code
    }

    // Calculate the n-th Fibonacci number
    int fibNumber = fibonacci(n);

    // Print the result
    printf("Fibonacci number at position %d is: %d\n", n, fibNumber);

    return 0; // Successful execution
}

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    // Base cases
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}
