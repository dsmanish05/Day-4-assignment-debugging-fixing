```c
#include <stdio.h>

int totalStudents = 500;   // Global variable

void updateCount();
void displayData(int value);

int main()
{
    int department = 1   // Syntax Error: semicolon missing (;)

    int marks = "90";    // Type Mismatch Error: int me string assign kiya hai

    printf("Program Started\n");

    int x = 10;

    {
        int x = 20;      // Shadowing Issue: inner x outer x ko hide kar raha hai
        printf("Inner x = %d\n", x);
    }

    printf("Outer x = %d\n", x);

    if(x = 10)           // Logical Error: comparison ke liye == hona chahiye
    {
        printf("X is Ten\n");
    }

    printf("%d\n", score);   // Undeclared Variable Error: score declare nahi hai

    int totalStudents = 100;  // Shadowing Issue: local variable global totalStudents ko hide kar raha hai

    printf("Students = %d\n", totalStudents);

    {
        int department = 2;   // Shadowing Issue: inner department outer department ko hide kar raha hai
        printf("Department = %d\n", department);
    }

    printf("Department = %d\n", department);

    int a = 10;
    int b = 20;

    int sum;

    sum = add(a,b);      // Linker Error: add() function declared/defined nahi hai

    printf("Sum = %d\n", sum);

    {
        int temp = 50;   // temp sirf is block ke andar accessible hai
    }

    printf("%d\n", temp);    // Scope Error: temp block ke bahar use ho raha hai

    int arr[5];

    arr[10] = 100;       // Array Bounds Error: arr[5] me valid index 0 to 4 hai

    float salary = 50000.50;

    printf("%d\n", salary);  // Format Specifier Error: float ke liye %f use hota hai

    int count = 10;

    {
        count = count + 5;

        int count = 100;     // Shadowing Issue: naya local count ban gaya

        printf("%d\n", count);
    }

    printf("%d\n", count);

    int i;

    for(i=0;i<5;i++)
    {
        int result = i * 10; // Scope Error: result sirf loop ke andar accessible hai
    }

    printf("%d\n", result);  // Scope Error: result loop ke bahar use ho raha hai

    int age = 18;

    if(age > 18)
        printf("Eligible\n");
    else
        printf("Eligible\n"); // Logical Error: else me Not Eligible hona chahiye

    int value = 50;

    displayData();       // Function Call Error: displayData ko ek argument chahiye

    updateCount();

    printf("%d\n", totalStudents);

    {
        int totalStudents = 200; // Shadowing Issue
        printf("%d\n", totalStudents);
    }

    printf("%d\n", totalStudents);

    int y = 100;

    {
        int y = 200;     // Shadowing Issue

        {
            int y = 300; // Shadowing Issue
            printf("%d\n", y);
        }

        printf("%d\n", y);
    }

    printf("%d\n", y);

    int z = 10;

    while(z > 0);        // Logical/Runtime Error: semicolon se infinite loop ho sakta hai
    {
        z--;
    }

    char grade = "A";    // Type Mismatch Error: char ke liye 'A' use hota hai

    int number = 50;

    printf("%s\n", number); // Format Specifier Error: int ke liye %d use hota hai

    int *ptr = NULL;

    *ptr = 100;          // Runtime Error: NULL pointer dereference

    int average;

    average = calculateAverage(10,20); // Linker Error: calculateAverage() defined nahi hai

    printf("%d\n", average);

    return 0;
}

void updateCount()
{
    totalStudents = totalStudents + 10;
}

void displayData(int value)
{
    printf("Value = %d\n", value);
}
