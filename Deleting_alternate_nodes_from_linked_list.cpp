// A program to remove alternate nodes of a linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void deleteAlt(struct node *head)
{
    if (head == NULL)
        return;
    struct node *node = head->next;
    if (node == NULL)
        return;
    head->next = node->next;
    free(node);
    deleteAlt(head->next);
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
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main()
{
    struct node* head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printf("\nList before calling deleteAlt: ");
    printList(head);
    deleteAlt(head);
    printf("\nList after calling deleteAlt: ");
    printList(head);
    getch();
}
