#include <stdio.h>

void read(int *p, int n)
{
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", p+i);
}

void display(int *p, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", *(p+i));
    printf("\n");
}

void reverse(int *p, int n)
{
    int i;
    for(i = n-1; i >= 0; i--)
        printf("%d ", *(p+i));
    printf("\n");
}

int delete(int *p, int *n, int key)
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
    int (*fp)(int *, int *, int) = delete;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    read(a, n);

    printf("Array: ");
    display(a, n);

    printf("Reverse: ");
    reverse(a, n);

    printf("Enter element to delete: ");
    scanf("%d", &key);

    if(fp(a, &n, key))
    {
        printf("After deletion: ");
        display(a, n);
    }
    else
        printf("Element not found");

    return 0;
}
