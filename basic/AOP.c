#include <stdio.h>
int main(){
    int a = 10, b = 20, c = 30;
    int *p[3] = {&a, &b, &c};

    printf("%d", *p[1]);
    return 0;
    
}
