/*
Write a c programm :

Create a binary search tree by asking 5 numbers from users one at a time.
Print this tree in in-order, pre-order and post-order.
Give user option to insert a number in the given BST.
Again print in in-order, pre-order and post-order.
Ask a number to user to search in a tree.
Ask a number from user to delete this number if it exist in a tree otherwise say not found.
Again print in in-order, pre-order and post-order.


Hint:

Use switch statement.

*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
     int data;
     struct node* left;
     struct node* right;
};
struct node* newNode(int data)
{
     struct node* node = (struct node*)
                                  malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
 
     return(node);
}
void printPreorder(struct node* node)
{
     if (node == NULL)
          return;
     printf("%d ", node->data);  
     printPreorder(node->left);  
     printPreorder(node->right);
}  
void printPostorder(struct node* node)
{
     if (node == NULL)
        return;
     printPostorder(node->left);
     printPostorder(node->right);
     printf("%d ", node->data);
}
void printInorder(struct node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data);  
     printInorder(node->right);
}  
int main()
{
     struct node *root  = NULL;

     root                  = newNode(2);
     root->left            = newNode(3);
     root->right           = newNode(4);
    root->left->left       = newNode(5); 
     printf("\nPreorder traversal of binary tree is \n");
     printPreorder(root);
      printf("\nInorder traversal of binary tree is \n");
     printInorder(root);  
     printf("\nPostorder traversal of binary tree is \n");
     printPostorder(root);
     getchar();
}
