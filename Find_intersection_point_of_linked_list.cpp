#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
  int data;
  struct node* next;
};
int getCount(struct node* head);
int _getIntesectionNode(int d, struct node* head1, struct node* head2);
int getIntesectionNode(struct node* head1, struct node* head2)
{
  int c1 = getCount(head1);
  int c2 = getCount(head2);
  int d;
  if(c1 > c2)
  {
    d = c1 - c2;
    return _getIntesectionNode(d, head1, head2);
  }
  else
  {
    d = c2 - c1;
    return _getIntesectionNode(d, head2, head1);
  }
}
int _getIntesectionNode(int d, struct node* head1, struct node* head2)
{
  int i;
  struct node* current1 = head1;
  struct node* current2 = head2;
  for(i = 0; i < d; i++)
  {
    if(current1 == NULL)
    {  
		return -1;
    }
    current1 = current1->next;
  }
  while(current1 !=  NULL && current2 != NULL)
  {
    if(current1 == current2)
      return current1->data;
    current1= current1->next;
    current2= current2->next;
  }
  return -1;
}
int getCount(struct node* head)
{
  struct node* current = head;
  int count = 0;
 
  while (current != NULL)
  {
    count++;
    current = current->next;
  }
  return count;
}
 void printList(struct node *head)
 {
      struct node *temp = head;
      while (temp != NULL)
      {
            printf("%d ",temp->data);
            temp = temp->next;
      }
 }
int main()
{
  struct node* newNode;
  struct node* head1 =
            (struct node*) malloc(sizeof(struct node));
  head1->data  = 10;
  struct node* head2 =
            (struct node*) malloc(sizeof(struct node));
  head2->data  = 3;
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 6;
  head2->next = newNode;
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 8;
  head2->next->next = newNode;
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 8;
  head1->next = newNode;
  head2->next->next->next  = newNode;
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 30;
  head1->next->next= newNode;
  head1->next->next->next = NULL;
  printList(head1);
  printf("\n");
  printList(head2);
  printf("\n The node of intersection is %d \n",
          getIntesectionNode(head1, head2));
  getchar();
}
