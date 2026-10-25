#include <stdio.h>
int  main ()
{
    int a[100],n,i,max,min;
    int *p=a;

    printf("Enter number of elements:");
    scanf("%d",&n);

    printf("Enter array elements");
    for ( i=0 ; i<n ;i++)
    scanf("%d",p+i);
    
}