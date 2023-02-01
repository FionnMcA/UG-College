// Name: Fionn McArdle, Student ID: 21446484, Date: 09/11/21

#include <stdio.h>
#include "string.h"


#define pi 3.141592653589793238462643383279502884197169399375105820974944 // defining p as a constant to the first 100 digits

int main(){
    float radius = 0; // initializing the radius as 0
    float height = 0; // Initializing the height as 0
    float base = 0; // Initializing the base as 0
    float LenghtA = 0; // Initializing the Length A as 0
    float LenghtB = 0; // Initializing the Length B as 0
    float TriangleArea = 0; // Initializing the area of the triangle as 0
    float RectangleArea = 0; // Initializing the area of the rectangle as 0
    float CircleArea = 0; // Initializing the area of the circle as 0
    float TrapeziumArea = 0; // Initializing the area of the trapezium as 0
    float width = 0; // Initializing the width as 0
    char answer[50] = "temp"; // creating a string
    
    
    printf("Area Calculator - Shape Choices are: \n"); // prints the statement Area Calculator - Shape Choices are:
    printf("___________________________________________________________\n");
    printf("Triangle, Rectangle, Circle, Trapezium. 'Done' to end \n");
    printf("___________________________________________________________\n"); // prints the statement Triangle, Rectangle, Circle, Trapezium. 'Done' to end
    
    puts("choice: \n"); // asks the user to input their choice
    gets(answer); // stores the users input as a string
    
    while (strcmp(answer, "Done") != 0) { // the while loop repeats until the word Done is entered
        
        if (strcmp(answer, "Triangle") == 0) { // if the user's choice is Triangle
        puts("height: "); // they will be asked to input the height
        scanf("%f", &height); // stores the user's input value
        printf("base: "); // they will be asked to input the base
        scanf("%f", &base); // stores the user's input value
        TriangleArea = 0.5 * base * height; // calculates the area of the triangle
        printf("Area = %0.2f \n", TriangleArea); // prints the area of the triangle
        printf("___________________________________________________________\n");
    }
    
   else if (strcmp(answer, "Rectangle") == 0) { // if the user's choice is Rectangle
        printf("height: "); // they will be asked to input the height
        scanf("%f", &height); // stores the user's input value
        printf("width: "); // they will be asked to input the width
        scanf("%f", &width); // stores the user's input value
        RectangleArea = width * height; // calculates the area of the rectangle
        printf("Area = %0.2f \n", RectangleArea); // prints the area of the triangle
        printf("___________________________________________________________\n");
    }
    
   else if (strcmp(answer, "Circle") == 0) { // if the user's choice is Circle
        printf("radius: "); // they will be asked to input the radius
        scanf("%f", &radius); // stores the user's input value
        CircleArea = pi * radius * radius; // calculates the area of the circle
        printf("Area = %0.2f \n", CircleArea); //prints the area of the circle
        printf("___________________________________________________________\n");
    }
    else if (strcmp(answer, "Trapezium") == 0) { // if the user's choice is Trapezium
        printf("height: "); // they will be asked to input the height
        scanf("%f", &height); // stores the user's input value
        printf("length A : "); // they will be asked to input the length A
        scanf("%f", &LenghtA);// stores the user's input value
        printf("length B : "); // they will be asked to input the length B
        scanf("%f", &LenghtB); // stores the user's input value
        TrapeziumArea = 0.5 * (LenghtA + LenghtB) * height; // calculates the area of the trapezium
        printf("Area = %0.2f \n", TrapeziumArea); // prints the area of the trapezium
        printf("___________________________________________________________\n");
    }
            
        
        else {
            printf("Invalid input please try again \n"); // if the user does not input Triangle, Rectangle, Circle, Trapezium or "Done" then Invalid input please try again will be printed and the loop will continue
            printf("___________________________________________________________\n");
        }
    
        printf("Area Calculator - Shape Choices are: \n"); // prints the statement Area Calculator - Shape Choices are:
        printf("___________________________________________________________\n");
        printf("Triangle, Rectangle, Circle, Trapezium. 'Done' to end \n");
        printf("___________________________________________________________\n"); // prints the statement Triangle, Rectangle, Circle, Trapezium. 'Done' to end
        
        puts("choice: \n"); // asks the user to input their choice
        scanf("%s", answer); // stores the users input as a string
    }
}
