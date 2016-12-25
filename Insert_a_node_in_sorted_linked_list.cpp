//A program of insert a node in sorted linked list
//Created linked list is also sorted
#include<stdio.h>
#include<stdlib.h>
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
void sortedInsert(struct node** head_ref, struct node* new_node)
{
    struct node* current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}
struct node *newNode(int new_data)
{
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next =  NULL;
    return new_node;
}
void printList(struct node *n)
{
	while(n != NULL)
	{
		printf("%d ",n->data);
		n = n->next;
	}
}
int main()
{
	struct node* head = NULL;
	struct node* new_node;
	push(&head, 6);
	push(&head, 5);
	push(&head, 3);
	push(&head, 2);
	push(&head, 0);
	puts("\ncreat Linked list is: ");
	printList(head);
    new_node = newNode(4);
    sortedInsert(&head, new_node);
    printf("\n Created Linked List\n");
    printList(head);
	getch();
}
