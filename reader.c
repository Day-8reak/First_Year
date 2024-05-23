#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "reader.h"

// Adding definitions to be used later
// Note: This part isn't mandatory, can just substitute values here
#define WORD_MAX 45
#define LINE_MAX 150

// We're making a pointer which will point to the first piece of info
// of a massive list of everything in vader_lexicon
struct words *vader_lexicon = NULL;
int numWords = 0;


// Defining the struct (basically a class without methods) "words"
struct words {
    char *word;
    float score;
    float SD;
    int SIS_array[10];
};



// This is the function that takes in a file, and will parse that file 
void parse_vader_lexicon(const char *filename) {
    //opening file
    FILE *file = fopen(filename, "r");

    // If the file is empty, then stop the program
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    // line is defined as an array of characters with max line length as it's size
    char line[LINE_MAX];

    // While fgets returns Something the following code runs, therefore
    // the file runs until there are no more lins
    while (fgets(line, sizeof(line), file)) {

        // Temporary variables to store different part of the ver_lexicon.txt
        char verbum[WORD_MAX];
        float sentiment, SD;
        int SIS_array[10];

        // The if checks if the line that we're looking at has exactly the correct number of 
        // values placed in such a way (explained by the format), that 13 values are filled each time it's run
        if (sscanf(line, "%s %f %f [%d,%d,%d,%d,%d,%d,%d,%d,%d,%d]",
                   verbum, &sentiment, &SD,
                   &SIS_array[0], &SIS_array[1], &SIS_array[2], &SIS_array[3], &SIS_array[4],
                   &SIS_array[5], &SIS_array[6], &SIS_array[7], &SIS_array[8], &SIS_array[9]) == 13) {
            // each new word that gets added reallocates the size of temp to 1 sizeof(struct words) longer        
            struct words *temp = realloc(vader_lexicon, (numWords + 1) * sizeof(struct words));

            // if temp is null (because nothing filled the values), exit the program 
            if (temp == NULL) {
                printf("Memory allocation failed.\n");
                cleanup_memory();
                exit(EXIT_FAILURE);
            }
            // redefining vader_lexicon's size
            vader_lexicon = temp;

            // changing the value of numWords' parts' values.
            strcpy(vader_lexicon[numWords].word, verbum);
            vader_lexicon[numWords].score = sentiment;
            vader_lexicon[numWords].SD = SD;
            memcpy(vader_lexicon[numWords].SIS_array, SIS_array, sizeof(SIS_array));
            numWords++;
        }
    }
    //closes file (duh!)
    fclose(file);
}


// Function calculates sentiment score of a sentence
float calculate_sentiment_score(char *sentence) {
    //
    char *token;
    char copy[LINE_MAX];  // Copy of the original sentence, the longest 
    strcpy(copy, sentence);   // copy now is equal to sentence

    // We initially set our count and score to 0
    float score = 0.0;
    int count = 0;


    // Tokenize the original sentence
    token = strtok(copy, " ,!.?");
    while (token != NULL) {
        // Check each token against the VADER lexicon
        for (int i = 0; i < numWords; i++) {
            // if the token is identical to some word in the vader_lexicon, then that word's 
            // score is added to score. count is also increased, and we move on to the next token (word)
            if (strcasecmp(token, vader_lexicon[i].word) == 0) {  
                score += vader_lexicon[i].score;
                //printf("%lf", vader_lexicon[i].score);
                //printf("%c", vader_lexicon[i].word[0]);
                break;
            }
            // If the word isn't in vader_lexicon, it means that the word has no 
            // assigned value and we continue to the next word
            else{ 
                continue;
            }
        }
        count++;
        // we use this to find the next word in the line
        token = strtok(NULL, " ,!.?");
    }

    // This calculates the actual sentiment score, which is score / count
    if (count == 0) {
        return 0.0;
    } else {
        return score / (count - 1);
    }
}


