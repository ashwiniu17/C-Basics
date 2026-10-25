#include <stdio.h>
struct Student
{
    int id;
    float marks;
};
void display (struct Student *p)
{
    printf("ID=%d\n",p->id);
    printf("Marks=%.2f\n",p->marks);
}
int main()
{
    struct Student s = {1,85.5};
    display(&s);
    return 0;
}