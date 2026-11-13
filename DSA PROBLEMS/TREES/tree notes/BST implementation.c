/*BINARY SEARCH TREE*/
/**
 * CREATE
 * INSERT
 * DELETE
 * SEARCH
 * MIN ELEMENT
 * MAX ELEMENT
 * PREDECESSOR
 * SUCCESSOR
 */
#include <stdio.h>
#include <stdlib.h>

 struct node {
     int data;
     struct node *left;
     struct node *right;
 };

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node with given data into the BST
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Search for a node with given data in the BST
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Find the minimum value node in the BST
struct node* findMin(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Find the maximum value node in the BST
struct node* findMax(struct node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}
// Find the predecessor of a given node in the BST
struct node* findPredecessor(struct node* root, int data) {
    struct node* current = search(root, data);
    if (current == NULL) {
        return NULL; // Node not found
    }
    if (current->left != NULL) {
        return findMax(current->left); // Predecessor is the maximum in the left subtree
    }
    struct node* predecessor = NULL;
    struct node* ancestor = root;
    while (ancestor != current) {
        if (current->data > ancestor->data) {
            predecessor = ancestor; // Update predecessor
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}

// Find the successor of a given node in the BST
struct node* findSuccessor(struct node* root, int data) {
    struct node* current = search(root, data);
    if (current == NULL) {
        return NULL; // Node not found
    }
    if (current->right != NULL) {
        return findMin(current->right); // Successor is the minimum in the right subtree
    }
    struct node* successor = NULL;
    struct node* ancestor = root;
    while (ancestor != current) {
        if (current->data < ancestor->data) {
            successor = ancestor; // Update successor
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}

// Delete a node with given data from the BST
struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}