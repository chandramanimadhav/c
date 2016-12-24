// swap two node in linked list with the help of delete and insert
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void deleteNode(struct node **head_ref, int position)
{
   if (*head_ref == NULL)
      return;
 
   struct node* temp = *head_ref;
    if (position == 0)
    {
        *head_ref = temp->next;  
        free(temp);              
        return;
    }
    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;
    if (temp == NULL || temp->next == NULL)
         return;
    struct node *next = temp->next->next;
 
    free(temp->next);  
 
    temp->next = next;  
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
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
int main()
{
    struct node* head = NULL;
    int x=2 , y=1;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);
    puts("Befor swap of linked list:");
    printList(head);
    deleteNode(&head,1);
    deleteNode(&head,2);
  insertAfter(head,1);
    printf("\n swap 2 and 1 each other.");
  printf("\n After swap.");
   insertAfter(head->next->next,2);
   printf("\n creat linked list: ");
   printList(head);
    getch ();
}
