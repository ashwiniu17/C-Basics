#include <stdio.h>
/*int main()
{
    int a=10;
    int *p=&a;
    printf("The value of a=%d\n", a);
    printf("address of a =%p\n",&a);
    printf("The value of a using pointer = %d\n" , *p);
    return 0 ;
}
*/
/*int main()
{
    int a[]={10,20,30};
    int *p = a+1;
    printf("%d\n", *p);
    p--;
    printf("%d\n",*p);
    p++;
    printf("%d\n",*p);
    return 0;
}
*/
int main()
{
    int a = 71 ;
    int *p= &a;
    int **q= &p;
    printf("%d",**q);
    return 0;
    
}