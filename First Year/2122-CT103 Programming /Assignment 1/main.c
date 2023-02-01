// Name: Fionn McArdle, Student ID: 21446484, Date 12/10/21
#include <stdio.h>

int main() {
    float Day1 = 0; //initial Day1 sales
    float Day2 = 0; //initial Day2 sales
    float Day3 = 0; //initial Day3 sales
    float Day4 = 0; //initial Day4 sales
    float DailyAverage;
    float CustomersSale;
   
    
    printf("Enter the total daily sales (Euro) on Day 1: "); // Asks the user to input their Daily sales for Day1
    scanf("%f", &Day1); //Allows the user to input the Day1 Sales
    
    printf("Enter the total daily sales (Euro) on Day 2: "); // Asks the user to input their Daily sales for Day2
    scanf("%f", &Day2); //Allows the user to input the Day2 Sales
    
    printf("Enter the total daily sales (Euro) on Day 3: "); // Asks the user to input their Daily sales for Day3
    scanf("%f", &Day3); //Allows the user to input the Day3 Sales
    
    printf("Enter the total daily sales (Euro) on Day 4: "); // Asks the user to input their Daily sales for Day4
    scanf("%f", &Day4); //Allows the user to input the Day4 Sales
    
    DailyAverage = (Day1 + Day2 + Day3 + Day4)/4; //Calculates the average daily sales
    printf("The average daily sales over the 4 days are %0.2f \n", DailyAverage); //Prints the daily average
    
    if(DailyAverage > 15000) {
        printf("Sales are high \n"); //When the average daily sales is greater than 15000 the statement "sales are high"
    }
    
    else if(DailyAverage  >= 10000 ) {
        printf("Sales are normal \n "); //When the average daily sales is greater than or equal to 10000 but less than 15000 the statement "sales are normal" will print
    }
        
    else if(DailyAverage < 10000) {
        printf("Sales are low \n"); //When the average daily sales is less than 10000 the statement "sales are low" will print
    }
    
    CustomersSale = (DailyAverage/500); //Calculate the average spend per customer
    printf("The average spend per customer (Euro) is %0.2f \n", CustomersSale); //prints the average spend per customer
    
}
