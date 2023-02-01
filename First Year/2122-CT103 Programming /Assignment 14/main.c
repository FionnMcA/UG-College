//Fionn McArdle, 21446484, 02/03/22

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAXSTRING 100
//global variables
char DictionaryStorage[100000][8];
//function prototypes
void ReadInDictionary(void);
void wordGuessing(void);

int main() {
    //calling the functions
    ReadInDictionary();
    wordGuessing();
}

void ReadInDictionary(){
FILE *fptr;
fptr = fopen("/Users/fionnmcardle/Downloads/dictionary.txt", "r"); //opens and reads the dictionary file
    if (fptr == NULL){
    printf("Could not open dictionary.txt"); //if the file is empty this statement prints
    }
else { //if the file is not empty
    char word[MAXSTRING];
    int NumWords = 0;
    while (fgets(word, MAXSTRING-1, fptr)!=NULL) {
        word[strlen(word)-1] = '\0'; //takes away the space charcter from the word
        if (strlen(word) >= 4 && strlen(word) <= 7){ // if the word is between 4 and 7
            strcpy(DictionaryStorage[NumWords], word); // then it is added to the Dictionary storage array
            NumWords++;//number of words counter
        }
    }
    printf("Loaded %d suitable words from the dictionary\n", NumWords);
    fclose (fptr);
}
}
void wordGuessing() {
    
    char GuessedLetter;
    char Dash[8];
    char RandomWord[8];
    int NumOfGuesses = 1;
    srand(time(NULL));
    int p = (rand()%30410); // picks a random number between 0 and 30409
    strcpy(RandomWord, DictionaryStorage[p]); // random number is put in the array index to pick around word
    
    for (int NumOfDashs = 0; NumOfDashs < strlen(RandomWord); NumOfDashs++) {
        Dash[NumOfDashs] = '-'; //a loop to see how long the word is to know the number of '-' to be printed
    }

    while (1 == 1) { // infinite loop that will run until the word is guessed
        printf("\nGuess %d.\n", NumOfGuesses);
        printf("%s", Dash);
        printf("\nGuess a letter >");
        scanf(" %c", &GuessedLetter);

        for (int LetterPosition = 0; LetterPosition < strlen(RandomWord); LetterPosition++) {
            if (RandomWord[LetterPosition] == GuessedLetter) { //if the guessed letter maatches a letter in the word this loop assigns that leter to its position
                Dash[LetterPosition] = GuessedLetter; // now instead of printing a dash it prints the correctly guessed letter
            }
        }
        
        int StringMatcher = strcmp(RandomWord, Dash); //If the strings are equal, it returns 0
        if (StringMatcher == 0) { // if the strings are equal that means the word has been guessed and the game is over
            printf("\n");
            printf("Well done, that took you %d guesses to find %s!\n\n", NumOfGuesses , RandomWord); //prints the word and the amount of guess the player took
            break; // breaks the infinte loop
        }
        NumOfGuesses++; // number of guesses counter
    }
}

