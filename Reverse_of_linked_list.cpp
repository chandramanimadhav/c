//A program of reverse of linked list
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
};
void push(struct node** head_ref,int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref)    = new_node;
}
void printList(struct node *n)
{
	while(n != NULL)
	{
		printf("%d ",n->data);
		n = n->next;
	}
}
static void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
int main()
{
	struct node* head = NULL;
	push(&head, 2);
	push(&head, 3);
	push(&head, 5);
	push(&head, 9);
	push(&head, 0);
	puts("\n creat Linked list is: ");
	printList(head);
	reverse(&head);                      
    printf("\nReversed Linked list \n");
    printList(head); 
	getch();
}
