//Fionn McArdle 21446484 16/02/22
#include <stdio.h>

// creating a stricture for the date
typedef struct{
    int day, month, year;
} date;

// creating a structure for customer
typedef struct{
    char name[50];
    int accountNumber;
    double balance;
    date lastTrans;
} customer;

    //function prototypes
    void getCustomerName(customer* cptr);
    void getAccountNumber(customer* cptr);
    void getLastTransDate(customer* cptr);
    void getBalance(customer* cptr);
    void printCustomer(customer* cptr);

    int main(){
    int i; // initializing i
    char temp[100];
    customer customers[3];
    for (i = 0; i < 3; i++){ //creating a loop that will loop 3 times
    getCustomerName(&customers[i]);
    getAccountNumber(&customers[i]);
    getLastTransDate(&customers[i]);
    getBalance(&customers[i]);
    gets(temp);
    printf("\n");
    }
        
    printf("\n\n%25s\t%13s\t%12s\t%s\n\n", "Name", "Account Number",
    "Balance", "Date of Last Transaction");
    for (i = 0; i < 3; i++){
    printCustomer(&customers[i]); //calls printcustomer function 3 times
    }
    }

    void getCustomerName(customer* cptr){
        printf("Enter customer name: ");
        scanf("%s", &cptr->name); //read in the customer name to name
        
    }

    void getAccountNumber(customer* cptr){
        printf("Enter account number: ");
        scanf("%d", &cptr->accountNumber); //read in the account number to account number
    }

    void getLastTransDate(customer* cptr){
        printf("Enter last transaction date in form dd/mm/yy: ");
        scanf("%d/%d/%d", &cptr->lastTrans.day, &cptr->lastTrans.month, &cptr->lastTrans.year); //read in the date to day month and year
    }

    void getBalance(customer* cptr){
        printf("Enter Current Balance: ");
        scanf("%lf", &cptr->balance); //read in the balance to balance
    }

void printCustomer(customer* cptr){
    printf("\n\n%25s\t%13d\t%12.2lf\t%d/%d/%d\n\n", cptr->name, cptr->accountNumber, cptr->balance, cptr->lastTrans.day, cptr->lastTrans.month, cptr->lastTrans.year); // prints the customers name, account number, balance and last transaction date
}

        

