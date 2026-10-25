/*Program 13. Bubble Sort Using Dynamic Memory Allocation and Pointers
Question: Write a C program to dynamically allocate an array, read elements, sort them in ascending order using bubble sort and display the sorted array.*/
#include <stdio.h>
#include <stdlib.h>

int *bubbleSort(int *a, int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (*(a + j) > *(a + j + 1))
            {
                temp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = temp;
            }
        }
    }

    return a;
}

int main(void)
{
    int *a, *sorted;
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || (size_t)n > (size_t)-1 / sizeof(int))
    {
        printf("Invalid size\n");
        return 1;
    }

    a = malloc((size_t)n * sizeof(int));

    if (a == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }

    sorted = bubbleSort(a, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(sorted + i));
    }

    free(a);
    a = NULL;
    sorted = NULL;

    return 0;
}