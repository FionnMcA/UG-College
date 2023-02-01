
//inlcuding the different libraries
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

void main() {
	FILE* fptr; //associates file with file pointer
	// creating variables needed to read in the information from the document
	char line[200];
	char countries[100];
	int population;
	fopen_s(&fptr, "C:\\Users\\RegHelp015\\Documents\\countries.txt", "r"); //opens the file countries and reads it 

	if (fptr != NULL) { //if there is not nothing in the file then the following will happen
		int i = 0, j = 0;
		while (!feof(fptr)) { //while the pointer is not at the end of the file
			char c = fgetc(fptr); // character c equals a charcter form the file 
			while (c != '\t') { // while c is not a tab
				countries[j] = c; // countries equals c which will eventually become a string of charcters which will spell out the countries from the file
				j++; //adds 1 to the j counter so c moves onto the next character
				c = fgetc(fptr); //c equals the next character
			}
			countries[j] = '\0'; // when countries equal a space 
			fscanf_s(fptr, "%d\n", &population); // reads in the numbers in the file and gives them to the population
			printf("Country: %s\nPopulation: %d\n", countries, population); // prints the country and the population
			j = 0;
		}
		fclose(fptr); //closes the file
	}

	printf("Question 4");
	fopen_s(&fptr, "C:\\Users\\RegHelp015\\Documents\\countries.txt", "a"); // opens the file and appends to the file
	fprintf(fptr, "\nFiji\t900,000"); //adds this statement to the file
	fclose(fptr);//closes the file

}
