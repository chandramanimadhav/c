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
bool isPalindromeUtil(struct node **left, struct  node *right)
{
   if (right == NULL)
      return true;
   bool isp = isPalindromeUtil(left, right->next);
   if (isp == false)
      return false;
   bool isp1 = (right->data == (*left)->data);
   *left = (*left)->next;
   return isp1;
}
bool isPalindrome(struct node *head)
{
   isPalindromeUtil(&head, head);
}
int main()
 {
     struct node* head = NULL;
     push(&head,4);
     push(&head,1);
     push(&head,2);
     push(&head,1);
     push(&head,4);
     printf("\nBefore deleting linked list is: ");
     printList(head); 
	  isPalindrome(head)? printf("\nIs Palindrome"):
                           printf("\nNot Palindrome");   
     getch();
 }
