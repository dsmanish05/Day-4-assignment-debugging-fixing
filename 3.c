```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
    int rollNo;
    char name[20];
    float marks;
};

int totalStudents = 0;   // Global variable

void addStudent();
void displayStudents();
float calculateAverage();
void generateReport();

struct Student students[5];   // Array of structure, size 5

int main()
{
    int choice   // Syntax Error: semicolon missing (;)

    printf("Student Management System\n");

    while(1)
    {
        printf("\n1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Average Marks\n");
        printf("4. Report\n");
        printf("5. Exit\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                printf("Average = %.2f\n",
                       calculateAverage());
                break;

            case 4:
                generateReport();
                break;

            case 5:
                exit(0);

            default   // Syntax Error: colon missing after default
                printf("Invalid Choice\n");
        }
    }

    return 0;
}

void addStudent()
{
    static int index = 0;

    students[index].rollNo = index + 1; // Runtime Error: index may go out of array size after 5 students

    printf("Enter Name: ");

    scanf("%s", students[index].name); // Runtime Error: no width limit, may overflow name[20]

    printf("Enter Marks: ");

    scanf("%f",&students[index].marks);

    totalStudents++;

    index++;

    if(index > 5) // Logical Error: condition should be checked before inserting data, and should be index >= 5
    {
        printf("Database Full\n");
    }
}

void displayStudents()
{
    int i;

    for(i=0;i<=totalStudents;i++) // Array Bounds/Logical Error: should be i < totalStudents
    {
        printf("\nRoll No : %d\n",
               students[i].rollNo);

        printf("Name : %s\n",
               students[i].name);

        printf("Marks : %.2f\n",
               students[i].marks);
    }
}

float calculateAverage()
{
    int i;

    float total = 0;

    for(i=0;i<totalStudents;i++)
    {
        total += students[i].marks;
    }

    return total / 0; // Runtime Error: division by zero, should divide by totalStudents
}

void generateReport()
{
    int highest = students[0].marks; // Type Mismatch/Logic Error: marks is float, highest should be float

    int lowest = students[0].marks; // Type Mismatch/Logic Error: marks is float, lowest should be float

    int i;

    for(i=0;i<totalStudents;i++)
    {
        if(students[i].marks > highest)
        {
            highest = students[i].marks; // Type Mismatch: float value assigned to int
        }

        if(students[i].marks < lowest)
        {
            lowest = students[i].marks; // Type Mismatch: float value assigned to int
        }
    }

    printf("Highest = %d\n", highest); // Format/Logic Error: marks are float, use %.2f

    printf("Lowest = %d\n", lowest); // Format/Logic Error: marks are float, use %.2f

    printf("Total Students = %d\n",
           totalStudent); // Undeclared Variable Error: totalStudent is not declared, correct variable is totalStudents

    printGrade(); // Linker Error: function declared/defined nahi hai

    calculateRank(); // Linker Error: function declared/defined nahi hai
}

void printDetails()
{
    struct Student s;

    s.rollNo = "101"; // Type Mismatch Error: string assigned to int

    strcpy(s.name,"Robil"); // Valid string copy

    s.marks = "90"; // Type Mismatch Error: string assigned to float

    printf("%d\n",s.rollNo);
}

void updateMarks()
{
    int roll;

    printf("Enter Roll No : ");

    scanf("%d",&roll);

    students[roll].marks = 100; // Array Bounds/Logical Error: roll may be outside valid index range
}

void deleteStudent()
{
    int roll;

    scanf("%d",&roll);

    students[roll] = NULL; // Type Mismatch Error: NULL cannot be assigned to structure variable
}

void searchStudent()
{
    char name[20];

    scanf("%s",name);

    if(name == students[0].name) // Logical Error: strings cannot be compared using ==, use strcmp()
    {
        printf("Found\n");
    }
}

void statistics()
{
    int avg;

    avg = calculateAverage(); // Type Mismatch Error: float return value stored in int

    printf("%d\n",avg); // Format/Logic Error: average should be printed with %f or %.2f
}

void showMenu()
{
    printf("Menu\n");
}

void saveData()
{
    FILE *fp;

    fp = fopen("student.txt","r"); // File Handling Error: file opened in read mode but used for writing

    fprintf(fp,"%d",totalStudents); // Runtime/File Error: fp may be NULL, and mode should be "w"

    fclose(fp); // Runtime Error: fclose on NULL pointer possible if fopen fails
}

void loadData()
{
    FILE *fp;

    fp = fopen("missing.txt","r"); // File Handling Error: file may not exist

    fscanf(fp,"%d",&totalStudents); // Runtime/File Error: fp may be NULL, check before reading

    fclose(fp); // Runtime Error: fclose on NULL pointer possible if fopen fails
}
```
