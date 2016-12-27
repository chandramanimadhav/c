#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void push(struct node** head_ref, int new_data);
struct node* sortedIntersect(struct node* a, struct node* b)
{
  struct node dummy;
  struct node* tail = &dummy;
  dummy.next = NULL;
  while (a != NULL && b != NULL)
  {
    if (a->data == b->data)
    {
       push((&tail->next), a->data);
       tail = tail->next;
       a = a->next;
       b = b->next;
    }
    else if (a->data < b->data)     
       a = a->next;
    else
       b = b->next;
  }
  return(dummy.next);
}
void push(struct node** head_ref, int new_data)
{  
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);    
    (*head_ref)    = new_node;
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
  struct node* a = NULL;
  struct node* b = NULL;
  struct node *intersect = NULL;
  push(&a, 6);
  push(&a, 5);
  push(&a, 4);
  push(&a, 3);
  push(&a, 2);
  push(&a, 1);                                   
  push(&b, 8);
  push(&b, 6);
  push(&b, 4);
  push(&b, 2);                                    
  printf("\nCreat a Linked List is: ");
  printList(a);
  printf("\nCreat b Linked List is: ");
  printList(b);                     
  intersect = sortedIntersect(a, b);
  printf("\n Linked list containing common items of a & b \n ");
  printList(intersect);           
  getchar();
}
