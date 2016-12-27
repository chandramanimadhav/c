#include<stdio.h>
#include<conio.h>
#include<assert.h>
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
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
/*void printList(struct node *node)
{
	while(node ! ==NULL)
	{
		printf("%d ",n->data);
		n=n->next;
	}
}*/
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
} 
void MoveNode(struct node** destRef, struct node** sourceRef) 
{
  struct node* newNode = *sourceRef; 
  assert(newNode != NULL);
  *sourceRef = newNode->next;
  newNode->next = *destRef; 
  *destRef = newNode; 
}
void AlternatingSplit(struct node* source, struct node** aRef, 
                            struct node** bRef) 
{
  struct node* b = NULL;
  struct node* a = NULL;
  struct node* current = source;
  while (current != NULL) 
  {
    MoveNode(&a, &current); 
    if (current != NULL) 
    {
       MoveNode(&b, &current); 
    }
  }
  *aRef = a;
  *bRef = b;
}
int main()
{
	struct node* head = NULL;
	struct node*    a = NULL;
	struct node*    b = NULL;
	push(&head,1);
	push(&head,2);
	push(&head,1);
	push(&head,2);
	push(&head,1);
	printf("\n Original linked List:  ");
  printList(head); 
  AlternatingSplit(head, &a, &b);
  printf("\n Resultant Linked List a: ");
  printList(a); 
  printf("\n Resultant Linked List b: ");
  printList(b); 
  getchar();
  return 0;
}
