// A C program for add front , insert and end of a linked list
#include<stdio.h>
#include<stdlib.h> 
#include<conio.h>
struct node 
{
  int data;
  struct node *next;
};
void push(struct node** head_ref,int new_data)//Add front of linked list
{
     struct node* new_node = (struct node*) malloc(sizeof(struct node));
     new_node->data = new_data;
     new_node->next =(*head_ref);
     (*head_ref) = new_node;
} 
void insertAfter(struct node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
      printf("the given previous node cannot be NULL");
      return;
    }
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void append(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    struct node *last = *head_ref;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
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
  head  = (struct node*)malloc(sizeof(struct node)); 
  second = (struct node*)malloc(sizeof(struct node));
  third  = (struct node*)malloc(sizeof(struct node));
  head->data = 1; 
  head->next = second;  
  
  second->data = 2; 
  second->next = third;  
  
  third->data = 3; 
  third->next = NULL;
   
  printList(head);
  
  printf("\n Add 6 at the front of linked list.");
  push(&head,6);
  printf("\n creat Linked list is: ");
  printList(head);
  printf("\n Add 0 after 1 of linked list.");
  insertAfter(head->next,0);
   printf("\n creat Linked list is: ");
  printList(head);
  printf("\n Add 4 end of linked list."); 
  append(&head,4);
  printf("\n Created Linked list is: ");
  printList(head);
  
  getch();
}
