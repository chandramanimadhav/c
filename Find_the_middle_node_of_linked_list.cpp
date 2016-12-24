//find middle node of linked list
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void printMiddle(struct node *head)
{
    int count = 0;
    struct node *mid = head;
 
    while (head != NULL)
    {
        if (count & 1)
            mid = mid->next;
 
        ++count;
        head = head->next;
    }
    if (mid != NULL)
        printf("The middle element is [%d]\n\n", mid->data);
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}
int main()
{
    struct node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);
    puts("\ncreat linked list:");
    printList(head);
    printf("\n");
    printMiddle(head);
    getch ();
}
