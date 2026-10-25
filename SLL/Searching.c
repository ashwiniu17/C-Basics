//11. Searching an Element in a Linked List
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
    int n, i, key, found = 0;

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

    printf("Enter element to search: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            found = 1;
            break;
        }

        temp = temp->next;
    }

    if (found)
        printf("Element found");
    else
        printf("Element not found");

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}