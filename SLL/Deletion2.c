//Deletion at a specified position
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *newnode, *temp, *del;
    int n, i, pos;

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

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || head == NULL)
        printf("Invalid position");
    else if (pos == 1)
    {
        del = head;
        head = head->next;
        free(del);
    }
    else
    {
        temp = head;

        for (i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL || temp->next == NULL)
            printf("Invalid position");
        else
        {
            del = temp->next;
            temp->next = del->next;
            free(del);
        }
    }

    printf("\nUpdated list: ");
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