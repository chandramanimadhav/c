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
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	printf("\nBefore deleting linked list is: ");
	printList(head);
	printf("Enter index to be delete : ");
	scanf("%d", &index);
    deleteNode(&head, index);
    getch();
}
