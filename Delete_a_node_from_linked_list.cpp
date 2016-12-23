// A C program for delete of a linked list
#include<stdio.h>
#include<stdlib.h> 
#include<conio.h>
struct node 
{
  int data;
  struct node *next;
};
void deleteNode(struct node **head_ref, int key)
{
    struct node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);   
        return;
    }
    while (temp != NULL && temp->data != key)
    {   temp = temp->next;
    }
        prev = temp;
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}
void printList(struct node *n)
{
  while (n != NULL)
  {
     printf(" %d ", n->data);
     n = n->next;
  }
} 
int main()
{
  struct node* head = NULL;
  struct node* second = NULL;
  struct node* third = NULL;
  struct node* fourth = NULL; 
  head  = (struct node*)malloc(sizeof(struct node)); 
  second = (struct node*)malloc(sizeof(struct node));
  third  = (struct node*)malloc(sizeof(struct node));
  fourth = (struct node*)malloc(sizeof(struct node));
  head->data = 1; 
  head->next = second;  
  
  second->data = 2; 
  second->next = third;  
  
  third->data = 3; 
  third->next = fourth;
  
  fourth->data = 4;
  fourth->next = NULL;
   
  printList(head);
  deleteNode(&head, 1);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
  getch();
}
