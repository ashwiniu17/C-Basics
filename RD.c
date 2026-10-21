//Program to read and display array using pointer
/*
#include <stdio.h>
int main()
{
    int a[100],n , i;
    int *p=a;

    printf("Enter number of elements:");
    scanf("%d",&n);

    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
    scanf("%d",p+i);

    printf("Array elements are:\n");
    for (i=0 ;i<n ; i++)
    printf("%d",*(p+i));

    return 0;
}
*/
int main()
{
    int a[10],n, i;
    int *p= a;

    printf("Enter number of elements : ");
    scanf("%d",&n);

    printf("enter array elements: ");
    for(i=0; i<n ; i++)
    scanf("%d",p+i);

    printf("Array element are: ");
    for(i=0 ; i<n ;i++)
    printf("%d",*(p+i));

    return 0 ;


}