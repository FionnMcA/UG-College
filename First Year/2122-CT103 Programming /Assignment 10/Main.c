#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main() {
    FILE* fptr; //associates file with file pounter 
    fopen_s(&fptr, "C:\\Users\\RegHelp015\\Documents\\SampleData.txt", "r"); // opens file and reads it
    if (fptr == NULL) { // if there's nothing in the file the below statement will print
        puts("Error Opening File \n Exiting ........");
        return;
    }
    else {
        char c = fgetc(fptr); // taking input single character at a time
        while (c != EOF) { //if c doesn't equal End of file
            printf("%c", c); //prints the character
            c = fgetc(fptr); //takes input single character at a time
        }
    }

    printf("\n------ Part 2 ------\n");
    fclose(fptr); // closes the file 
    char line[1001];
    fopen_s(&fptr, "C:\\Users\\RegHelp015\\Documents\\SampleData.txt", "r"); // opens file again and reads it again
    if (fptr == NULL) {  // if there's nothing in the file the below statement will print
        puts("Error Opening File \n Exiting ........");
        return;
    }
    else {
        fgets(line, 1001, fptr);
        printf("%s\n", line);
        float totalIncome = 0; //initialising total income 
        int i = 0; // creating a counter

        while (!feof(fptr)) {
            //creating the below variables
            int date;
            int month;
            int year;
            int units;
            char region[41];
            char rep[41];
            char item[41];
            float cost;
            float total;

            // printing the information with a tab
            fscanf_s(fptr, "%d/", &month);
            fscanf_s(fptr, "%d/", &date);
            fscanf_s(fptr, "%d/\t", &year);
            fscanf_s(fptr, "%s\t", region, 41);
            fscanf_s(fptr, "%s\t", rep, 41);
            fscanf_s(fptr, "%s\t", item, 41);
            fscanf_s(fptr, "%d\t", &units);
            fscanf_s(fptr, "%f/\t", &cost);
            fscanf_s(fptr, "%f/\t\n", &total);
            printf("%d/%d/%d\t  %s\t%s\t%s\t%d\t   %0.2f\t%0.2f\t\n", month, date, year, region, rep, item, units, cost, total);
            totalIncome += total; // adds to the total income 
            i++; // adds 1 to the counter
        }
        //prints the below statements
        printf("Total order income = %0.2f euro.\n", totalIncome);
        printf("Average order value = %0.2f euro.\n", totalIncome / i);

    }
    fclose(fptr); //closes the file again
    printf("\n------ Part 3------\n");
    fopen_s(&fptr, "C:\\Users\\RegHelp015\\Documents\\SampleData.txt", "a"); // opens the file again and can add to it
    fprintf(fptr, "25/01/22\tGalway\tMcArdle\tpen\t44\t19.99\t879.56"); //prints the information given
    fclose(fptr);//closes the file
}
