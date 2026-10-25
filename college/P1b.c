#include <stdio.h>

int main()
{
    int a[5], i;
    int *p;

    p = a;   // Pointer points to the first element of array

    printf("Enter 5 elements:\n");

    for(i = 0; i < 5; i++)
    {
        scanf("%d", p + i);
    }
    printf("\nArray elements are:\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n\nArray elements in reverse order:\n");
    for(i = 4; i >= 0; i--)
    {
        printf("%d ", *(p + i));
    }
    return 0;
}
