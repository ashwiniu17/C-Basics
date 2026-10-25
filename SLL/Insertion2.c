//C. Insertion at a specified position
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *newnode, *temp;
    int n, i, pos, value;

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
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }

    printf("Enter value and position: ");
    scanf("%d%d", &value, &pos);

    newnode = malloc(sizeof(struct node));

    if (newnode == NULL)
        return 1;

    newnode->data = value;

    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else if (pos > 1)
    {
        temp = head;

        for (i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL)
        {
            printf("Invalid position");
            free(newnode);
            return 0;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        printf("Invalid position");
        free(newnode);
        return 0;
    }

    printf("Updated list: ");
    temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}