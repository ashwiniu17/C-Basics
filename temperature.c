#include <stdio.h>
void main(){
    float temperature;
    printf("Enter temperature: ");
    scanf("%f" ,&temperature);

    if(temperature<=20){
        printf("Wear a sweather!\n");
    }
    else if (temperature>20 && temperature<30){
        printf("Normal\n");
    }
    else{
        printf("Wear a tshirt and drink more water!\n");
    }
}