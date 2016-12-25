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
    int i;
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    printf("\nBefore deleting linked list is: ");
    printList(head);
    printf("\nEnter the value node between 0 to 3: ");
    scanf("%d",&i);
    switch(i)
    {
             case 0:
                deleteNode(head);
                printf("\nAfter deleting linked list is: ");
                printList(head);
                break;
             case 1:
                deleteNode(head->next);
                printf("\nAfter deleting linked list is: ");
                printList(head);
                break;
             case 2:
                deleteNode(head->next->next);
                printf("\nAfter deleting linked list is: ");
                printList(head);
                break;
             case 3:
                deleteNode(head->next->next->next);
                printf("\nAfter deleting linked list is: ");
                printList(head);
                break;
             default:
                printf("\nYou choose default.");
     }        
    getch();
}
