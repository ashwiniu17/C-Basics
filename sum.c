#include <stdio.h>
int main()
{
    int a[100],n,i,sum;
    float avg;
    int *p=a;
    printf("Enter number of elements");
    scanf("%d", &n);

    printf("Enter array elements");
    sum=0;

    for(i=0;i<n;i++){
    scanf("%d",p+i);
    sum=sum+*(p+i);
    }
    avg  = (float)sum/n;
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", avg);

    return 0;
}