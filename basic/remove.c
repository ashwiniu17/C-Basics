#include <stdio.h>

int Remove(int *P, int N)
{
    int i, j = 0;

    for (i = 0; i < N; i++)
    {
        if (*(P+i) >= 0)
        {
            *(P+j) = *(P+i);
            j++;
        }
    }

    return j;
}

int main()
{
    int arr[10], N, i, remaining;

    printf("Enter the number of elements:\n");
    scanf("%d", &N);

    printf("Enter the array elements:\n");
    for (i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    remaining = Remove(arr, N);

    if (remaining == N)
    {
        printf("All elements are positive or zero.\n");
    }
    else if (remaining == 0)
    {
        printf("No elements remain after removing negatives.\n");
    }
    else
    {
        printf("Array after removing negative elements:\n");
        for (i = 0; i < remaining; i++)
            printf("%d ", arr[i]);
    }

    return 0;
}