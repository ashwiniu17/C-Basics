#include <stdio.h>
void main(){
    int n = 4;
    int marks[n];
    printf("Enter Students Marks:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&marks[i]);
    }
    printf("Students marks are:\n");
    for(int i=0;i<n;i++){
        printf("%d ",marks[i]);
    }
}