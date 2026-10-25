#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *newnode;
    struct node *prev, *current, *next;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct node));

        if (newnode == NULL)
            return 1;

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
        {
            current = head;

            while (current->next != NULL)
                current = current->next;

            current->next = newnode;
        }
    }

    prev = NULL;
    current = head;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    printf("Reversed list: ");
    current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }

    return 0;
}