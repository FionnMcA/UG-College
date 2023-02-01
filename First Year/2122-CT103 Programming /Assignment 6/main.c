// Name: Fionn McArdle, Student ID: 21446484, Date: 16/11/21
#include <stdio.h>
#include <math.h>

float VolumeOfPool(float length, float width, float height); //creating the function that will calculate the volume of the pool
void MassOfPool(float v); // creating the function that will calculate the mass of the pool
int HowManyBarrels(float v); // creating the function that will calculate how many barrels can be filled

int main(){
    float Volume = VolumeOfPool(4, 8, 4); // calculates the volume using the VolumeOfPool funtion
    printf("Volume = %0.2f \n", Volume); // prints the volume
    MassOfPool(Volume); // calculates the mass of the pool
    printf("Barrels = %0.2d \n", HowManyBarrels(Volume)); //prints how many barrels can be filled
    return 0;
}
float VolumeOfPool(float length, float width, float height) {
    return length * width * height; // calculates the volume
}
void MassOfPool(float v){
    printf("THe mass of the water is %0.2fKg \n", v * 1000); //calulates the mass and prints the mass of the pool
}
int HowManyBarrels(float v){
    return round( v / 0.48); // calculates the amount of barrels that can be filled
}
