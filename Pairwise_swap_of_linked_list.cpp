#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
       int data;
       struct node *next;
};
void push(struct node** head_ref, int new_data)
{
     struct node* new_node = (struct node*) malloc(sizeof(struct node));
     new_node->data = new_data;
     new_node->next = (*head_ref);
     (*head_ref) = new_node;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void pairWiseSwap(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        swap(&temp->data, &temp->next->data);
        temp = temp->next->next;
    }
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
    struct node *head = NULL;
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printf("Linked list before calling  pairWiseSwap()\n");
    printList(head);
    pairWiseSwap(head);
    printf("\nLinked list after calling  pairWiseSwap()\n");
    printList(head);
    getch();
}
