// A program to print reverse of input Linked list
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
     new_node->next = (*head);
     (*head) = new_node;
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
void printReverse(struct node* head)
{  
    if (head == NULL)
       return;
    printReverse(head->next);
    printf("%d  ", head->data);
}
int main()
{
    struct node* head = NULL;
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    printf("\ncreat Linked List is: ");
    printList(head);
    printf("\ncreat recursive Linked List is: ");
    printReverse(head);
    getch();
}
