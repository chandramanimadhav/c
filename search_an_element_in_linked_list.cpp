// Iterative C program to search an element in linked list
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int key;
    struct node* next;
};
void push(struct node** head_ref, int new_key)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->key  = new_key;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
bool search(struct node* head, int x)
{
    struct node* current = head;
    while (current != NULL)
    {
        if (current->key == x)
            return true;
        current = current->next;
    }
    return false;
}
int main()
{
    struct node* head = NULL;
    int x = 20;
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    push(&head, 20); 
    search(head, 20)? printf("Yes\n") : printf("No\n");
    getch();
}
