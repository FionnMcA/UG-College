// Name: Fionn McArdle, Student ID: 21446484, Date 2/11/21
#include <stdio.h>
int main()
{
    int Rating[21]; //declaring the array to store all rating values
    float RatingFrequency[] = {0,0,0,0,0};
    float PercentageFrequency[] = {0,0,0,0,0};
    float TotalRating = 0; //initialising the total rating as 0
    float AverageRating = 0; //initialising the average rating as 0
    
    printf("Enter a movie rating between 1 and 5 \n"); //prints the statment Enter a movie rating between 1 and 5

    for(int i = 0 ; i < 21; i++) // a for loop that loops 21 times because there are 21 ratings
    {
        printf("Enter rating number %d: ", i + 1); //asks the user to input the rating
        scanf("%d", &Rating[i]); //stores the value in an array
        TotalRating += Rating[i]; // calculates the total rating 
        
        switch(Rating[i]){  // the switch statement will read the value inputted by the user and will run it through the cases until it finds a case where the input is true
            case 1:
                RatingFrequency[0]++;
                break;
            case 2:
                RatingFrequency[1]++;
                break;
            case 3:
                RatingFrequency[2]++;
                break;
            case 4:
                RatingFrequency[3]++;
                break;
            case 5:
                RatingFrequency[4]++;
                break;
            default:
                printf("Invalid number \n"); //tells the user that the number they inputted was invalid 
                TotalRating -= Rating[i];
                i--; //removes 1 from the total counter since it isn't a valid number
                break;
        }
    }
    
    AverageRating = (TotalRating / 21); // calculates the average rating
    printf("Average Rating is: %.1f \n" , AverageRating); //prints the average rating
    
    printf("rating frequency \n");
    printf("-------------------------------- \n");
    
  
    for(int i=0; i<5; i++) // a for loop that runs 5 times because there's only 5 possible ratings
    {
                  printf("%d star " , i+1); // prints the rating number
                  for (int j = 0; j < RatingFrequency[i]; j++)
                      printf("*"); // prints one star per each time the rating was inputed
                  printf("\t %.0f \n", RatingFrequency[i]); // prints the number of stars that were printed
    }
    printf("-------------------------------- \n");
    printf("percentage frequency \n");
    printf("-------------------------------- \n");
    
    for(int i=0; i<5; i++) // a for loop that runs 5 times because there's only 5 possible ratings
    {
                  PercentageFrequency[i] = (RatingFrequency[i] / 21) * (100); // calulates the percentage frequency of each rating
                  printf("%d star " , i+1);
                  for (int j = 0; j < PercentageFrequency[i]; j++)
                      printf("*"); // prints one star per one percent of the ratings percentage frequency
                  printf("\t %.1f%% \n", PercentageFrequency[i]); // printd the percentage frequency of the rating
              
    }
    return 0;
}
