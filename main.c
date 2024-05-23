#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"

#define WORD_MAX 45
#define LINE_MAX 150


// Defining the struct (basically a class without methods) "words"
struct words {
    char *word;
    float score;
    float SD;
    int SIS_array[10];
};

int main(int argc, char *argv[]) {
    // checks if we have the right amount of inputs
    if (argc != 3) {
        printf("Usage: %s vader_lexicon.txt input_file.txt\n", argv[0]);
        return EXIT_FAILURE;
    }

    // puts the text file (in this case vader_lexicon.txt through the parse function)
    parse_vader_lexicon(argv[1]);

    // Opens the second file, which is validation.text, which is where we have the sample phrases
    FILE *input_file = fopen(argv[2], "r");

    // if the input file is empty, then, we have an error
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        cleanup_memory();
        return EXIT_FAILURE;
    }

    //Defining line to have LINE_MAX
    char line[LINE_MAX];

    //printing the format of the final message
    printf("string sample\t\t\tscore\n");
    printf("--------------------------------------------------------------\n");

    //While there are lines in the validation file the code inside this file runs
    while (fgets(line, sizeof(line), input_file)) {

        // these all help with the formatting
        int width = 100;
        int spaces = width - strlen(line); 
        line[strcspn(line, "\r\n")] = 0;

        printf("%s%*s", line, spaces, ""); // Printing the sentiment score
        float score = calculate_sentiment_score(strcat(line, " and"));
        printf("%.2f\n", score);
    }


    fclose(input_file); // closing the file

    cleanup_memory(); // Cleaning up memory

    return EXIT_SUCCESS;
}