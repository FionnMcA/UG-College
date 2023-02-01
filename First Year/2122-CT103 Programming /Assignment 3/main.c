//Name: Fionn McArdle Student ID: 21446484 Date: 26/10/2021

#include <stdio.h>

int main()
{
    float DailySales[365]; //declaring the array to store all values with a limit of one year
    float TotalSales = 0; //declaring the total sales
    float AverageSales = 0; //declaring the average sales
    float AdditionalDays = 0; //declaring the additional days
    float NewAverage = 0; //declaring the new average
    float NewTotal = 0; //declaring the new total
    
    for(int i = 0 ; i < 7; i++) //creating a loop for 7 days
    {
        printf("Enter sales total for (Euro) for day %d:€", i + 1); //asks users to input the daily sales
        scanf("%f", &DailySales[i]); //stores the value in an array
        TotalSales += DailySales[i]; //total sales calculator
        AverageSales = TotalSales/7; // average sales calculator
    }
    printf("Total Sales is:€%0.2f \n ", TotalSales); //prints the total sales
    printf("Average Sales is:€%0.2f \n" , AverageSales); //prints the average sales
    
    printf("how many additional days would you like to add: "); //asks the users if they would like to add any days
    scanf("%f", &AdditionalDays); //stores the value

    int i =0;
    while(i < AdditionalDays) //creates a while loop for however many additional days the user added
    {
        printf("Enter sales in euro for day %d:€", i + 8); //asks the user to input the daily sales
        scanf("%f", &DailySales[i + 7]); //stores the values
        i++;
    }
    NewTotal = TotalSales + AdditionalDays; //calculates the new total sales
    NewAverage = NewTotal / (7 + AdditionalDays); //calculates the new average
    printf("New total sales is:€%0.2f \n", NewTotal); //prints the new total sales
    printf("New average is:€%0.2f \n", NewAverage); //prints the new average sales
    
    int AdditionalDaysArray = 7 + AdditionalDays; //stores the additional days in an array
    for (int i = 0; i < AdditionalDaysArray; i++) //creates a for loop for the number of additional days requested
    {
        printf("sales for day %d:€%0.2f \n", i+1, DailySales[i]); // prints all the days and there sales
    }
}
