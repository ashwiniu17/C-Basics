
#include <stdio.h>

void Read(int *P, int n)
{
    int i;

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", P + i);
    }
}

void Display(int *P, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%d ", *(P + i));
    }
}

void Reverse(int *P, int n)
{
    int i, temp;

    for(i = 0; i < n / 2; i++)
    {
        temp = *(P + i);
        *(P + i) = *(P + n - 1 - i);
        *(P + n - 1 - i) = temp;
    }
}

int main()
{
    int a[5],  *P;

    P = a;
    Read(P, 5);
    printf("\nArray before reverse:\n");
    Display(P, 5);
    Reverse(P, 5);
    printf("\n\nArray after reverse:\n");
    Display(P, 5);
    return 0;
}
