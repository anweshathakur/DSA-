#include <stdio.h>
#include <stdlib.h>

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

int main() {
    struct node *root ;
    root = createNode(1);
}