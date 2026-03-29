#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#include <ctype.h>
#define MAX_CHARACTERS 1005
#define MAX_WORDS 1000
#define MAX_SENTENCES 100
#define MAX_PARAGRAPHS 5


char ****get_document(char* text) {
    
    char **sentence = (char **)malloc(sizeof(char *)* MAX_WORDS);
    char ***paragraph = (char ***)malloc(sizeof(char **) * MAX_SENTENCES);
    char ****document = (char ****)malloc(sizeof(char ***) * MAX_PARAGRAPHS);
    int i = 0, char_count = 0, word_count = 0, sentence_count = 0, paragraph_count = 0;
    for (i = 0; text[i] != '\0'; i++) {

        char *word = (char *)malloc(sizeof(char) * 100);
        char *str = NULL;

        while (isalpha(text[i])) {
            word[char_count++] = text[i++];
        }

        if (char_count != 0) {
            word[char_count] = '\0';
            // printf("%s\n", word);
            str = malloc(sizeof(char) * (strlen(word) + 1));
            strcpy(str, word);
        }

        if (isspace(text[i]) || text[i] == '.') {
            if (str != NULL) {
                sentence[word_count++] = str;
                printf("%s\n", sentence[word_count - 1]);
            }
            
        }
        
        if (text[i] == '.') {
            paragraph[sentence_count++] = sentence;
            word_count = 0;
            sentence = (char **)malloc(sizeof(char *)* MAX_WORDS);
            // printf("END OF SENTENCE...sentence count : %d\n", sentence_count);
        }
        
        if (text[i] == '\n' || text[i + 1] == '\0') {
            document[paragraph_count++] = paragraph;
            sentence_count = 0;
            paragraph = (char ***)malloc(sizeof(char **) * MAX_SENTENCES);
            printf("END OF PARAGRAPH...paragraph_count : %d\n", paragraph_count);
        }


        free(word);
        char_count = 0;
    
    }
    return document;
}

int main(void) {
    char *text = "Learning C is fun.\nLearning pointers is more fun.It is good to have pointers.";
    get_document(text);
}