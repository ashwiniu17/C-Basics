#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
struct Student 
{ 
    char name[50]; 
    int reg_no; 
    float marks[3]; 
    float average_marks; 
}; 
 
/* Function to read student information */ 
void readStudents(struct Student *s, int n) 
{ 
    int i, j; 
 
    for (i = 0; i < n; i++) 
    { 
        printf("\nEnter details of Student %d\n", i + 1); 
 
        printf("Enter Name: "); 
        scanf(" %[^\n]", (s + i)->name); 
 
        printf("Enter Register Number: "); 
        scanf("%d", &(s + i)->reg_no); 
 
        for (j = 0; j < 3; j++) 
        { 
            printf("Enter marks in Test %d: ", j + 1); 
            scanf("%f", &(s + i)->marks[j]); 
        } 
 
        (s + i)->average_marks = 0; 
    } 
} 
 
/* Function to calculate average of best two marks */ 
void calculateAverage(struct Student *s, int n) 
{ 
    int i; 
    float m1, m2, m3, sum; 
 
    for (i = 0; i < n; i++) 
    { 
        m1 = (s + i)->marks[0]; 
        m2 = (s + i)->marks[1]; 
        m3 = (s + i)->marks[2]; 
 
        /* Find sum of best two marks */ 
        if (m1 <= m2 && m1 <= m3) 
            sum = m2 + m3; 
        else if (m2 <= m1 && m2 <= m3) 
            sum = m1 + m3; 
        else 
            sum = m1 + m2; 
 
        (s + i)->average_marks = sum / 2; 
    } 
 
    printf("\nAverage of best two marks calculated successfully.\n"); 
} 
 
/* Function to display student information */ 
void displayStudents(struct Student *s, int n) 
{ 
    int i; 
 
    printf("\n------------------------------------------------------------\n"); 
    printf("Name\t\tReg.No\tTest1\tTest2\tTest3\tAverage\n"); 
    printf("------------------------------------------------------------\n"); 
 
    for (i = 0; i < n; i++) 
    { 
        printf("%-15s %d\t%.2f\t%.2f\t%.2f\t%.2f\n", 
               (s + i)->name, 
               (s + i)->reg_no, 
               (s + i)->marks[0], 
               (s + i)->marks[1], 
               (s + i)->marks[2], 
               (s + i)->average_marks); 
    } 
 
    printf("------------------------------------------------------------\n"); 
} 
 
int main() 
{ 
    struct Student *ptr; 
    int n, choice; 
 
    printf("Enter number of students: "); 
    scanf("%d", &n); 
 
    /* Dynamic memory allocation */ 
    ptr = (struct Student *)malloc(n * sizeof(struct Student)); 
 
    if (ptr == NULL) 
    { 
        printf("Memory allocation failed!\n"); 
        return 1; 
    } 
 
    do 
    { 
        printf("\n========== MENU ==========\n"); 
        printf("1. Read Student Information\n"); 
        printf("2. Display Student Information\n"); 
        printf("3. Calculate Average of Best Two Tests\n"); 
        printf("4. Exit\n"); 
        printf("==========================\n"); 
 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) 
        { 
            case 1: 
                readStudents(ptr, n); 
                break; 
 
            case 2: 
                displayStudents(ptr, n); 
                break; 
 
            case 3: 
                calculateAverage(ptr, n); 
                break; 
 
            case 4: 
                printf("\nExiting program...\n"); 
                break; 
 
            default: 
                printf("\nInvalid choice! Please try again.\n"); 
        } 
} while (choice != 4); 
/* Free dynamically allocated memory */ 
free(ptr); 
return 0; 
}