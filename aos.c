#include <stdio.h>

struct Student
{
    int id;
    char name[30];
    float marks;
};

int main()
{
    struct Student s[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("Enter ID, name and marks:\n");
        scanf("%d %29s %f",
              &s[i].id, s[i].name, &s[i].marks);
    }

    printf("\nStudent Details:\n");

    for (i = 0; i < 3; i++)
    {
        printf("%d %s %.2f\n",
               s[i].id, s[i].name, s[i].marks);
    }

    return 0;
}