#include <stdio.h>
struct Employee{
    char name[25];
    int emp_id;
    char dept_name[5];
    float salary;
    int experience;
};
int main()
{
    struct Employee e[10];
    int n,i;
    float hike;
    char dept_name[5];

    printf("enter nuber of employees:");
    scanf("%d",&n);

    for(i=0 ; i<n ; i++)
    {
        printf("\n Enter details of employee %d:\n",i+1);

        printf("Enter name, emp_id,dept_name, salary ,experience:\n");
        scanf("%24s %d %24s %f %d", e[i].name, &e[i].id , e[i].department, &e[i].salary , &e[i].experience) ;   
    }
    printf("\nEnter department to display: ");
    scanf("%49s", dept);

    printf("\nEmployees in department: %s\n", dept);

    for (i = 0; i < n; i++)
    {
        if (strcmp(e[i].department, dept) == 0)
        {
            if (e[i].experience < 5)
                hike = 5;
            else if (e[i].experience <= 10)
                hike = 10;
            else
                hike = 15;

            newSalary = e[i].salary +
                        (e[i].salary * hike / 100);

            printf("\nName: %s\n", e[i].name);
            printf("Employee ID: %d\n", e[i].id);
            printf("Department: %s\n", e[i].department);
            printf("Original Salary: %.2f\n", e[i].salary);
            printf("Salary Hike: %.0f%%\n", hike);
            printf("Salary after Hike: %.2f\n", newSalary);
            printf("Experience: %d years\n", e[i].experience);
        }
    }

    return 0;
}