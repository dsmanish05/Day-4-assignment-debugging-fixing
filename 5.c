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
    int choice

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

            default
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
    scanf("%s", books[totalBooks].title);

    printf("Enter Author : ");
    scanf("%s", books[totalBooks].author);

    printf("Enter Price : ");
    scanf("%f",&books[totalBooks].price);

    totalBooks++;

    if(totalBooks > 20)
    {
        printf("Library Full\n");
    }
}

void displayBooks()
{
    int i;

    for(i=0;i<=totalBooks;i++)
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

    books[id].price = books[id].price - 10;
}

void returnBook()
{
    int id;

    scanf("%d",&id);

    books[id].price =
        books[id].price + 10;
}

void generateReport()
{
    float highest =
        books[0].price;

    float lowest =
        books[0].price;

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
           totalPrice/totalBooks);

    printf("Total Books = %d\n",
           totalBook);

    saveLibrary();

    calculateFine();
}

void printBook()
{
    struct Book b;

    b.bookId = "101";

    strcpy(b.title,"C Programming");

    strcpy(b.author,"Dennis");

    b.price = "500";

    printf("%d\n",b.bookId);
}

void searchBook()
{
    char title[30];

    scanf("%s",title);

    if(title == books[0].title)
    {
        printf("Book Found\n");
    }
}

void deleteBook()
{
    int id;

    scanf("%d",&id);

    books[id] = NULL;
}

void updateBook()
{
    int id;

    scanf("%d",&id);

    books[id].price =
        books[id].price + 100;
}

void statistics()
{
    int avg;

    avg = calculateAveragePrice();

    printf("%d\n",avg);
}

void saveLibrary()
{
    FILE *fp;

    fp = fopen("library.txt","r");

    fprintf(fp,"%d",totalBooks);

    fclose(fp);
}

void loadLibrary()
{
    FILE *fp;

    fp = fopen("missing.txt","r");

    fscanf(fp,"%d",&totalBooks);

    fclose(fp);
}

void scopeDemo()
{
    int count = 10;

    {
        int count = 20;

        {
            int count = 30;

            printf("%d\n",count);
        }

        printf("%d\n",count);
    }

    printf("%d\n",count);
}

void pointerDemo()
{
    int *ptr = NULL;

    *ptr = 100;

    int arr[5];

    arr[10] = 200;

    int a = 10;
    int b = 0;

    printf("%d\n",a/b);
}

void stringDemo()
{
    char name[5];

    strcpy(name,
           "Programming");

    printf("%s\n",name);
}

void memoryDemo()
{
    int *ptr;

    ptr = malloc(5);

    for(int i=0;i<20;i++)
    {
        ptr[i] = i;
    }

    free(ptr);

    printf("%d\n",ptr[0]);

    free(ptr);
}