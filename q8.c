#include <stdio.h>
#include <time.h>

// Function prototypes
unsigned long long factorialIterative(int n);
unsigned long long factorialRecursive(int n);

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Measure time for the iterative method
    clock_t startIterative = clock();
    unsigned long long factIterative = factorialIterative(n);
    clock_t endIterative = clock();
    double timeIterative = (double)(endIterative - startIterative) * 1000.0 / CLOCKS_PER_SEC;

    // Measure time for the recursive method
    clock_t startRecursive = clock();
    unsigned long long factRecursive = factorialRecursive(n);
    clock_t endRecursive = clock();
    double timeRecursive = (double)(endRecursive - startRecursive) * 1000.0 / CLOCKS_PER_SEC;

    // Print results
    printf("Factorial of %d (Iterative): %llu\n", n, factIterative);
    printf("Time taken (Iterative): %.6f milliseconds\n", timeIterative);
    printf("Factorial of %d (Recursive): %llu\n", n, factRecursive);
    printf("Time taken (Recursive): %.6f milliseconds\n", timeRecursive);

    return 0;
}

// Iterative method to calculate factorial
unsigned long long factorialIterative(int n) {
    unsigned long long factorial = 1;
    for(int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

// Recursive method to calculate factorial
unsigned long long factorialRecursive(int n) {
    if (n == 0)
        return 1;
    else
        return (n * factorialRecursive(n - 1));
}
