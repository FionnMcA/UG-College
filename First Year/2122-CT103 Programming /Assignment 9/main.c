// Name: Fionn McArdle, Student ID: 21446484, Date: 18/01/22

//including the differnent libraries
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


#define Gridsize 10 // defining the gridsize
void randomSearch(int grid);
void gridSearch(int grid, int locationsTried);

// creating the differnet variable
int shipX;
int shipY;
int locationsTried =0;
int xx = 0;
int yy = 0;

int main(){ // the main function
    srand(time(NULL)); // random number generator
    shipX = rand() % (Gridsize-1); // asigning shipX a random number between 0 and the size of the grid inclusive
    shipY = rand() % (Gridsize-1); // asigning shipY a random number between 0 and the size of the grid inclusive

    randomSearch(Gridsize); // calling the randomSearch function
    gridSearch(Gridsize, locationsTried);
    
    printf("===== New Grid ===== \n");
    
    shipX = rand() % (4); // asigning shipX a random number between 0 and the size of my student id inclusive
    shipY = rand() % (4); // asigning shipY a random number between 0 and the size of my student id inclusive

    randomSearch(4); // calling the randomSearch function with 4
    gridSearch(0,4); // calling grid search with 4
}

void randomSearch(grid){
    int x = rand() %(Gridsize -1); // asigning random search x value a random number
    int y = rand() %(Gridsize-1); // asigning random search y value a random number
    int i = 0; // will be used as a counter
    int j = 100000;
    while (j != grid ) { // creating an inifite loop that once the random x and why equals the ships x and y will print the statement below and the loop will break
        if (x == shipX && y == shipY){
            printf("----- Random Search ----- \nShip found after %d locations \nShip location x : %d, y : %d \n", i, x, y);
            break;
        }
        else { // if the random x and y don't equal there will be a new random number assigned to x and y and 1 will be added to the counter
             x = rand() %(Gridsize -1);
             y = rand() %(Gridsize -1);
            i++;
        }
    }
}
void gridSearch(int grid, int locationsTried) {
    
        if(xx == shipX && yy == shipY){ //if the x and y equal the ships x and y the statement will print
            printf("----- Grid Search ----- \nShip found after %d locations \nShip location x : %d, y : %d \n", locationsTried, xx, yy);
        }
    
       else{ // if they dont equal a new x and y will be calculated
            if(xx != shipX){
                xx = locationsTried % Gridsize;
            }
            else if(yy != shipY){
                yy = (locationsTried - xx)/ Gridsize;
            }
            locationsTried++; // adds 1 to the locationsTried counter
            gridSearch(grid, locationsTried); //calls the function itself
        }
    }