// cleaning up memory (duh!)
void cleanup_memory() {
    if (vader_lexicon != NULL) {
        for (int i = 0; i < numWords; i++) {
            free(vader_lexicon[i].word);
        }
        free(vader_lexicon);
    }
}



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


// Issues:
/* Right now all the lines with commas don't work.
The SUX! line doesn't work for some reason
*/


/*
#include <stdio.h>



struct words* vader = NULL;

struct words {
    char *word;
    float score;
    float SD;
    int SIS_array[10];
};


float scoreGetter(struct words word1){
    return word1.score;
}


float SDGetter(struct words word1){
    return word1.SD;
}

void charGetter(struct words word1){
    while (*word1.word != "\0"){
        printf("%c", word1.word);
        word1.word = word1.word + 1;
    }
    printf("\n");
}


float wordGetter(struct words word1){
    for( int i  = 0; i <= 10; i++){
        printf("%d,", word1.SIS_array[i]);
    }
    printf("\n");
}


void reader () {
   // struct words diction[] = {};
    //struct words lol;
}


int main(){
    struct words diction[] = {};
    FILE *vader_lexicon;

    fopen(vader_lexicon, "r");

    int finput = 0;
    int lines = 100;
    
    while(fscanf(vader_lexicon, "]", ))

    fclose(vader_lexicon);
}

*/


/*VADER (Valence Aware Dictionary and sEntiment Reasoner) is a lexicon and rule-based sentiment
analysis tool specifically designed for analyzing the sentiment of text. It is extensively used in
natural language processing tasks such as social media sentiment analysis, customer feedback
analysis, and opinion mining. The VADER lexicon consists of a list of words with corresponding
sentiment scores, indicating the positivity, negativity, and neutrality of each word. We downloaded
the VADER lexicon ( vader lexicon.txt ) from the official GitHub repository from here .
To write a C code to read the downloaded dictionary vader lexicon.txt , we’ll need to parse
the file and store the words along with their sentiment scores in a data structure for further
sentiment analysis computations. For example, the line 4450 in vader lexicon.txt , we have
”love 3.2 0.4 [3, 3, 3, 3, 3, 3, 3, 4, 4, 3]”, where ”love” is the word, ”3.2” is the polarity score,
”0.4” is the standard deviation, and ”[3, 3, 3, 3, 3, 3, 3, 4, 4, 3]” represents the sentiment
intensity scores. Each word with its corresponding score must be saved in a struct :


Read the files with dynamic memory allocation ( malloc and realloc ). Your code must be
able to handle all potential errors. Let’s say if I add a few more words to the files, your program
must be able still read the updated dictionaries. I have to be able to compile your code with
Makefile , and run it with ./mySA vader lexicon.txt <other inputs> , where mySA is the executable
object file created by your Makefile . At this point we don’t have any <other inputs> .




Steps:
1. How do i read a text file using c?
2. How do i parse text in c?
3. How do i take text in a text file, then parse it and split it into a bunch of different words in a word file?
*/




// Storage for some code i cooked up:


/*
            // This else if checks for spelling mistakes. In the case where the user missed one letter,
            // or mistyped a letter, this function will still catch the word.
            else if (strcmp(token, vader_lexicon[i].word) == 1)
            {
                // Checking through the symbols which are commonly used to draw an emoticon,
                //  in the case that one of these are detected, the symbol wasn't an emoticon
                // Because mistyping doesn't happen
                if((strstr(token, ":") != NULL) || (strstr(token, "-") != NULL) || (strstr(token, ";") != NULL) || (strstr(token, "{") != NULL) || (strstr(token, "}") != NULL) || (strstr(token, "*") != NULL) || (strstr(token, "_") != NULL) || strlen(token) < 6){ // finish
                    continue; // if the program thinks it was an emoticon then it continues
                }
                // if it's not an emoticon then this activates
                score += vader_lexicon[i].score;
                //printf("d" , vader_lexicon[i].score);
                count++;

                break;
            }
            */
