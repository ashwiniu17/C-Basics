# include<stdio.h>
int main()
{
    int X = 12;
    int *P3,  **P2,  ***P1;

    P3 = &X;       // P3 points to X
    P2 = &P3;      // P2 points to P3
    P1 = &P2;      // P1 points to P2

    printf("Value of X using P3 = %d\n", *P3);
    printf("Value of X using P2 = %d\n", **P2);
    printf("Value of X using P1 = %d\n", ***P1);
    return 0;
}
