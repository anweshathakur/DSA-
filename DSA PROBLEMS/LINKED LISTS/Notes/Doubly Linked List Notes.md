# Doubly Linked Lists

### Advantages
1. Bi-directional traversal
2. Efficient Deletion
3. Insertion at both ends

### representation

```cpp
struct node {
    int data;
    struct node *next;
    struct node* prev;
}
```
NULL ← [Prev | Data | Next] ⇄ [Prev | Data | Next] ⇄ [Prev | Data | Next] → NULL

## create
```c
#include <stdio.h>
#include <stdlib.h>

//declaring node
struct node {
    int data; 
    struct node* next;
    struct node* prev;
}
struct node * head , * tail;

void create DLL(){

    struct node* newnode;
    head = 0 ;
    tail = 0 ;
    
    while (choice){
        newNode = (struct node*) malloc (sizeof(struct node));

        printf("Enter data:");
        scanf("%d" , & newnode -> data);

        newNode-> next = 0;
        newNode -> prev = 0 ;

        if (head == 0){
            head = tail = newNode;
        }
        else {
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        printf("Do u want to add more ? (1/0)");
        scanf("%d", &choice)
    }
}
```

## Insertion at Beginning
1. create new node.
2. assign data val
3. assign new nodes next to head 
4. assign head prev to new node
5. update head to new node 

```c
Node* createnew(int val){
    struct Node *newnode = (struct Node*) malloc (sizeof (struct Node));
    newnode -> data = val;
    newNode -> next = NULL;
    newNode -> prev = NULL ;
    return newNode;
}
void InsertAtStart (struct node **head, int data){
    struct Node* n = createnew(int val);
    if (*head == NULL){
        *head = *tail = n;
    }
    n -> next = *head ;
    *head -> prev = n;
    *head = n;
 
}
```

## Insertion at Last
1. create new node
2. assign data
3. assign next = null (last node)
4. assign tail-> next = new node 
5. assign newnode -> prev = tail
6. update tail to newnode

```c
void insertAtTail{ 
    struct Node* n = createnew (int val);
    if (*tail == NULL){
        *tail = *head = n;
    }
    *tail -> next = n ;
    n -> prev = *tail;
    *tail  = n ;

}
```

## Insert At Pos
1. creat newNode.
2. make sure the position is within range
3. traverse till pos - 1
4. 
• Set newNode->next to prevNode->next.
• Set newNode->prev to prevNode.
• If prevNode->next is not NULL, set prevNode-
>next->prev to newNode.
• Set prevNode->next to newNode.

```c
void insertatpos()
{
 struct node *newnode , *temp;

 int pos, i = 1;
 printf("Enter position: ");
 scanf("%d", &pos);
 // Insert at beginning
 if(pos == 1)
 {
 insertatbeg();
 return;
 }
 newnode = (struct node*)malloc(sizeof(struct
node));
 printf("Enter data: ");
 scanf("%d",&newnode->data);

temp = head;
 // Move to position-1 node
 while(i < pos-1)
 {
 temp = temp->next;
 i++;
 }
 newnode->next = temp->next;
 newnode->prev = temp;
 if(temp->next != NULL)
 temp->next->prev = newnode;
 temp->next = newnode;
}
```

## Deletion At head
1. store first Node in temp
2. head = head ->next move head to 2nd node
3. head -> prev = NULL 
4. free old head

```c
void delFromBeg()
{
struct node *temp;
if(head == NULL)
{
printf("List is empty\n");
}
else
{
temp = head; // store first node
head = head->next; // move head to second node
head->prev = NULL; // new first node prev becomes NULL
}
free(temp); // delete old first node
}
```

## Deletion at Tail
1. store tail in temp
2. move tail to prev of tail
3. tail -> next = NULL;
4. delete old tail

```c
void delFromend()
{
struct node *temp;
if(head == NULL)
{
printf("List is empty\n");
}
else
{
temp = tail;
tail = tail->prev;
tail->next =0;
}
free(temp); // delete old first node
}
```

## delete at Pos
1. traverse till pos using temp
2. temp->prev->next = temp->next;
 temp->next->prev = temp->prev;

 ```c
 void delFromPos()
{
 int pos, i = 1;
 struct node *temp;
 temp = head;
 printf("Enter Position: ");
 scanf("%d", &pos);
 while(i < pos)
 {
 temp = temp->next;
 i++;
 }
 temp->prev->next = temp->next;
 temp->next->prev = temp->prev;
}
 ```
 ```c
 int main() {
    // Local head and tail pointers
    Node* head = NULL;
    Node* tail = NULL;

    printf("--- Doubly Linked List Operations ---\n");

    // Testing Insertions
    insertAtHead(&head, &tail, 10);      // [10]
    insertAtTail(&head, &tail, 30);      // [10, 30]
    insertAtPosition(&head, &tail, 20, 2); // [10, 20, 30]
    printf("After Insertions: ");
    display(head);

    // Testing Deletions
    deleteAtPosition(&head, &tail, 2);   // Remove 20
    printf("After Deleting Pos 2: ");
    display(head);

    deleteAtHead(&head, &tail);          // Remove 10
    printf("After Deleting Head:  ");
    display(head);

    deleteAtTail(&head, &tail);          // Remove 30
    printf("After Deleting Tail:  ");
    display(head);

    return 0;
}
 ```

