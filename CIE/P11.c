/*Program 16. Employee Salary Hike Using Structures
Question: Define an Employee structure with employee ID, name, salary, years of experience and department. Write a C program to calculate salary hikes using these rules:
- Experience below 5 years: 5% hike.
- Experience from 5 years to 10 years inclusive: 10% hike.
- Experience above 10 years: 15% hike.*/
#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
    int experience;
    char department[30];
};

int main(void)
{
    struct Employee e;
    float hike, newSalary;

    printf("Enter employee ID: ");
    scanf("%d", &e.id);

    printf("Enter employee name (one word): ");
    scanf("%49s", e.name);

    printf("Enter salary: ");
    scanf("%f", &e.salary);

    printf("Enter years of experience: ");
    scanf("%d", &e.experience);

    printf("Enter department (one word): ");
    scanf("%29s", e.department);

    if (e.experience < 0 || e.salary < 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    if (e.experience < 5)
        hike = 0.05f;
    else if (e.experience <= 10)
        hike = 0.10f;
    else
        hike = 0.15f;

    newSalary = e.salary + e.salary * hike;

    printf("\nEmployee Details\n");
    printf("ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Department: %s\n", e.department);
    printf("Experience: %d years\n", e.experience);
    printf("Original Salary: %.2f\n", e.salary);
    printf("Hike: %.0f%%\n", hike * 100);
    printf("Updated Salary: %.2f\n", newSalary);

    return 0;
}