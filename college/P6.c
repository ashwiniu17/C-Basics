/*Develop a menu driven program to implement Circular singly linked list 
with various operations such as (Note: Use Header node to simplify he 
complex operations)  
i) Insertion and Deletion at front/rear  
ii) Insertion and Deletion at the specified position 
iii) Delete by Key 
iv) Search by key 
v) Create an ordered list  
vi) Reverse a list  
vii) Creating a copy of the list  */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;

/* Function declarations */
NODE *createHeader(void);
NODE *insertFront(NODE *head, int x);
NODE *insertRear(NODE *head, int x);
NODE *deleteFront(NODE *head);
NODE *deleteRear(NODE *head);
NODE *insertPosition(NODE *head, int x, int pos);
NODE *deletePosition(NODE *head, int pos);
NODE *deleteKey(NODE *head, int key);
void search(NODE *head, int key);
NODE *createOrdered(NODE *head, int x);
NODE *reverse(NODE *head);
NODE *copyList(NODE *head);
void display(NODE *head);
void freeList(NODE *head);

/* Create header node */
NODE *createHeader(void)
{
    NODE *head = (NODE *)malloc(sizeof(NODE));

    if (head == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    head->next = head;
    return head;
}

/* Insert at front */
NODE *insertFront(NODE *head, int x)
{
    NODE *newnode;

    newnode = (NODE *)malloc(sizeof(NODE));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    newnode->data = x;
    newnode->next = head->next;
    head->next = newnode;

    return head;
}

/* Insert at rear */
NODE *insertRear(NODE *head, int x)
{
    NODE *newnode, *temp;

    newnode = (NODE *)malloc(sizeof(NODE));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    newnode->data = x;

    temp = head;

    while (temp->next != head)
        temp = temp->next;

    newnode->next = head;
    temp->next = newnode;

    return head;
}

/* Delete at front */
NODE *deleteFront(NODE *head)
{
    NODE *temp;

    if (head->next == head)
    {
        printf("List is empty\n");
        return head;
    }

    temp = head->next;
    head->next = temp->next;

    free(temp);

    return head;
}

/* Delete at rear */
NODE *deleteRear(NODE *head)
{
    NODE *temp, *prev;

    if (head->next == head)
    {
        printf("List is empty\n");
        return head;
    }

    prev = head;
    temp = head->next;

    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);

    return head;
}

/* Insert at specified position */
NODE *insertPosition(NODE *head, int x, int pos)
{
    NODE *newnode, *temp;
    int i;

    if (pos < 1)
    {
        printf("Invalid position\n");
        return head;
    }

    temp = head;

    for (i = 1; i < pos && temp->next != head; i++)
        temp = temp->next;

    if (i != pos)
    {
        printf("Invalid position\n");
        return head;
    }

    newnode = (NODE *)malloc(sizeof(NODE));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    newnode->data = x;
    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

/* Delete at specified position */
NODE *deletePosition(NODE *head, int pos)
{
    NODE *temp, *prev;
    int i;

    if (pos < 1 || head->next == head)
    {
        printf("Invalid position or empty list\n");
        return head;
    }

    prev = head;
    temp = head->next;

    for (i = 1; i < pos && temp != head; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head)
    {
        printf("Invalid position\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

/* Delete by key */
NODE *deleteKey(NODE *head, int key)
{
    NODE *temp, *prev;

    prev = head;
    temp = head->next;

    while (temp != head)
    {
        if (temp->data == key)
        {
            prev->next = temp->next;
            free(temp);
            printf("Key deleted successfully\n");
            return head;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Key not found\n");
    return head;
}

/* Search by key */
void search(NODE *head, int key)
{
    NODE *temp;
    int pos = 1;

    temp = head->next;

    while (temp != head)
    {
        if (temp->data == key)
        {
            printf("Element found at position %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Element not found\n");
}

/* Create ordered list (Ascending order) */
NODE *createOrdered(NODE *head, int x)
{
    NODE *newnode, *temp, *prev;

    newnode = (NODE *)malloc(sizeof(NODE));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    newnode->data = x;
    temp = head->next;
    prev = head;

    while (temp != head && temp->data <= x)
    {
        prev = temp;
        temp = temp->next;
    }

    newnode->next = temp;
    prev->next = newnode;

    return head;
}

/* Reverse the list */
NODE *reverse(NODE *head)
{
    NODE *prev, *current, *next;

    prev = head;
    current = head->next;

    while (current != head)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head->next = prev;

    return head;
}

/* Create a copy of the list */
NODE *copyList(NODE *head)
{
    NODE *copy, *temp, *last, *newnode;

    copy = createHeader();
    temp = head->next;
    last = copy;

    while (temp != head)
    {
        newnode = (NODE *)malloc(sizeof(NODE));

        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return copy;
        }

        newnode->data = temp->data;
        newnode->next = copy;
        last->next = newnode;
        last = newnode;

        temp = temp->next;
    }

    return copy;
}

/* Display the list */
void display(NODE *head)
{
    NODE *temp;

    if (head->next == head)
    {
        printf("List is empty\n");
        return;
    }

    temp = head->next;

    printf("HEADER -> ");

    while (temp != head)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("HEADER\n");
}

/* Free the list */
void freeList(NODE *head)
{
    NODE *temp, *next;

    temp = head->next;

    while (temp != head)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }

    free(head);
}

/* Main function */
int main()
{
    NODE *head = createHeader();
    NODE *copy = NULL;

    int choice, x, pos, key;

    while (1)
    {
        printf("\n----- CIRCULAR SINGLY LINKED LIST -----\n");

        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete at Front\n");
        printf("4. Delete at Rear\n");
        printf("5. Insert at Specified Position\n");
        printf("6. Delete at Specified Position\n");
        printf("7. Delete by Key\n");
        printf("8. Search by Key\n");
        printf("9. Create Ordered List\n");
        printf("10. Reverse the List\n");
        printf("11. Copy the List\n");
        printf("12. Display the List\n");
        printf("13. Display Copied List\n");
        printf("14. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &x);
                head = insertFront(head, x);
                break;

            case 2:
                printf("Enter the element: ");
                scanf("%d", &x);
                head = insertRear(head, x);
                break;

            case 3:
                head = deleteFront(head);
                break;

            case 4:
                head = deleteRear(head);
                break;

            case 5:
                printf("Enter the element: ");
                scanf("%d", &x);
                printf("Enter the position: ");
                scanf("%d", &pos);
                head = insertPosition(head, x, pos);
                break;

            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                head = deletePosition(head, pos);
                break;

            case 7:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                head = deleteKey(head, key);
                break;

            case 8:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                search(head, key);
                break;

            case 9:
                printf("Enter the element: ");
                scanf("%d", &x);
                head = createOrdered(head, x);
                break;

            case 10:
                head = reverse(head);
                printf("List reversed successfully\n");
                break;

            case 11:
                if (copy != NULL)
                    freeList(copy);
                copy = copyList(head);
                printf("List copied successfully\n");
                break;

            case 12:
                display(head);
                break;

            case 13:
                if (copy == NULL)
                    printf("No copied list available\n");
                else
                    display(copy);
                break;

            case 14:
                if (copy != NULL)
                    freeList(copy);
                freeList(head);
                printf("Exiting the program...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
