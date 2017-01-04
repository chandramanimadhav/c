/*A Program to split a circular linked list into two halves */
#include<stdio.h> 
#include<stdlib.h> 
struct node
{
  int data;
  struct node *next;
}; 
void splitList(struct node *head, struct node **head1_ref, 
                                            struct node **head2_ref)
{
  struct node *slow_ptr = head;
  struct node *fast_ptr = head; 
 
  if(head == NULL)
    return;
  while(fast_ptr->next != head &&
         fast_ptr->next->next != head) 
  {
     fast_ptr = fast_ptr->next->next;
     slow_ptr = slow_ptr->next;
  }  
  if(fast_ptr->next->next == head)
    fast_ptr = fast_ptr->next;      
  *head1_ref = head;    
  if(head->next != head)
    *head2_ref = slow_ptr->next; 
  fast_ptr->next = slow_ptr->next; 
  slow_ptr->next = head;       
}
void push(struct node **head_ref, int data)
{
  struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
  struct node *temp = *head_ref; 
  ptr1->data = data;  
  ptr1->next = *head_ref; 
  if(*head_ref != NULL)
  {
    while(temp->next != *head_ref)
      temp = temp->next;        
    temp->next = ptr1; 
  }
  else
     ptr1->next = ptr1;
 
  *head_ref = ptr1;     
} 
void printList(struct node *head)
{
  struct node *temp = head; 
  if(head != NULL)
  {
    printf("\n");
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
  }
}
int main()
{
  int list_size, i; 
  struct node *head = NULL;
  struct node *head1 = NULL;
  struct node *head2 = NULL;  
  push(&head, 12); 
  push(&head, 56);   
  push(&head, 2);   
  push(&head, 11);   
  printf("Original Circular Linked List");
  printList(head);    
  splitList(head, &head1, &head2);
  printf("\nFirst Circular Linked List");
  printList(head1);  
  printf("\nSecond Circular Linked List");
  printList(head2);  
  getchar();
} 
