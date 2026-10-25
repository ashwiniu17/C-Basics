#include <stdio.h>
void main(){
    char name[50];
    int age;
    const float bb = 18.31;

    printf("Enter your name:  ");
    scanf("%s" ,name);

    printf("Enter your age:  ");
    scanf("%d" , &age);

    printf("Im %s and my age is %d and my bank balance is %f" , name, age , bb);
    
}