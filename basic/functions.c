#include <stdio.h>
void greet(){
    printf("Hi Ashwini");
}
int add(int a , int b){
    int c;
    c = a+b;
    return c;
}
void main(){
    int a, b, sum;
    printf("Enter two number:\n");
    scanf("%d %d",&a, &b);
    sum= add(a,b);
    printf("Printing sum:%d", sum);
}