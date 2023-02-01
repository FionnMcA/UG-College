//Fionn McArdle 21446484 08/02/22
#include <stdio.h>

//function prototypes 
void printDoubleArray(double* dp, int len);
void swapIntegerValues(int* i1, int* i2);
void squareIntArray(int* i1, int len);
void printIntegerArrayBackwards(int* arr, int len);
void randomIntArray(int* arr, int len, int max);

void main() {

	double array1[] = { 1.50,2.30,4.70,8.90 }; //creating an array
	printDoubleArray(array1, 4); //calling the function passing in the array and length 4

	//assigning i1 and i2 the values 4 and 12
	int x = 4; 
	int y = 12;
	int* i1 = &x;
	int* i2 = &y;

	printf("\n\nQ2: Integar Swap\n"); 
	printf("x = %d, y = %d\n", *(i1), *(i2)); //prints the statement with i1 and i2 and their current values
	swapIntegerValues(i1, i2); //calling the function which swaps the values
	printf("x = %d, y = %d\n", *(i1), *(i2)); //prints the statement with the values swapped

	int array2[] = {1,2,3,4,5}; .//creating an array 
	squareIntArray(array2, 5); //calls the function to square each number in the array 

	printIntegerArrayBackwards(array2, 5); //calls the function which prints the numbers backwards

	int arrr[5]; // creating an array of size 5
	randomIntArray(arrr, 5, 100); //calls function which creates 5 random numbers bewtween 0 and 100
}

void printDoubleArray(double* dp, int len) {
	printf("Q1: Double Array\n");
	for (int i = 0; i < len; i++) { // reads in each value of the array 
		printf("%0.2lf ", *(dp + i)); //prints each value of the array 
	}
}

void swapIntegerValues(int* i1, int* i2) {
	int z = *i1; // letting i1 equal a random variable
	*i1 = *i2; // then i1 = i2 
	*i2 = z; // and i2 equals the random variable (which is the original value of i1)
	}

void squareIntArray(int* i1, int len) { 
	printf("\nQ3 square array\n"); 
	for (int i = 0; i < len; i++) { // reads in each value of the array
		*(i1 + i) = *(i1 + i) * *(i1 + i); // multiplies each value by itself (squaring it)
		printf("%d ", *(i1 + i)); // prints the values
	}
}

void printIntegerArrayBackwards(int* arr, int len) {
	printf("\n\nQ4. Array Backwards\n");
	for (int i = len - 1; i >= 0; i--) { //reads in the values from the end to the start
		printf("%d ", *(arr + i)); //prints the values
	}
}

void randomIntArray(int* arr, int len, int max) {
	printf("\n\nQ5. Random Integers\n");
	srand(time(NULL) * max); // random number generator
	for (int i = 0; i < len; i++) { // creates 5 random numbers
		arr[i] = rand() % max; // creates random numbers between 0 and 100
		printf("%d ", *(arr + i)); // prints the values
	}
}