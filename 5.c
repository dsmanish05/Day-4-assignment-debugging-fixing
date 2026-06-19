```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book
{
    int bookId;
    char title[50];
    char author[30];
    float price;
};

struct Book books[20];

int totalBooks = 0;

void addBook();
void displayBooks();
void issueBook();
void returnBook();
void generateReport();

int main()
{
    int choice   // Syntax Error: missing semicolon (;)

    printf("Library Management System\n");

    while(1)
    {
        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Issue Book");
        printf("\n4. Return Book");
        printf("\n5. Report");
        printf("\n6. Exit");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                issueBook();
                break;

            case 4:
                returnBook();
                break;

            case 5:
                generateReport();
                break;

            case 6:
                exit(0);

            default   // Syntax Error: colon (:) missing
                printf("Invalid Choice\n");
        }
    }

    return 0;
}

void addBook()
{
    static int bookCounter = 100;

    books[totalBooks].bookId = bookCounter++;

    printf("Enter Title : ");
    scanf("%s", books[totalBooks].title); // Runtime Error: may overflow title array

    printf("Enter Author : ");
    scanf("%s", books[totalBooks].author); // Runtime Error: may overflow author array

    printf("Enter Price : ");
    scanf("%f",&books[totalBooks].price);

    totalBooks++;

    if(totalBooks > 20) // Logical Error: should be checked before insertion and use >= 20
    {
        printf("Library Full\n");
    }
}

void displayBooks()
{
    int i;

    for(i=0;i<=totalBooks;i++) // Array Bounds Error: should be i < totalBooks
    {
        printf("\nBook ID : %d",
               books[i].bookId);

        printf("\nTitle : %s",
               books[i].title);

        printf("\nAuthor : %s",
               books[i].author);

        printf("\nPrice : %.2f\n",
               books[i].price);
    }
}

void issueBook()
{
    int id;

    printf("Enter Book ID : ");
    scanf("%d",&id);

    books[id].price = books[id].price - 10; // Logical Error: Book ID used as array index
}

void returnBook()
{
    int id;

    scanf("%d",&id);

    books[id].price =
        books[id].price + 10; // Logical Error: Book ID used as array index
}

void generateReport()
{
    float highest = books[0].price; // Runtime Error: no books added yet

    float lowest = books[0].price; // Runtime Error: no books added yet

    float totalPrice = 0;

    int i;

    for(i=0;i<totalBooks;i++)
    {
        totalPrice += books[i].price;

        if(books[i].price > highest)
        {
            highest = books[i].price;
        }

        if(books[i].price < lowest)
        {
            lowest = books[i].price;
        }
    }

    printf("Highest Price = %.2f\n",
           highest);

    printf("Lowest Price = %.2f\n",
           lowest);

    printf("Average Price = %.2f\n",
           totalPrice/totalBooks); // Runtime Error: division by zero if totalBooks = 0

    printf("Total Books = %d\n",
           totalBook); // Undeclared Variable Error: should be totalBooks

    saveLibrary(); // Function used before declaration

    calculateFine(); // Linker Error: function not defined
}

void printBook()
{
    struct Book b;

    b.bookId = "101"; // Type Mismatch Error: string assigned to int

    strcpy(b.title,"C Programming");

    strcpy(b.author,"Dennis");

    b.price = "500"; // Type Mismatch Error: string assigned to float

    printf("%d\n",b.bookId);
}

void searchBook()
{
    char title[30];

    scanf("%s",title);

    if(title == books[0].title) // Logical Error: strings cannot be compared using ==
    {
        printf("Book Found\n");
    }
}

void deleteBook()
{
    int id;

    scanf("%d",&id);

    books[id] = NULL; // Type Mismatch Error: structure cannot be assigned NULL
}

void updateBook()
{
    int id;

    scanf("%d",&id);

    books[id].price =
        books[id].price + 100; // Logical Error: Book ID used as array index
}

void statistics()
{
    int avg;

    avg = calculateAveragePrice(); // Linker Error: function not defined

    printf("%d\n",avg);
}

void saveLibrary()
{
    FILE *fp;

    fp = fopen("library.txt","r"); // File Handling Error: opened in read mode

    fprintf(fp,"%d",totalBooks); // Runtime/File Error: writing in read mode

    fclose(fp);
}

void loadLibrary()
{
    FILE *fp;

    fp = fopen("missing.txt","r"); // File Handling Error: file may not exist

    fscanf(fp,"%d",&totalBooks); // Runtime Error: fp may be NULL

    fclose(fp);
}

void scopeDemo()
{
    int count = 10;

    {
        int count = 20; // Shadowing Issue

        {
            int count = 30; // Shadowing Issue

            printf("%d\n",count);
        }

        printf("%d\n",count);
    }

    printf("%d\n",count);
}

void pointerDemo()
{
    int *ptr = NULL;

    *ptr = 100; // Runtime Error: NULL pointer dereference

    int arr[5];

    arr[10] = 200; // Array Bounds Error: valid index is 0-4

    int a = 10;
    int b = 0;

    printf("%d\n",a/b); // Runtime Error: division by zero
}

void stringDemo()
{
    char name[5];

    strcpy(name,
           "Programming"); // Buffer Overflow Error: string larger than array

    printf("%s\n",name);
}

void memoryDemo()
{
    int *ptr;

    ptr = malloc(5); // Memory Error: only 5 bytes allocated

    for(int i=0;i<20;i++)
    {
        ptr[i] = i; // Runtime Error: writing beyond allocated memory
    }

    free(ptr);

    printf("%d\n",ptr[0]); // Runtime Error: use after free

    free(ptr); // Runtime Error: double free
}