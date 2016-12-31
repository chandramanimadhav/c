// A program to remove intermediate points in a linked list 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int x, y;
    struct node *next;
};
void push(struct node ** head_ref, int x,int y)
{
    struct node* new_node = 
           (struct node*) malloc(sizeof(struct node));
    new_node->x  = x;
    new_node->y  = y;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
}
void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("(%d,%d)-> ", temp->x,temp->y);
        temp = temp->next;
    }
    printf("\n");
}
void deleteNode(struct node *head, struct node *Next)
{
    head->next = Next->next;
    Next->next = NULL;
    free(Next);
}
struct node* deleteMiddle(struct node *head)
{
    if (head==NULL || head->next ==NULL || head->next->next==NULL)
        return head;
    struct node* Next = head->next;
    struct node *NextNext = Next->next ;
    if (head->x == Next->x)
    {
        while (NextNext !=NULL && Next->x==NextNext->x)
        {
            deleteNode(head, Next);
            Next = NextNext;
            NextNext = NextNext->next;
        }
    }
    else if (head->y==Next->y)
    {
        while (NextNext !=NULL && Next->y==NextNext->y)
        {
            deleteNode(head, Next);
            Next = NextNext;
            NextNext = NextNext->next;
        }
    }
    else  
    {
        puts("Given linked list is not valid");
        return NULL;
    }
    deleteMiddle(head->next);
    return head;
}
int main()
{
    struct node *head = NULL;
    push(&head, 40,5);
    push(&head, 20,5);
    push(&head, 10,5);
    push(&head, 10,8);
    push(&head, 10,10);
    push(&head, 3,10);
    push(&head, 1,10);
    push(&head, 0,10);
    printf("Given Linked List: \n");
    printList(head);
    if (deleteMiddle(head) != NULL);
    {
        printf("Modified Linked List: \n");
        printList(head);
    }
    getch();
}
