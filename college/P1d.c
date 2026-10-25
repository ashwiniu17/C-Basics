#include <stdio.h>

void Read(int (*p)[3], int rows)
{
    int i, j;

    printf("Enter matrix elements:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", *(p + i) + j);
        }
    }
}

void Display(int (*p)[3], int rows)
{
    int i, j;

    printf("Matrix elements are:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
}

int main()
{
    int a[2][3];
    int (*p)[3];

    p = a;       // Pointer to 2D array

    Read(p, 2);
    Display(p, 2);

    return 0;
}
