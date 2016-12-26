#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
       int data;
       struct node* next;
};
void push(struct node** head, int new_data)
{
     struct node* new_node = (struct node*) malloc(sizeof(struct node));
     new_node->data = new_data;
     new_node->next =(*head);
     (*head) = new_node;
}
void printList(struct node *node)
{
     while(node != NULL)
     {
                printf("%d ",node->data);
                node = node->next;
     }
}
void removeDuplicates(struct node* head)
{
    struct node* current = head;
    struct node* next_next; 
    if (current == NULL) 
       return; 
    while (current->next != NULL) 
    {
       if (current->data == current->next->data) 
       {              
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;  
       }
       else
       {
          current = current->next; 
       }
    }
}
int main()
{
    struct node* head = NULL;
    push(&head,8);
    push(&head,12);
    push(&head,12);
    push(&head,13);
    push(&head,13);
    push(&head,20);
    push(&head,20);
    push(&head,30);
    printf("\ncreat Linked List is: ");
    printList(head);
    removeDuplicates(head);
    printf("\nLinked List after duplicate remove: ");
    printList(head);
    getch();
}
