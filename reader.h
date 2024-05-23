#ifndef READER_H
#define READER_H

void parse_vader_lexicon(const char *filename);

float calculate_sentiment_score(char *sentence); 

void cleanup_memory();

#endif /* FUNCTIONS_H */