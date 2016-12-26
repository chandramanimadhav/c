//Remove duplicate node from linked list
#include<stdio.h>
#include<stdlib.h> 
#include<conio.h>
struct node 
{
  int data;
  struct node *next;
};
void push(struct node** head_ref,int new_data)
{
     struct node* new_node = (struct node*) malloc(sizeof(struct node));
     new_node->data = new_data;
     new_node->next =(*head_ref);
     (*head_ref) = new_node;
} 
void printList(struct node *n)
{
  while (n != NULL)
  {
     printf(" %d ", n->data);
     n = n->next;
  }
} 
void removeDuplicates(struct node *head)
{
  struct node *ptr1, *ptr2, *dup;
  ptr1 = head;
  while(ptr1 != NULL && ptr1->next != NULL)
  {
     ptr2 = ptr1;
     while(ptr2->next != NULL)
     {
       if(ptr1->data == ptr2->next->data)
       {
          dup = ptr2->next;
          ptr2->next = ptr2->next->next;
          free(dup);
       }
       else 
       {
          ptr2 = ptr2->next;
       }
     }
     ptr1 = ptr1->next;
  }
}
int main()
{
    struct node* head = NULL;
    push(&head, 5);
    push(&head, 8);
    push(&head, 3);
    push(&head, 5);
    push(&head, 8);
    push(&head, 4);
    push(&head, 2);
    push(&head, 4);
    printf("\nCreat Linked List is: ");
    printList(head);
    removeDuplicates(head);
    printf("\nLinked list after removing duplicates: ");
    printList(head);
    getchar();
}
