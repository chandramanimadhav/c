//A program to populate arbit pointers to next higher value
// using merge sort
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next, *arbit;
};
struct node* SortedMerge(struct node* a, struct node* b);
void FrontBackSplit(struct node* source,
                    struct node** frontRef, struct node** backRef);
void MergeSort(struct node** headRef)
{
    struct node* head = *headRef;
    struct node* a, *b;
    if ((head == NULL) || (head->arbit == NULL))
        return;
    FrontBackSplit(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *headRef = SortedMerge(a, b);
}
struct node* SortedMerge(struct node* a, struct node* b)
{
    struct node* result = NULL;
    if (a == NULL)
        return (b);
    else if (b==NULL)
        return (a);
    if (a->data <= b->data)
    {
        result = a;
        result->arbit = SortedMerge(a->arbit, b);
    }
    else
    {
        result = b;
        result->arbit = SortedMerge(a, b->arbit);
    }
    return (result);
}
void FrontBackSplit(struct node* source,
                    struct node** frontRef, struct node** backRef)
{
    struct node* fast, *slow;
    if (source==NULL || source->arbit==NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }
    slow = source,  fast = source->arbit;
    while (fast != NULL)
    {
        fast = fast->arbit;
        if (fast != NULL)
        {
            slow = slow->arbit;
            fast = fast->arbit;
        }
    }
    *frontRef = source;
    *backRef = slow->arbit;
    slow->arbit = NULL;
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    new_node->arbit = NULL;
    (*head_ref)    = new_node;
}
void printListafter(struct node *node, struct node *anode)
{
    printf("Traversal using Next Pointer\n");
    while (node!=NULL)
    {
        printf("%d, ", node->data);
        node = node->next;
    }
 
    printf("\nTraversal using Arbit Pointer\n");
    while (anode!=NULL)
    {
        printf("%d, ", anode->data);
        anode = anode->arbit;
    }
}
struct node* populateArbit(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        temp->arbit = temp->next;
        temp = temp->next;
    }
    MergeSort(&head);
    return head;
}
int main()
{
    struct node* head = NULL;
    push(&head, 3);
    push(&head, 2);
    push(&head, 10);
    push(&head, 5);
    struct node *ahead = populateArbit(head);
    printf("\nResult Linked List is: \n");
    printListafter(head, ahead);
    getchar();
}
