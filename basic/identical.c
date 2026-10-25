#include <stdio.h>
int identical (int *a, int *b , int n)
{
    int i;

    for (i=0 ; i<n ; i++){
        if(*(a+i) !=*(b+i))
        return 0;
    }
    return 1;
}
int  main()
{
    int a[10],b[10],n,i;

    printf("Enter number of elements:");
    scanf("%d",&n);

    printf("Enter first array:\n");
    for(i=0 ;i<n ;i++)
    scanf("%d",&a[i]);

    printf("Enter second array:\n");
    for (i=0 ; i<n ;i++)
    scanf("%d",&b[i]);

    if(identical (a,b,n))
    printf("Arrays are identical");

    else
       printf("Array are not identical");

  return 0;
}