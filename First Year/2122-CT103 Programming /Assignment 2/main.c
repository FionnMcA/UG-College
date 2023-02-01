//Name: Fionn McArdle Student ID: 21446484 Date: 19/10/2021

#include <stdio.h>

int main() {
    float ChildAge = 0; // initial Child age is 0
    float ChildCounter = 0; // initial Child counter value is 0, this float will be used to count the total number of children
    float TotalAge = 0; // initial total age is 0, this float will be used to count the total age
    float AverageAge = 0; // initial average age is 0
    float Oldest = 0; // initial oldest age is 0
    float Youngest = 18; // initial youngest age is 18
    
    printf("To stop the program enter a negative number \n"); // tells the user the program will end when they enter a negative number
    
    while(ChildAge >= 0) { //start a while loop
        ChildCounter++; // the count will go up by a value of 1 every time the loop is repeated
        TotalAge = TotalAge + ChildAge; // the age the user inputed is added to the total age
        printf("Enter Child age %.0f: \n", ChildCounter); // user is requested to input an age
        scanf("%f", &ChildAge); // inputed age is recorded
        
    if(ChildAge > 17){ // if statement that checks if the age entered is a child (below 18 years old)
        printf("Not a child \n"); // tells the user the number the input is not a child
        ChildCounter--; //removes 1 from the counter since it isn't a valid age
        ChildAge = 0; // sets child age back to 0
        }
    else if(ChildAge > 0){
        
        if (ChildAge > Oldest){ //if the age is older than the previous oldest age, then it becomes the new oldest age
            Oldest = ChildAge;
        }
        if (ChildAge < Youngest){
            Youngest = ChildAge; //if the age is younger than the previous youngest age, then it becomes the new youngest age
            }
        }
    }
    
    printf("Ending While Loop \n");
    
    ChildCounter--;
    printf("There are %0.f children \n", ChildCounter); //prints the total number of children
    AverageAge =  (TotalAge / (ChildCounter)); { // calculates the average age
    printf("The average age is %.2f: \n ",AverageAge ); //prints the average age
    }
    printf("The minimum age is %.0f \n" , Youngest); //prints the youngest age
    printf("The maximum age is %.0f \n" , Oldest); //prints the oldest age
    
    return 0;
}

