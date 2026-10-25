#include <stdio.h>
int main()
{
    char a[30]="Hello";
    char b[30]="World";
    
    printf("Lenght=%zu\n",strlen(a));

    strcpy(b,a);
    printf("Copy =%s\n",b);

    printf("Compare =%d\n",strcmp(a,b));

    strcat(a,b);
    printf("Concatenate = %s\n" ,a);

    return 0;
  
}