/* C Program to move last element to front in a given linked list */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void moveToFront(struct node **head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return;
    struct node *secLast = NULL;
    struct node *last = *head_ref;
    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }
    secLast->next = NULL;
    last->next = *head_ref;
    *head_ref = last;
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main()
{
    struct node *head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printf("\n Linked list before moving last to front: ");
    printList(head);
    moveToFront(&head);
    printf("\n Linked list after removing last to front: ");
    printList(head);
    getch();
}
