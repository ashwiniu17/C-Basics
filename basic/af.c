
#include <stdio.h>

void read(int *p, int n)
{
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", p+i);
}

void write(int *p, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", *(p+i));
}

void reverse(int *p, int n)
{
    int i, temp;
    for(i = 0; i < n/2; i++)
    {
        temp = *(p+i);
        *(p+i) = *(p+n-1-i);
        *(p+n-1-i) = temp;
    }
}

int searchDelete(int *p, int *n, int key)
{
    int i, j;

    for(i = 0; i < *n; i++)
    {
        if(*(p+i) == key)
        {
            for(j = i; j < *n-1; j++)
                *(p+j) = *(p+j+1);

            (*n)--;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int a[100], n, key;
    int (*fp)(int *, int *, int) = searchDelete;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    read(a, n);

    printf("Array: ");
    write(a, n);

    reverse(a, n);
    printf("\nReversed array: ");
    write(a, n);

    printf("\nEnter key to delete: ");
    scanf("%d", &key);

    if(fp(a, &n, key))
    {
        printf("After deletion: ");
        write(a, n);
    }
    else
        printf("Element not found");

    return 0;
}
