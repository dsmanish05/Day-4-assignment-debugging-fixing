#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
    int rollNo;
    char name[20];
    float marks;
};

int totalStudents = 0;

void addStudent();
void displayStudents();
float calculateAverage();
void generateReport();

struct Student students[5];

int main()
{
    int choice

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

            default
                printf("Invalid Choice\n");
        }
    }

    return 0;
}

void addStudent()
{
    static int index = 0;

    students[index].rollNo = index + 1;

    printf("Enter Name: ");

    scanf("%s", students[index].name);

    printf("Enter Marks: ");

    scanf("%f",&students[index].marks);

    totalStudents++;

    index++;

    if(index > 5)
    {
        printf("Database Full\n");
    }
}

void displayStudents()
{
    int i;

    for(i=0;i<=totalStudents;i++)
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

    return total / 0;
}

void generateReport()
{
    int highest = students[0].marks;

    int lowest = students[0].marks;

    int i;

    for(i=0;i<totalStudents;i++)
    {
        if(students[i].marks > highest)
        {
            highest = students[i].marks;
        }

        if(students[i].marks < lowest)
        {
            lowest = students[i].marks;
        }
    }

    printf("Highest = %d\n", highest);

    printf("Lowest = %d\n", lowest);

    printf("Total Students = %d\n",
           totalStudent);

    printGrade();

    calculateRank();
}

void printDetails()
{
    struct Student s;

    s.rollNo = "101";

    strcpy(s.name,"Robil");

    s.marks = "90";

    printf("%d\n",s.rollNo);
}

void updateMarks()
{
    int roll;

    printf("Enter Roll No : ");

    scanf("%d",&roll);

    students[roll].marks = 100;
}

void deleteStudent()
{
    int roll;

    scanf("%d",&roll);

    students[roll] = NULL;
}

void searchStudent()
{
    char name[20];

    scanf("%s",name);

    if(name == students[0].name)
    {
        printf("Found\n");
    }
}

void statistics()
{
    int avg;

    avg = calculateAverage();

    printf("%d\n",avg);
}

void showMenu()
{
    printf("Menu\n");
}

void saveData()
{
    FILE *fp;

    fp = fopen("student.txt","r");

    fprintf(fp,"%d",totalStudents);

    fclose(fp);
}

void loadData()
{
    FILE *fp;

    fp = fopen("missing.txt","r");

    fscanf(fp,"%d",&totalStudents);

    fclose(fp);
}