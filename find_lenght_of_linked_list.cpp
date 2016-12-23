//A program of find length of linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
       int data;
       struct node *next;
};

void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
     new_node->data=new_data;
     new_node->next=(*head_ref);
     (*head_ref) = new_node;
}

void printList(struct node *node)
{
     while(node !=NULL)
     {
                printf("%d",node->data);
                node = node->next;
     }
}

int getCount(struct node* head)//length of linked list
{
    if (head == NULL)
        return 0;
    return 1 + getCount(head->next);
}

int main()
{
    struct node* head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    push(&head,8);
    puts("created linked list is: ");
    printList(head);
    
     printf("\ncount of nodes is %d", getCount(head));
    getch();
}
