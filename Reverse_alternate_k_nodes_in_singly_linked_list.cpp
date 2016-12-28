#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node *kAltReverse(struct node *head, int k)
{
    struct node* current = head;
    struct node* next;
    struct node* prev = NULL;
    int count = 0;   
    while (current != NULL && count < k)
    {
       next  = current->next;
       current->next = prev;
       prev = current;
       current = next;
       count++;
    }
    if(head != NULL)
      head->next = current;   
    count = 0;
    while(count < k-1 && current != NULL )
    {
      current = current->next;
      count++;
    }
    if(current !=  NULL)
       current->next = kAltReverse(current->next, k); 
    return prev;
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
    int count = 0;
    while(node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
        count++;
    }
}    
int main(void)
{
    struct node* head = NULL;
    for(int i = 20; i > 0; i--)
      push(&head, i);
     printf("\n Given linked list \n");
     printList(head);
     head = kAltReverse(head, 3);
     printf("\n Modified Linked list \n");
     printList(head);
     getchar();
}
