//A program of delete linked list
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
void deleteList(struct node** n)
{
   struct node* current = *n;
   struct node* next;
   while (current != NULL) 
   {
       next = current->next;
       free(current);
       current = next;
   }
   *n = NULL;
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
	printf("\n Deleting linked list");
    deleteList(&head);  
    printf("\n Linked list deleted");
	getch();
}
