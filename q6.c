#include <stdio.h>

#define rows 5
#define seatsPerRow 10
char chart[rows][seatsPerRow];

// Initialize the seating chart with all seats as available ('O')
void initializeSeatingChart() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < seatsPerRow; j++) {
            chart[i][j] = 'O';
        }
    }
}

// Display the current seating chart
void displaySeatingChart() {
    printf("\nSeating Chart:\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < seatsPerRow; j++) {
            printf("%c ", chart[i][j]);
        }
        printf("\n");
    }
}

// Attempt to book a seat, returning 1 on success and 0 on failure
int bookSeat(int row, int seat) {
    if (row >= 1 && row <= rows && seat >= 1 && seat <= seatsPerRow) {
        if (chart[row - 1][seat - 1] == 'O') {
            chart[row - 1][seat - 1] = 'X'; // Mark seat as booked
            printf("\nSeat booked successfully.\n");
            return 1; // Booking success
        } else {
            printf("\nSeat is already booked.\n");
            return 0; // Seat already booked
        }
    } else {
        printf("\nInvalid row or seat number. Please enter row numbers between 1 and %d, and seat numbers between 1 and %d.\n", rows, seatsPerRow);
        return 0; // Invalid input
    }
}

// Display the total number of booked seats
void displayTotalBookedSeats() {
    int total = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < seatsPerRow; j++) {
            if (chart[i][j] == 'X') {
                total += 1;
            }
        }
    }
    printf("\nTotal Booked Seats: %d\n", total);
}

int main() {
    initializeSeatingChart();
    displaySeatingChart();
    bookSeat(2, 3);
    bookSeat(3, 7);
    bookSeat(1, 5);
    bookSeat(5, 5); // A Corrected call as per the valid range
    displaySeatingChart();
    bookSeat(2, 3); // Example of an Attempt to book an already booked seat
    displayTotalBookedSeats();

    return 0;
}
