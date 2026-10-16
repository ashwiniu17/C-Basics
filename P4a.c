#include <stdio.h>

#define MAX 100

void display(int a[], int n)
{
    int i;
    printf("Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void insertPos(int a[], int *n, int pos, int key)
{
    int i;
    for (i = *n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = key;
    (*n)++;
}

void deletePos(int a[], int *n)
{
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > *n)
    {
        printf("Invalid position\n");
        return;
    }

    for (i = pos - 1; i < *n - 1; i++)
        a[i] = a[i + 1];

    (*n)--;
}

void insertKey(int a[], int *n, int key, int value)
{
    int i, pos = -1;

    for (i = 0; i < *n; i++)
    {
        if (a[i] == key)
        {
            pos = i + 1;
            break;
        }
    }

    if (pos == -1)
    {
        printf("Key not found\n");
        return;
    }

    for (i = *n; i > pos; i--)
        a[i] = a[i - 1];

    a[pos] = value;
    (*n)++;
}

void deleteKey(int a[], int *n)
{
    int key, i, pos = -1;

    printf("Enter key: ");
    scanf("%d", &key);

    for (i = 0; i < *n; i++)
    {
        if (a[i] == key)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        printf("Key not found\n");
        return;
    }

    for (i = pos; i < *n - 1; i++)
        a[i] = a[i + 1];

    (*n)--;
}

void insertOrder(int a[], int *n, int key)
{
    int i = *n - 1;

    while (i >= 0 && a[i] > key)
    {
        a[i + 1] = a[i];
        i--;
    }

    a[i + 1] = key;
    (*n)++;
}

void searchKey(int a[], int n)
{
    int key, i, found = 0;

    printf("Enter key: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("Found at position %d\n", i + 1);
            found = 1;
        }
    }

    if (!found)
        printf("Key not found\n");
}

void searchPos(int a[], int n)
{
    int pos;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n)
        printf("Invalid position\n");
    else
        printf("Element = %d\n", a[pos - 1]);
}

void reverse(int a[], int n)
{
    int i, temp;

    for (i = 0; i < n / 2; i++)
    {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
}

int main()
{
    int a[MAX];
    int n, i, choice;
    int pos, key, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 0 || n > MAX)
    {
        printf("Invalid number of elements\n");
        return 1;
    }

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    while (1)
    {
        printf("\n1. Insert by position");
        printf("\n2. Delete by position");
        printf("\n3. Insert by key");
        printf("\n4. Delete by key");
        printf("\n5. Insert by order");
        printf("\n6. Search by key");
        printf("\n7. Search by position");
        printf("\n8. Reverse");
        printf("\n9. Display");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (n == MAX)
                {
                    printf("Array is full\n");
                    break;
                }

                printf("Enter position and value: ");
                scanf("%d%d", &pos, &value);

                if (pos < 1 || pos > n + 1)
                {
                    printf("Invalid position\n");
                    break;
                }

                insertPos(a, &n, pos, value);
                break;

            case 2:
                deletePos(a, &n);
                break;

            case 3:
                if (n == MAX)
                {
                    printf("Array is full\n");
                    break;
                }

                printf("Enter key and value: ");
                scanf("%d%d", &key, &value);

                insertKey(a, &n, key, value);
                break;

            case 4:
                deleteKey(a, &n);
                break;

            case 5:
                if (n == MAX)
                {
                    printf("Array is full\n");
                    break;
                }

                printf("Enter value: ");
                scanf("%d", &key);

                insertOrder(a, &n, key);
                break;

            case 6:
                searchKey(a, n);
                break;

            case 7:
                searchPos(a, n);
                break;

            case 8:
                reverse(a, n);
                break;

            case 9:
                display(a, n);
                break;

            case 0:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
