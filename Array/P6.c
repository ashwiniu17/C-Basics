/*Program 6. Binary Search in a Sorted Array
Question: Write a C program to search for an element using binary search.
*/

#include <stdio.h>

int main(void)
{
    int a[100], n, i, key;
    int low, high, mid;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
        {
            printf("Element found at position %d\n", mid + 1);
            return 0;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("Element not found\n");

    return 0;
}
