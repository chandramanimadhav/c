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
     struct node *new_node =(struct node*) malloc(sizeof(struct node));
     new_node->data = new_data;
     new_node->next = (*head_ref);
     (*head_ref) = new_node;
}
void printList(struct node *head)
{
     struct node *temp = head;
     while (temp != NULL)
     {
           printf("%d ",temp->data);
           temp = temp->next;
     }
}
void deleteNode(struct node *node_ptr)
{
     struct node *temp = node_ptr->next;
     node_ptr->data = temp->data;
     node_ptr->next = temp->next;
     free(temp);
}
int main()
{
    struct node* head = NULL;
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    printf("\nBefore deleting linked list is: ");
    printList(head);
    deleteNode(head);
    printf("\nAfter deleting linked list is: ");
    printList(head);
    getch();
}
