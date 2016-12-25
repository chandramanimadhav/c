/* A program to merge two sorted linked lists */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<conio.h>
struct node
{
    int data;
    struct node* next;
};
struct node* SortedMerge(struct node* a, struct node* b) 
{
  struct node* result = NULL;
  if (a == NULL) 
     return(b);
  else if (b==NULL) 
     return(a);
  if (a->data <= b->data) 
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}
void MoveNode(struct node** destRef, struct node** sourceRef)
{
    struct node* newNode = *sourceRef;
    assert(newNode != NULL);
    *sourceRef = newNode->next;
    newNode->next = *destRef;
    *destRef = newNode;
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
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main()
{
    struct node* res = NULL;
    struct node* a = NULL;
    struct node* b = NULL;
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
    printf("\ncreat linked list a is: ");
    printList(a);
    printf("\ncreat linked list b is: ");
    printList(b);
    res = SortedMerge(a, b);
    printf("\nMerged Linked List is: ");
    printList(res);
    getch();
}
