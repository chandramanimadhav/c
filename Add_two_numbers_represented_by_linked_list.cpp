//A program of add two Linked List
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node* next;
};
struct node *newNode(int data)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
struct node* addTwoLists (struct node* first, struct node* second)
{
    struct node* res = NULL; 
    struct node *temp, *prev = NULL;
    int carry = 0, sum;
 
    while (first != NULL || second != NULL) 
    {
        sum = carry + (first? first->data: 0) + (second? second->data: 0);
        carry = (sum >= 10)? 1 : 0;
        sum = sum % 10;
        temp = newNode(sum);
        if(res == NULL)
            res = temp;
        else 
            prev->next = temp;
        prev  = temp;
        if (first) first = first->next;
        if (second) second = second->next;
    }
 
    if (carry > 0)
      temp->next = newNode(carry);
    return res;
}
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
int main(void)
{
    struct node* res = NULL;
    struct node* first = NULL;
    struct node* second = NULL;
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    printf("First List is: ");
    printList(first);
    push(&second, 4);
    push(&second, 8);
    printf("Second List is: ");
    printList(second);
    res = addTwoLists(first, second);
    printf("Resultant list is: ");
    printList(res);
    getch();
}
