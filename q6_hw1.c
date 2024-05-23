#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Use the current time as a seed for the random number generator
    srand(time(NULL));

    // Generate and print 5 random numbers
    for (int i = 0; i < 5; ++i) {
        int randomValue = rand();
        printf("Random number %d: %d\n", i + 1, randomValue);
    }

    return 0;
}