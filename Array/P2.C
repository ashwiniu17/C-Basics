// Write a C program to dynamically allocate memory for an array
// and display its elements using pointers.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i;
    int *a, *p, *end;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    if (a == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    p = a;
    end = a + n;

    printf("Array elements are:\n");
    while (p < end)
    {
        printf("%d ", *p);
        p++;
    }

    free(a);

    return 0;
}