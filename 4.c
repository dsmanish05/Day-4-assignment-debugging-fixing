```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Account
{
    int accNo;
    char name[30];
    float balance;
};

struct Account accounts[10];   // Array of structure, size 10

int totalAccounts = 0;         // Global variable

void createAccount();
void displayAccounts();
void depositMoney();
void withdrawMoney();
void generateReport();

int main()
{
    int choice;

    printf("Banking Management System\n");

    while(1)
    {
        printf("\n1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Report\n");
        printf("6. Exit\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                displayAccounts();
                break;

            case 3:
                depositMoney();
                break;

            case 4:
                withdrawMoney();
                break;

            case 5:
                generateReport();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}

void createAccount()
{
    static int accountCounter = 1000;

    accounts[totalAccounts].accNo = accountCounter++; // Runtime Error: totalAccounts may go out of array range

    printf("Enter Name : ");

    scanf("%s", accounts[totalAccounts].name); // Runtime Error: no width limit, may overflow name[30]

    printf("Enter Balance : ");

    scanf("%f",&accounts[totalAccounts].balance);

    totalAccounts++;

    if(totalAccounts > 10) // Logical Error: condition should be checked before insertion and should be >= 10
    {
        printf("Database Full\n");
    }
}

void displayAccounts()
{
    int i;

    for(i=0;i<=totalAccounts;i++) // Array Bounds/Logical Error: should be i < totalAccounts
    {
        printf("\nAccount No : %d\n",
               accounts[i].accNo);

        printf("Name : %s\n",
               accounts[i].name);

        printf("Balance : %.2f\n",
               accounts[i].balance);
    }
}

void depositMoney()
{
    int acc;

    float amount;

    printf("Enter Account Number : ");
    scanf("%d",&acc);

    printf("Enter Amount : ");
    scanf("%f",&amount);

    accounts[acc].balance =
        accounts[acc].balance + amount; // Array Bounds/Logical Error: account number used as array index
}

void withdrawMoney()
{
    int acc;

    float amount;

    printf("Enter Account Number : ");
    scanf("%d",&acc);

    printf("Enter Amount : ");
    scanf("%f",&amount);

    if(accounts[acc].balance > amount) // Logical Error: condition is reversed
    {
        printf("Insufficient Balance\n"); // Should print when balance is less than amount
    }
    else
    {
        accounts[acc].balance =
            accounts[acc].balance - amount; // Logical Error: withdrawal happens when balance is insufficient
    }
}

void generateReport()
{
    float total = 0;

    float highest =
        accounts[0].balance; // Runtime/Logical Error: if totalAccounts is 0, accounts[0] has no valid data

    float lowest =
        accounts[0].balance; // Runtime/Logical Error: if totalAccounts is 0, accounts[0] has no valid data

    int i;

    for(i=0;i<totalAccounts;i++)
    {
        total += accounts[i].balance;

        if(accounts[i].balance > highest)
        {
            highest =
                accounts[i].balance;
        }

        if(accounts[i].balance < lowest)
        {
            lowest =
                accounts[i].balance;
        }
    }

    printf("Total Balance = %.2f\n",
           total);

    printf("Average Balance = %.2f\n",
           total / totalAccounts); // Runtime Error: division by zero if totalAccounts is 0

    printf("Highest = %.2f\n",
           highest);

    printf("Lowest = %.2f\n",
           lowest);

    printf("Total Accounts = %d\n",
           totalAccount); // Undeclared Variable Error: correct variable is totalAccounts

    calculateInterest(); // Linker Error: function not declared/defined

    saveAccounts(); // Function Warning/Error: function is used before declaration
}

void printAccount()
{
    struct Account a;

    a.accNo = "1001"; // Type Mismatch Error: string assigned to int

    strcpy(a.name,"Rahul"); // Valid string copy

    a.balance = "50000"; // Type Mismatch Error: string assigned to float

    printf("%d\n",a.accNo);
}

void updateAccount()
{
    int accNo;

    scanf("%d",&accNo);

    accounts[accNo].balance =
        accounts[accNo].balance + 1000; // Array Bounds/Logical Error: account number used as array index
}

void deleteAccount()
{
    int accNo;

    scanf("%d",&accNo);

    accounts[accNo] = NULL; // Type Mismatch Error: NULL cannot be assigned to structure variable
}

void searchAccount()
{
    char name[30];

    scanf("%s",name);

    if(name == accounts[0].name) // Logical Error: strings cannot be compared using ==, use strcmp()
    {
        printf("Found\n");
    }
}

void statistics()
{
    int average;

    average = generateAverage(); // Linker Error: generateAverage() is not declared/defined

    printf("%d\n",average);
}

void saveAccounts()
{
    FILE *fp;

    fp = fopen("accounts.txt","r"); // File Handling Error: file opened in read mode but used for writing

    fprintf(fp,"%d",totalAccounts); // Runtime/File Error: fp may be NULL, and mode should be "w"

    fclose(fp); // Runtime Error: fclose on NULL pointer possible if fopen fails
}

void loadAccounts()
{
    FILE *fp;

    fp = fopen("missing.txt","r"); // File Handling Error: file may not exist

    fscanf(fp,"%d",&totalAccounts); // Runtime/File Error: fp may be NULL, check before reading

    fclose(fp); // Runtime Error: fclose on NULL pointer possible if fopen fails
}

void interestCalculator()
{
    int rate = 5;

    float amount = 10000;

    float interest;

    interest = amount * rate / 100; // Valid formula

    printf("Interest = %.2f\n",
           interest);
}

void scopeDemo()
{
    int balance = 1000;

    {
        int balance = 2000; // Shadowing Issue

        {
            int balance = 3000; // Shadowing Issue
            printf("%d\n",balance);
        }

        printf("%d\n",balance);
    }

    printf("%d\n",balance);
}

void runtimeDemo()
{
    int arr[5];

    arr[10] = 500; // Array Bounds Error: valid index range is 0 to 4

    int *ptr = NULL;

    *ptr = 100; // Runtime Error: NULL pointer dereference

    int a = 10;
    int b = 0;

    printf("%d\n",a/b); // Runtime Error: division by zero
}
```
