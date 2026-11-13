/*
Traversal of Binary Tree (Infix , postfix , prefix)
*/
#include <stdio.h>
#include <stdlib.h>
/*Infix Traversal of Binary Tree*/

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter data for the node: (-1 for no value) ");
    scanf("%d", &x);
    newNode->data = x;

    if (newNode->data == -1) {
        free(newNode);
        return NULL;
    }
    //recursively create left and right children
    printf("Enter left child of %d\n", newNode->data);
    newNode->left = createNode();

    printf("Enter right child of %d\n", newNode->data);
    newNode->right = createNode();

    return newNode;
}

void infix(struct node *root)
{
    if (root == NULL)
        return;
    infix(root->left);
    printf("%d ", root->data);
    infix(root->right);
}

//POSTFIX Traversal of Binary Tree
void postfix(struct node *root)
{
    if (root == NULL)
        return;
    postfix(root->left);
    postfix(root->right);
    printf("%d ", root->data);
}

//PREFIX Traversal of Binary Tree
void prefix(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    prefix(root->left);
    prefix(root->right);
}

int main() {
    struct node *root ;
    root = createNode(1);
    printf("Infix Traversal of Binary Tree: ");
    infix(root);
    printf("\nPostfix Traversal of Binary Tree: ");
    postfix(root);
    printf("\nPrefix Traversal of Binary Tree: ");
    prefix(root);
}

