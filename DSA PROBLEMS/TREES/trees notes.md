# Trees 

## Implementation in C 
```c 
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define EMPTY '-'

//structure to represent to Arrays Tree
typedef struct {
    char nodes[MAX_SIZE];
}ArrayTree;

//initialize with empty nodes 
void initTree(ArrayTree* tree){
    for (int i = 0; i < n ; i ++){
        tree-> nodes[i] = EMPTY;
    }
}

//set root node
void setRoot (ArrayTree* tree , char key){
    tree-> nodes[0] = key;
}
// Set left child of node at parentIndex
void setLeft(ArrayTree* tree, char key, int parentIndex) {
    int leftIndex = 2 * parentIndex + 1;
    if (parentIndex >= MAX_SIZE || tree->nodes[parentIndex] == EMPTY) {
        printf("Error: Parent at index %d does not exist.\n", parentIndex);
        return;
    }
    if (leftIndex < MAX_SIZE) {
        tree->nodes[leftIndex] = key;
    } else {
        printf("Error: Tree capacity exceeded!\n");
    }
}

// Set right child of node at parentIndex
void setRight(ArrayTree* tree, char key, int parentIndex) {
    int rightIndex = 2 * parentIndex + 2;
    if (parentIndex >= MAX_SIZE || tree->nodes[parentIndex] == EMPTY) {
        printf("Error: Parent at index %d does not exist.\n", parentIndex);
        return;
    }
    if (rightIndex < MAX_SIZE) {
        tree->nodes[rightIndex] = key;
    } else {
        printf("Error: Tree capacity exceeded!\n");
    }
}

// Print array storage
void printArrayTree(ArrayTree* tree) {
    printf("Array Tree Representation: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (tree->nodes[i] != EMPTY) {
            printf("%c ", tree->nodes[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int main() {
    ArrayTree tree;
    initTree(&tree);

    /* Constructing Tree:
             A (index 0)
            / \
     (1)   B   C (2)
          /
     (3) D
    */

    setRoot(&tree, 'A');
    setLeft(&tree, 'B', 0);  // Index 1
    setRight(&tree, 'C', 0); // Index 2
    setLeft(&tree, 'D', 1);  // Index 3

    printArrayTree(&tree);   // Output: A B C D - - - - - -

    return 0;
}

```

## Implementation through Linked List
```c
#include <stdio.h>
#include <stdlib.h>

// Define Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Utility function to create a new tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder Traversal (Left -> Root -> Right)
void inorderTraversal(Node* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Free allocated memory recursively
void freeTree(Node* root) {
    if (root == NULL) return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    /* Constructing Tree:
              10
             /  \
           20    30
          /
        40
    */

    Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);

    printf("Inorder Traversal: ");
    inorderTraversal(root); // Output: 40 20 10 30
    printf("\n");

    // Always free dynamic memory in C
    freeTree(root);

    return 0;
}
```

## STL Notations in CPP

### A. Standard Heap Algorithms
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main (){

    std :: vector <int > tree = {10, 20, 5 , 30 15};

    //1. 
}
```