/*Program 7. Reverse an Array Using a Function and Pointers
Question: Write a C program to reverse an array using pointers and a function*/
#include <stdio.h>

void reverse(int *p, int n)
{
    int i, temp;

    for (i = 0; i < n / 2; i++)
    {
        temp = *(p + i);
        *(p + i) = *(p + n - 1 - i);
        *(p + n - 1 - i) = temp;
    }
}

int main(void)
{
    int a[100], n, i;

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
        scanf("%d", &a[i]);
    }

    reverse(a, n);

    printf("Reversed array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}