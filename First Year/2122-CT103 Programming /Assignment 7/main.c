// Name: Fionn McArdle, Student ID: 21446484, Date: 23/11/21
#include <stdio.h>
#include <math.h>
float ReadInTime(); // initialising function ReadInTime
float RoundedTime(float Time); // initialising function ReadInTime
float ElecPrice(float time); // initialising function ReadInTime
void PrintResults(float Rate, float roundtime); // initialising function ReadInTime

float dayRate = 23.9; // creating two global constants dayRate constant
float nightRate = 12.6;  // creating two global constants nightRate constant

int main(){
    float Time = ReadInTime();
    printf("time = %f \n" , Time); // prints the time
    float roundtime = ceil(Time);
    printf("time = %f \n" , roundtime); //prints the rounded time
    float Rate = ElecPrice(roundtime);
    PrintResults(Rate, roundtime); // prints the time and rates
}
float ReadInTime(){
    float hour; // initialising the hour
    float minute; //initialising the minutes
    printf("Please enter the current hour: "); // aks the user to input the hour
    scanf("%f", &hour); // records the input
    printf("Please enter the current minute: "); // asks the user to input the minute
    scanf("%f", &minute); // records the input
    
    
    if(hour > 24){ // if the hour is above 24 the hour will be brought down to 24
        hour = 24;
    }
    if(hour < 0){ // if the hour is below 0 the hour will be brought up to 0
        hour = 0;
    }
    if(minute > 60){ // if the minute is above 60 the hour will be brought down to 60
        hour = 60;
    }
    if(minute < 0){ // if the minute is below 0 the hour will be brought up to 0
        minute = 0;
    }
    
    float Time = (hour * (60) + minute)/(60);// turning the hours and minutes into a single float
    
    if(Time >= 24){ // if the time is above 24 then 24 will be taken away from the time
        Time = Time - 24;
    }
    return Time;
}

float RoundedTime(float Time){ //function that rounds uo the time
    float roundtime = ceil(Time); // rounds up the time
    return roundtime;
}

float ElecPrice(float Time){
    float Rate = (Time >= 8) ? dayRate : nightRate; // conditional operator that checks if the input applies to the day rate or night rate
    return Rate;
}

void PrintResults( float roundtime, float Rate){
    printf("Electricity price at time %f is %f c/kWh \n" , Rate, roundtime); // prints the statement that tells the user the time and the rate for that time.
}
