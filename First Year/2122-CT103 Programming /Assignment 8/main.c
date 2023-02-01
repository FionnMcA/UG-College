// Name: Fionn McArdle, Student ID: 21446484, Date: 30/11/21
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//initialising the functions
int setPasscode(int passcode);
void randomPasscodeSearch(int passcode, int N);
void orderedPasscodeSearch(int passcode, int N);

int RandomPasscode; //initialising the random password

int main() {
    printf("Max passcode = 9 \n");
    setPasscode(9); // calling the function with a max password of 9
    randomPasscodeSearch(RandomPasscode, 9); // calls the randomPasscodeSearch function
    orderedPasscodeSearch(RandomPasscode, 9); // calls the orderedPasscodeSearch function
    
    
    printf("\nMax passcode = 99 \n");
    setPasscode(99); //calling the function with a max password of 99
    randomPasscodeSearch(RandomPasscode, 99); //
    orderedPasscodeSearch(RandomPasscode, 99);
    
    
    printf("\nMax passcode = 999 \n");
    setPasscode(999); //calling the function with a max password of 999
    randomPasscodeSearch(RandomPasscode, 999);
    orderedPasscodeSearch(RandomPasscode, 9999);
    
    printf("\nMax passcode = 9999 \n");
    setPasscode(9999); //calling the function with a max password of 9999
    randomPasscodeSearch(RandomPasscode, 9999);
    orderedPasscodeSearch(RandomPasscode, 9999);
    
    printf("\nMax passcode = 484 \n");
    setPasscode(484); //calling the function with a max password of 484
    randomPasscodeSearch(RandomPasscode, 484);
    orderedPasscodeSearch(RandomPasscode, 484);
}

int setPasscode(int passcode){
    srand(time(NULL));
    RandomPasscode = (rand()%passcode) +1; // creating a random password
    printf("Random passcode = %d \n", RandomPasscode); //printing the password
    return RandomPasscode;
}

void randomPasscodeSearch(int passcode, int N){
   int Rps = (rand()%passcode) +1; // creating a random number
    int i = 0; //initialising i has 0
    while (i != N ){ // creating an infinite loop
        if (Rps == RandomPasscode){ // that if equals the random password
        printf("Random Search: %d. found after %d attempts \n", passcode, i+1); //this statement prints saying the amount of attempts it took to match the password
            break; // and breaks the loop
        }
            else {
            Rps = (rand()%passcode) +1; // else if Rps doesn't equal the random password a new random password
                i++; // and contiues to count the attempts
        }
}
}

    void orderedPasscodeSearch(int passcode, int N){
        int i = 0; //initialising i has 0
        while ( i != N){ // creating an infinite loop
            if (i == RandomPasscode){ // that if i equals The random password
            printf("Ordered Search: %d. found after %d attempts \n", passcode, i+1); // the statement prints saying the amount of attempts it took to match the password
                break; // and the loop breaks
            }
                else {
                    i++;  // else if i doesn't equal the random password the loop continues to count
            }
    }
}

