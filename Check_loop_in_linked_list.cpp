// Check loop is present in linked list
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
	new_node->data = new_data;
	new_node->next = *head_ref;
 	*head_ref = new_node;
}
void printList(struct node *n)
{
	while(n != NULL)
	{
		printf("%d ",n->data);
		n = n->next;
	}
}
int detectloop(struct node *list)
{
    struct node  *slow_p = list, *fast_p = list;
  
    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
           printf("\nFound Loop");
           return 1;
        }
    }
    return 0;
}
int main()
{
	struct node* head = NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,5);
	push(&head,0);
	push(&head,9);
	printf("\ncreat Linked List is: ");
	printList(head);
    head->next->next->next->next->next->next = head;
    detectloop(head);
	getch();
}
