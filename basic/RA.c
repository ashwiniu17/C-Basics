#include <stdio.h>
int main()
{
    int a[10], n,i;
    int *p=a;

    printf("Enter the number of elements");
    scanf("%d",&n);

    printf("Enter array elements");
    for(i=0;i<n;i++)
    scanf("%d",p+i);

    printf("Array in reverse order");
    for (i=n-1;i>=0;i--)
    printf("%d",*(p+i));

    return 0;
}