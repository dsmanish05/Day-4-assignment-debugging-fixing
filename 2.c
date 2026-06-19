```c
#include <stdio.h>

extern int total;   // Linker Error: 'total' is declared but not defined

void update();
void display();

int main()
{
    int marks = "90";   // Type Mismatch Error: string assigned to integer

    auto int age = 20;  // Valid auto variable

    register int count = 100; // Valid register variable

    printf("Program Started\n") // Syntax Error: missing semicolon (;)

    static int visits = 0; // Valid static variable

    visits++;

    printf("Visits = %d\n", visits);

    printf("%d\n", total); // Linker Error: 'total' definition is missing

    int x = 10;

    {
        int x = 20; // Shadowing Issue: inner x hides outer x
        printf("Inner X = %d\n", x);
    }

    printf("Outer X = %d\n", x);

    int result = add(10,20); // Function Error: function prototype missing before main()

    printf("%d\n", result);

    register int number = 50;

    printf("%d\n", &number); // Error: address of register variable cannot be accessed

    static int salary = "50000"; // Type Mismatch Error: string assigned to integer

    printf("%d\n", salary);

    {
        int department = 1; // Accessible only inside this block
    }

    printf("%d\n", department); // Scope Error: department used outside its scope

    int i;

    for(i=0;i<5;i++)
    {
        int temp = i * 10; // Accessible only inside loop
    }

    printf("%d\n", temp); // Scope Error: temp used outside loop

    int arr[5];

    arr[10] = 500; // Array Bounds Error: valid index range is 0 to 4

    int a = 10;
    int b = 0;

    printf("%d\n", a/b); // Runtime Error: division by zero

    int value = 100;

    if(value = 100) // Logical Error: assignment operator used instead of ==
    {
        printf("Hundred\n");
    }

    int score = 90;

    if(score > 80)
        printf("Pass\n");
    else
        printf("Pass\n"); // Logical Error: both branches print the same output

    static int counter = 0;

    counter++;

    printf("%d\n", counter);

    display();

    update(); // Linker Error: update() uses undefined variable 'total'

    char grade = "A"; // Type Mismatch Error: char should use single quotes

    printf("%c\n", grade);

    int totalMarks = 500;

    {
        int totalMarks = 100; // Shadowing Issue

        {
            int totalMarks = 50; // Shadowing Issue
            printf("%d\n", totalMarks);
        }

        printf("%d\n", totalMarks);
    }

    printf("%d\n", totalMarks);

    int data;

    printf("%d\n", data); // Runtime/Semantic Error: uninitialized variable

    int *ptr = NULL;

    *ptr = 100; // Runtime Error: NULL pointer dereference

    extern int companyCode; // Linker Error: declared but not defined

    printf("%d\n", companyCode); // Linker Error: definition missing

    int average;

    average = calculateAverage(10,20); // Linker Error: function not defined

    printf("%d\n", average);

    int employeeId = "EMP101"; // Type Mismatch Error: string assigned to integer

    printf("%d\n", employeeId);

    while(counter > 0); // Logical Error: unwanted semicolon creates infinite loop
    {
        counter--;
    }

    int y = 50;

    {
        int y = 100; // Shadowing Issue
        printf("%d\n", y);
    }

    printf("%d\n", y);

    return 0;
}

void update()
{
    total = total + 1; // Linker Error: total is not defined
}

void display()
{
    printf("Display Function\n");
}

int add(int a, int b)
{
    return a + b;
}
```
