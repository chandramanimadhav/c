// A program to find n'th node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node
{
    int data;
    struct node* next;
};
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
int GetNth(struct node* head, int index)
{
    struct node* current = head;
    int count = 0; 
    while (current != NULL)
    {
       if (count == index)
          return(current->data);
       count++;
       current = current->next;
    }
    assert(0);              
}
int main()
{
    struct node* head = NULL;
    push(&head, 10);
    push(&head, 32);
    push(&head, 14);
    push(&head, 9);
    push(&head, 18);  
    printf("Element at index 2 is %d", GetNth(head, 2));  
    getchar();
}
