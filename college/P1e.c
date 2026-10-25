#include <stdio.h>

void Read(char *P)
{
    scanf("%s", P);
}

void Display(char *P)
{
    printf("%s", P);
}

void StrCat(char *PS1, char *PS2)
{
    while (*PS1 != '\0')
    {
        PS1++;
    }

    while (*PS2 != '\0')
    {
        *PS1 = *PS2;
        PS1++;
        PS2++;
    }

    *PS1 = '\0';
}

int main()
{
    char S1[100], S2[50];
    char *PS1, *PS2;

    PS1 = S1;
    PS2 = S2;

    printf("Enter first string: ");
    Read(PS1);
    printf("Enter second string: ");
    Read(PS2);
    printf("\nFirst string: ");
    Display(PS1);
    printf("\nSecond string: ");
    Display(PS2);
    StrCat(PS1, PS2);
    printf("\n\nAfter concatenation: ");
    Display(PS1);
    return 0;
}
