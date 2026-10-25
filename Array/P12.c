/*Program 15. Count the Frequency of Each Character in a String
Question: Write a C program to count the frequency of each character in a string.*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[200];
    int freq[256] = {0};
    int i;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL)
    {
        return 1;
    }

    str[strcspn(str, "\n")] = '\0';

    for (i = 0; str[i] != '\0'; i++)
    {
        freq[(unsigned char)str[i]]++;
    }

    printf("Character frequencies:\n");

    for (i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
        {
            printf("%c : %d\n", i, freq[i]);
        }
    }

    return 0;
}