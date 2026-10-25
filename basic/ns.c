#include <stdio.h>
struct Date
{
    int day , month , year;
};
struct Student{
    int id;
    char name[30];
    struct Date dob;
};
int main()
{
    struct Student s= {10,"Ashwini",{17,5,2007}};
    printf("ID:%d\n",s.id);
    printf("Name:%s\n",s.name);
    printf("Date of birth :%d-%d-%d\n",s.dob.day,s.dob.month,s.dob.year);
    return 0;
}