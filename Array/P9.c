#include <stdio.h>

int main(void)
{
    int a[100], n, i, j = 0;
    int *p = a;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid size\n");
        return 1;
    }

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }

    for (i = 0; i < n; i++)
    {
        if (*(p + i) >= 0)
        {
            *(p + j) = *(p + i);
            j++;
        }
    }

    n = j;

    printf("Array after removing negative elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }

    return 0;
}