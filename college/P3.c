#include <stdio.h>

typedef struct
{
    int hour;
    int minute;
    int second;
} Time;

/* Function declarations */
void readTime(Time *T);
void displayTime(Time *T);
void updateTime(Time *T);
void addTime(Time *T1, Time *T2);
void normalizeTime(Time *T);

int main()
{
    int choice;
    Time T1, T2;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Read Time\n");
        printf("2. Display Time\n");
        printf("3. Update Time\n");
        printf("4. Add Two Times\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                readTime(&T1);
                break;

            case 2:
                printf("Time: ");
                displayTime(&T1);
                break;

            case 3:
                updateTime(&T1);
                printf("Updated time: ");
                displayTime(&T1);
                break;

            case 4:
                printf("Enter first time:\n");
                readTime(&T1);

                printf("Enter second time:\n");
                readTime(&T2);

                addTime(&T1, &T2);

                printf("Resultant time: ");
                displayTime(&T1);
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/* Function to normalize time */
void normalizeTime(Time *T)
{
    T->minute = T->minute + T->second / 60;
    T->second = T->second % 60;

    T->hour = T->hour + T->minute / 60;
    T->minute = T->minute % 60;

    T->hour = T->hour % 24;
}

/* Function to read time */
void readTime(Time *T)
{
    printf("Enter hour: ");
    scanf("%d", &T->hour);

    printf("Enter minute: ");
    scanf("%d", &T->minute);

    printf("Enter second: ");
    scanf("%d", &T->second);

    normalizeTime(T);
}

/* Function to display time */
void displayTime(Time *T)
{
    printf("%02d:%02d:%02d\n",
           T->hour, T->minute, T->second);
}

/* Function to increment time by one second */
void updateTime(Time *T)
{
    T->second++;
    normalizeTime(T);
}

/* Function to add two times */
void addTime(Time *T1, Time *T2)
{
    T1->hour = T1->hour + T2->hour;
    T1->minute = T1->minute + T2->minute;
    T1->second = T1->second + T2->second;

    normalizeTime(T1);
}
