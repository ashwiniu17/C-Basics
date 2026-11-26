/*Develop a menu driven program to implement Stack with static and 
dynamic memory allocation mechanisms. (Represent Stack using 
structure) 
*/


//Static memory allocation( using array )

#include <stdio.h>
#define MAX 5

struct stack
{
    int a[MAX];
    int top;
};

void push(struct stack *s)
{
    int x;

    if(s->top == MAX-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter element to push: ");
        scanf("%d", &x);

        s->top++;
        s->a[s->top] = x;
    }
}

void pop(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Deleted element = %d\n", s->a[s->top]);
        s->top--;
    }
}

void display(struct stack *s)
{
    int i;

    if(s->top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack elements are:\n");

        for(i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->a[i]);
        }
    }
}

int main()
{
    struct stack s;
    int choice;

    s.top = -1;

    do
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push(&s);
                break;

            case 2:
                pop(&s);
                break;

            case 3:
                display(&s);
                break;

            case 4:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 4);

    return 0;
}
