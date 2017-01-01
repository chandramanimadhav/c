/* A program to randomly select a node from a singly
   linked list */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>
struct node
{
    int key;
    struct node* next;
};
void printRandom(struct node *head)
{
    if (head == NULL)
       return;
    srand(time(NULL));
    int result = head->key;
    struct node *current = head;
    int n;
    for (n=1; current!=NULL; n++)
    {
        if (rand() % n == 0)
           result = current->key;
        current = current->next;
    }
    printf("Randomly selected key is %d\n", result);
}
struct node *newNode(int new_key)
{
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
    new_node->key  = new_key;
    new_node->next =  NULL;
 
    return new_node;
}
void push(struct node** head_ref, int new_key)
{
    struct node* new_node = new node;
    new_node->key  = new_key;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
int main()
{
    struct node *head = NULL;
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);
    printRandom(head);
    getch();
}
