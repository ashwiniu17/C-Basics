#include <stdio.h> 
#include <stdlib.h> 
typedef struct node 
{ 
int data; 
struct node *next; 
} NODE; 
/* Function declarations */ 
NODE *insert_front(NODE *first, int item); 
NODE *insert_rear(NODE *first, int item); 
NODE *insert_position(NODE *first, int item, int pos); 
NODE *delete_front(NODE *first); 
NODE *delete_rear(NODE *first); 
NODE *delete_position(NODE *first, int pos); 
void display(NODE *first); 
 
int main() 
{ 
    NODE *first = NULL; 
    int choice, item, pos; 
 
    while (1) 
    { 
        printf("\n\n----- SINGLY LINKED LIST -----"); 
        printf("\n1. Insert Front"); 
        printf("\n2. Insert Rear"); 
        printf("\n3. Insert at Position"); 
        printf("\n4. Delete Front"); 
        printf("\n5. Delete Rear"); 
        printf("\n6. Delete at Position"); 
        printf("\n7. Display"); 
        printf("\n8. Exit"); 
 
        printf("\nEnter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) 
        { 
            case 1: 
                printf("Enter item: "); 
                scanf("%d", &item); 
 
                first = insert_front(first, item); 
                break; 
 
            case 2: 
                printf("Enter item: "); 
                scanf("%d", &item); 
 
                first = insert_rear(first, item); 
                break; 
 
            case 3: 
                printf("Enter item: "); 
                scanf("%d", &item); 
 
                printf("Enter position: "); 
                scanf("%d", &pos); 
 
                first = insert_position(first, item, pos); 
                break; 
 
            case 4: 
                first = delete_front(first); 
                break; 
 
            case 5: 
                first = delete_rear(first); 
                break; 
 
            case 6: 
                printf("Enter position: "); 
                scanf("%d", &pos); 
 
                first = delete_position(first, pos); 
                break; 
 
            case 7: 
                display(first); 
                break; 
 
            case 8: 
                printf("\nProgram terminated."); 
                return 0; 
 
            default: 
                printf("\nInvalid choice!"); 
        } 
    } 
} 
 
 
/* Insert at Front */ 
NODE *insert_front(NODE *first, int item) 
{ 
    NODE *newnode; 
 
    newnode = (NODE *)malloc(sizeof(NODE)); 
 
    newnode->data = item; 
    newnode->next = first; 
 
    first = newnode; 
 
    return first; 
} 
 
 
/* Insert at Rear */ 
NODE *insert_rear(NODE *first, int item) 
{ 
    NODE *newnode, *temp; 
 
    newnode = (NODE *)malloc(sizeof(NODE)); 
 
    newnode->data = item; 
    newnode->next = NULL; 
 
    if (first == NULL) 
    { 
        first = newnode; 
    } 
    else 
    { 
        temp = first; 
 
        while (temp->next != NULL) 
        { 
            temp = temp->next; 
        } 
 
        temp->next = newnode; 
    } 
 
    return first; 
} 
 
 
/* Insert at Position */ 
NODE *insert_position(NODE *first, int item, int pos) 
{ 
    NODE *newnode, *temp; 
    int i; 
 
    if (pos <= 0) 
    { 
        printf("Invalid position!"); 
        return first; 
    } 
 
    newnode = (NODE *)malloc(sizeof(NODE)); 
 
    newnode->data = item; 
 
    /* Position 1 - insert at front */ 
    if (pos == 1) 
    { 
        newnode->next = first; 
        first = newnode; 
 
        return first; 
    } 
 
    temp = first; 
 
    /* Move to node before required position */ 
    for (i = 1; i < pos - 1 && temp != NULL; i++) 
    { 
        temp = temp->next; 
    } 
 
    if (temp == NULL) 
    { 
        printf("Invalid position!"); 
        free(newnode); 
 
        return first; 
    } 
 
    newnode->next = temp->next; 
    temp->next = newnode; 
 
    return first; 
} 
 
 
/* Delete from Front */ 
NODE *delete_front(NODE *first) 
{ 
    NODE *temp; 
 
    if (first == NULL) 
    { 
        printf("List is empty!"); 
        return first; 
    } 
 
    temp = first; 
 
    first = first->next; 
 
    printf("Deleted item = %d", temp->data); 
 
    free(temp); 
 
    return first; 
} 
 
 
/* Delete from Rear */ 
NODE *delete_rear(NODE *first) 
{ 
    NODE *temp, *prev; 
 
    if (first == NULL) 
    { 
        printf("List is empty!"); 
        return first; 
    } 
 
    /* Only one node */ 
    if (first->next == NULL) 
    { 
        printf("Deleted item = %d", first->data); 
 
        free(first); 
 
        return NULL; 
    } 
 
    temp = first; 
 
    while (temp->next != NULL) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
 
    prev->next = NULL; 
 
    printf("Deleted item = %d", temp->data); 
 
    free(temp); 
 
    return first; 
} 
 
 
/* Delete at Position */ 
NODE *delete_position(NODE *first, int pos) 
{ 
    NODE *temp, *prev; 
    int i; 
 
    if (first == NULL) 
    { 
        printf("List is empty!"); 
        return first; 
    } 
 
    if (pos <= 0) 
    { 
        printf("Invalid position!"); 
        return first; 
    } 
 
    /* Position 1 - delete from front */ 
    if (pos == 1) 
    { 
        temp = first; 
 
        first = first->next; 
 
        printf("Deleted item = %d", temp->data); 
 
        free(temp); 
 
        return first; 
    } 
 
    temp = first; 
 
    /* Move to node at required position */ 
    for (i = 1; i < pos && temp != NULL; i++) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
 
    if (temp == NULL) 
    { 
        printf("Invalid position!"); 
        return first; 
    } 
 
    prev->next = temp->next; 
 
    printf("Deleted item = %d", temp->data); 
 
    free(temp); 
 
    return first; 
} 
 
 
/* Display */ 
void display(NODE *first) 
{ 
    NODE *temp; 
 
    if (first == NULL) 
    { 
        printf("List is empty!"); 
        return; 
    } 
 
    temp = first; 
 
    printf("\nList: "); 
 
    while (temp != NULL) 
    { 
printf("%d -> ", temp->data); 
temp = temp->next; 
} 
printf("NULL"); 
} 