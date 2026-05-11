# Circular Linked List Notes in cpp

## What is circular linked List
Circular Linked List is a type of Linked List where the last node points back to the first node forming a closed loop.

## Uses of Circular Linked Lists
1. continuous playlists
2. token passing in networks
3. real Time systems like Traffic light control

---

## Creation of Linked List
```c
#include <stdio.h>
void createCLL (){
    struct node* newnode, *temp;
    int choice = 1;

    while (choice){
        newnode = (struct node*) malloc (sizeof(struct node));

        printf("Enter Data:");
        scanf("%d",&newnode -> data);

        newnode -> next = 0;

        if(head == 0){
            head = temp = newnode;
        }
        else {
            temp -> nexr = newnode;
            temp = newnode;
        }
        temp -> next = head;

        printf("1 to continue 0 to exit");
        scanf("%d", &choice);
    }
}
void Display(){
    struct node *temp;

    if (head == 0){
        printf("List is Empty");
    }
    else {
        temp = head ;
    }
    do {
        printf("%d", temp -> data);
        temp = temp -> next;
    }
    while (temp != head);
}
```

---

##Check if CLL

```c
#include <stdio.h>
void checkCLL(){
    struct node *temp ;
    temp = head -> next

    while (temp != NULL && temp != head){
        temp = temp -> next;
    }

    if (temp == head){
        printf("LSIT IS CIRCULAR");
    }
    else {
        printf("not circular");
    }
}
```
## Insertion in CLL

### Insertion in Beginning
```c
void InsertAtHead(){
    struct node *newnode;

    newnode = (struct node*) malloc (sizeof(struct node));
    printf("enter Data:");
    scanf("%d" , &newnode-> data );

    if (head == 0){
        head = tail = newnode ;
        newnode -> next = head ;
    }
    else {
        newnode -> next = head ;
        head = newnode ;
        tail -> next = head ;
    }
}
```

### Insertion at Last
```c
void insertionAtLast(){
    struct node *newnode;

    newnode = (struct node*) malloc (sizeof(struct node));
    printf("enter Data:");
    scanf("%d" , &newnode-> data );

    if (head == 0){
        head = tail = newnode ;
        newnode -> next = head ;
    }
    else {
        tail -> next = newnode  ;
        tail = newnode ;
        tail -> next =head;
    }
}
```

### Insertion at Pos
```c
void insertionAtLast(){
    struct node *newnode, *temp;
    int pos , i = 1;

    printf ("enter pos:");
    scanf("%d", &pos);

    newnode = (struct node*) malloc (sizeof(struct node));
    printf("enter Data:");
    scanf("%d" , &newnode-> data );

    //empty list
    if (head == 0){
        head = tail = newnode ;
        newnode -> next = head ;
    }

    //at head 
    else if (pos == 1) {
        newnode -> next = head ;
        head = newnode ;
        tail -> next = head ;
    }

    //at pos
    else{
        temp = head ;
        while (i < pos -1){
            temp = temp -> next ;
            i++;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;

        //at last
        if (temmp == tail){
            tail= newnode;
        }
    }

}
```
## Deletion In CLL

### Deletion At Start
```c
void deleteBeg(){
    struct node *temp ;

    //empty
    if (head == 0){
        printf("Underflow");
    }
    //1 node
    if (head == tail){
        free(head);
        head = tail = 0;
    }
    else {
        temp = head ;
        head = head -> next;
        tail -> next = head;
        free (temp);
    }
}
```
### Deletion at Last
```c
void deleteLast(){
    struct node *temp ;

    //empty
    if (head == 0){
        printf("Underflow");
    }
    //1 node
    else if (head == tail){
        free(head);
        head = tail = 0;
    }
    else {
        temp = head ;
        while (temp -> next != tail){
            temp = tmep-> next;
        }
        temp -> next = head ;
        free (tail);
        tail = temp
    }

}
```
### Deletion at pos
```c
void deletePos(){
    struct node *nextnode, *temp;
    int pos , i = 1;

    printf ("enter pos:");
    scanf("%d", &pos);

    newnode = (struct node*) malloc (sizeof(struct node));
    printf("enter Data:");
    scanf("%d" , &newnode-> data );

    //empty
    if (head == 0){
        printf("Underflow");
    }
    //1 node
    else if (head == tail){
        free(head);
        head = tail = 0;
    }
    else {
        temp = head;
        while (i < pos - 1){
            temp = temp -> next;
            i++;
        }
        nextnode = temp -> next;
        temp -> next = nextnode -> next ;

        if (nextnode == tail){
            tail = temp;
            tail -> next = head ;
        }
        free(nextnode);
    }

}
```