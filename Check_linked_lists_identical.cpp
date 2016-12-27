// An iterative C program to check if two linked lists are
// identical or not
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
bool areIdentical(struct node *a, struct node *b)
{
    while (a != NULL && b != NULL)
    {
        if (a->data != b->data)
            return false;
        a = a->next;
        b = b->next;
    }
    return (a == NULL && b == NULL);
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
int main()
{
    struct node *a = NULL;
    struct node *b = NULL;
    push(&a, 1);
    push(&a, 2);
    push(&a, 3);
    push(&b, 1);
    push(&b, 4);
    push(&b, 3);
    areIdentical(a, b)? printf("Identical\n"):
                        printf("Not identical\n");
    getch();
}
