#include <stdio.h>
void main(){
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    
    if(age<=18){
        printf("Not eligible to vote");
    }
    else{
        printf("Eligible to vote");
    }
}