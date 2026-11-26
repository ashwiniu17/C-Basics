/*Develop a menu driven program to implement Stack with static and 
dynamic memory allocation mechanisms. (Represent Stack using 
structure) 
*/


//Dynamic memory allocation( using linkedin list )


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct stack
{
    struct node *top;
};

void push(struct stack *s)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter element to push: ");
        scanf("%d", &newnode->data);

        newnode->next = s->top;
        s->top = newnode;
    }
}

void pop(struct stack *s)
{
    struct node *temp;

    if(s->top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        temp = s->top;

        printf("Deleted element = %d\n", temp->data);

        s->top = s->top->next;
        free(temp);
    }
}

void display(struct stack *s)
{
    struct node *temp;

    if(s->top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        temp = s->top;

        printf("Stack elements are:\n");

        while(temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void clear(struct stack *s)
{
    struct node *temp;

    while(s->top != NULL)
    {
        temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

int main()
{
    struct stack s;
    int choice;

    s.top = NULL;

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
                clear(&s);
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 4);

    return 0;
}
