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
 void deleteNode(struct node *node_ptr,int index)
 {
      struct node *temp = node_ptr->next;
      node_ptr->data = temp->data;
      node_ptr->next = temp->next;
      free(temp);
 }
 int main()
 {
     struct node* head = NULL;
     int index;
     push(&head,4);
     push(&head,3);
     push(&head,2);
     push(&head,1);
     printf("\nBefore deleting linked list is: ");
     printList(head); 
     for(index = 0; index <= 3; index++)
     {
     	if( index==2)
     	{
     		current =index != NULL;
     		current = curent->next;
			deleteNode(head);
        	printf("\nDelete the index: ");
   	    	printList(head);
     	}
     }     
     getch();
 }
