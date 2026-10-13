  #include <stdio.h>
#include <stdlib.h>

// Implementation of list node in a singly linked list
typedef struct Node {
    int val;            // Data part of the node
    struct Node* next;  // Pointer to the next node
} Node;

// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

// Insertion at head
void insertAtHead(Node** head, int val) {
    Node* n = createNode(val);
    n->next = *head;  // Point new node towards the current head
    *head = n;        // Update head to the new node
}

// Insertion at tail
void insertAtTail(Node** head, int val) {
    Node* new_node = createNode(val);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Insertion at any position (k)
void insertAtPosition(Node** head, int val, int pos) {
    if (pos == 0) {
        insertAtHead(head, val);
        return;
    }
    
    Node* temp = *head;
    int cur_pos = 0;
    
    // Traversing till (pos - 1)th position
    while (temp != NULL && cur_pos < pos - 1) {
        temp = temp->next;
        cur_pos++;
    }
    
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(new_node);
        return;
    }
    
    Node* new_node = createNode(val);
    new_node->next = temp->next;
    temp->next = new_node;
}

// Update at position k
void updateAtPosition(Node** head, int k, int val) {
    Node* temp = *head;
    int cur_pos = 0;
    while (temp != NULL && cur_pos != k) {
        temp = temp->next;
        cur_pos++;
    }
    if (temp != NULL) {
        temp->val = val; // Update the value at position k
    } else {
        printf("Position out of bounds\n");
    }
}

// Deletion at head
void deleteAtHead(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete at tail
void deleteAtTail(Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* sec_last = *head;
    while (sec_last->next->next != NULL) {
        sec_last = sec_last->next;
    }
    Node* temp = sec_last->next;
    sec_last->next = NULL;
    free(temp);
}

// Delete at any position k
void deleteAtPosition(Node** head, int pos) {
    if (*head == NULL) return;
    if (pos == 0) {
        deleteAtHead(head);
        return;
    }
    int cur_pos = 0;
    Node* prev = *head;
    while (prev != NULL && cur_pos < pos - 1) {
        prev = prev->next;
        cur_pos++;
    }
    if (prev == NULL || prev->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    Node* temp = prev->next;
    prev->next = temp->next;
    free(temp);
}

// Print list
void display(Node* head) {
    Node* temp = head; // Temp pointer to traverse the list
    while (temp != NULL) {
        printf("%d->", temp->val);
        temp = temp->next; // Move to the next node
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    
    insertAtHead(&head, 5);
    insertAtHead(&head, 2);
    insertAtTail(&head, 10);
    
    printf("Linked List: ");
    display(head);

    return 0;
}