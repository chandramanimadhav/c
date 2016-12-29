//Detect and remove loop in a Linked List
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
void push(struct node** head_ref , int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void printList(struct node *node)
{
	while(node != NULL)
	{
		printf("%d ",node->data);
		node = node->next;
	}
}
void removeLoop(struct node *loop_node, struct node *head)
{
   struct node *ptr1;
   struct node *ptr2;
   ptr1 = head;
   while (1)
   {
     ptr2 = loop_node;
     while (ptr2->next != loop_node && ptr2->next != ptr1)
         ptr2 = ptr2->next;
     if (ptr2->next == ptr1)
        break;
     ptr1 = ptr1->next;
   }
   ptr2->next = NULL;
}
int detectAndRemoveLoop(struct node *list)
{
    struct node  *slow_p = list, *fast_p = list;
 
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
            removeLoop(slow_p, list);
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
	push(&head,4);
	push(&head,5);
	push(&head,2);
	printf("\nCreat Linked List is: ");
	printList(head);
	detectAndRemoveLoop(head);
    printf("\nLinked List after removing loop: ");
    printList(head);
    getch();
}
