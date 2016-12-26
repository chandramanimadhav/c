 // Delete a node in Linked list
 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>
 #include<assert.h>
 struct node
 {
        int data;
        struct node *next;
 };
 void push(struct node** head_ref, int new_data)
 {
      struct node *new_node =(struct node*) malloc(sizeof(struct node));
      new_node->data = new_data;
      new_node->next = (*head_ref);
      (*head_ref) = new_node;
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
 int GetNth(struct node* head, int index)
{
    struct node* current = head;
    int count = 0;
    while (current != NULL)
    {
       if (count == index)
          return(current->data);
       count++;
       current = current->next;
    }
    assert(0);              
}
void removeDuplicates(struct node* head)
{
    struct node* current = head;
    struct node* next_next; 
    if (current == NULL) 
       return; 
    while (current->next != NULL) 
    {
       if (current->data == current->next->data) 
       {              
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;  
       }
       else
       {
          current = current->next; 
       }
    }
}
void printReverse(struct node* head)
{  
    if (head == NULL)
       return;
    printReverse(head->next);
    printf("%d  ", head->data);
}
void deleteNode(struct node **head_ptr, int index) {
    struct node *temp = (*head_ptr);
    struct node *prev_node, *next_node, *current_node;
    prev_node = NULL;
    next_node = NULL;
    current_node = NULL;
    int count = 0;
    while (temp != NULL) {
        current_node = temp;
        next_node = temp->next;
        if(count == index) {
            break;
        } else {
            prev_node = temp;
            next_node = NULL;
            current_node = NULL;
            count++;
        }
        temp = temp->next;
    }
    if (current_node != NULL) {
        if (prev_node != NULL) {
            prev_node->next = next_node;
        } else {
            (*head_ptr) = next_node;
        }
        free(current_node);
    } else {
        printf("\nIndex out ot boundary.");
    }
}
int main() {
	struct node* head = NULL;
	int index;
	int i;
	push(&head,16);
	push(&head,15);
	push(&head,15);
	push(&head,14);
	push(&head,13);
	push(&head,13);
	push(&head,12);
	push(&head,12);
	push(&head,11);
	printf("\nCreat linked list is: ");
	printList(head);
	printf("\nEnter 1 for deleting the node.");
	printf("\nEnter 2 for remove duplicate node in Linked List.");
	printf("\nEnter 3 for revers the input Linked List.");
	printf("\nEnter the value of i: ");
	scanf("%d",&i); 
	switch(i)
	{
		case (1):
	printf("\nEnter index to be delete : ");
	scanf("%d", &index);
    deleteNode(&head, index);
    printf("\nAfter deleting linked list is: ");
    printList(head);
    break;
    case (2):
    removeDuplicates(head);
    printf("\nAfter removing duplicate node in linked list is: ");
    printList(head);
    break;
    case (3):
    printf("\ncreat recursive Linked List is: ");
    printReverse(head);
    break;
    default:
    	printf("\nYou choose default.");
	}
    getch();
}
