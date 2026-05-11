# Queue Notes in C ++ && C 
- First in First out (FIFO)
- push : rear <br>  pop : front

## Queue STL 
funtions :
- push (x)
- pop ()
- size ()
- isEmpty ()
- front ()
- rear () 

```cpp
#include <iostream>
#include <queue>
using namespace std;
int main (){
    //create  queue
    queue <int> q ;

    q.push (1);
    q.push (2);
    q.push (3);
    q.push (4);

    cout <<size << q.size()<< endl;
    q.pop();
    q.pop();
    cout << first element << q.front() <<endl;
    cout << is  empty? << q.isEmpty() << endl;

    return 0;
}
```

## Implementation of Queue using stacks 

A queue follows FIFO (First in First Out) , while a stack follows LIFO (Last In First Out). Hence , to implement stacks using queues we use two stacks.

- Enqueue 
    - push element  in Stack 1
- Dequeue 
    - If Stack 2 is  empty -> push all elements from stack 1 to Stack 2 and pop from stack2 . 
    - since the order gets reversed the first element of  Stack 1 bcomes the last of  Stack 2 , hence the first element of stacck 1 gets popped.

### C Program to implement queue using two stacks 
```c
#incluude <stdio.h>
#define MAX 100

int stack1[MAX] , stack2[MAX];
int top1 =  -1 ; top2 = -1 ; 

//push to top1
void enqueue (int x){
    if (top1== MAX-1){
        printf ("Queue Overflow !\n");
        return ;
    }
    stack1[++top1] = x;
}
//Pop from Stack2 
int dequeue (){
    if (top1 == -1 && top2 == -1 ){
        printf ("Queue Underflow\n");
        return -1 ;
    }
    //transffer if stack 2 is empty
    if  (top2 == -1 ){
        while (top1 != -1 ){
            stack2[++top2] = stack1[top1--];
        }
    }
    return stack2[top2--];
}

//display
void display() {
    int i;
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    // stack2 elements (front side)
    for (i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    // stack1 elements (rear side)
    for (i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    enqueue(40);
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    return 0;
}

```
### Array Based Stack Implementation using C
```c
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == SIZE - 1) { printf("Queue Overflow!\n"); return; }
    if (front == -1) front = 0;
    queue[++rear] = val;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n"); return -1;
    }
    return queue[front++];
}

void display() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
```

## Implementation of Queue Using LinkedList
```c
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node
struct Node {
    int data;
    struct Node* next;
};

// Pointers to keep track of the queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to add an element (Enqueue)
void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed (Overflow)!\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;

    // If queue is empty, both front and rear point to the new node
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    // Add the new node at the end and update rear
    rear->next = newNode;
    rear = newNode;
}

// Function to remove an element (Dequeue)
int dequeue() {
    if (front == NULL) {
        printf("Queue Underflow!\n");
        return -1;
    }

    struct Node* temp = front;
    int data = temp->data;

    // Move front to the next node
    front = front->next;

    // If front becomes NULL, set rear to NULL as well
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return data;
}

void display() {
    struct Node* temp = front;
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(); // Output: 10 -> 20 -> 30 -> NULL

    printf("Dequeued: %d\n", dequeue());
    display(); // Output: 20 -> 30 -> NULL

    return 0;
}
```
# DeQueue
Deque or Double Ended Queue is a generalized version of Queue data structure that allows insert and delete at both ends.

### Operations  
- insertFront(x) → Insert an element at the front end.
- insertRear(x) → Insert an element at the rear end.
- deleteFront() → Delete an element from the front end.
-  deleteRear() → Delete an element from the rear end.
- getFront() → Retrieve (but don’t remove) the front element.
- getRear() → Retrieve (but don’t remove) the rear element.
- isEmpty() → Check if the deque is empty.
- size() → Return the number of elements currently in the deque

## Implementation using Arrays in C
```c
#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

void insertFront(int val) {
    if ((rear + 1) % SIZE == front) {
        printf("Deque Overflow!\n");
        return;
    }
    if (front == -1) { // Empty
        front = rear = 0;
    } else if (front == 0) { // Wrap around
        front = SIZE - 1;
    } else {
        front--;
    }
    deque[front] = val;
}

void insertRear(int val) {
    if ((rear + 1) % SIZE == front) {
        printf("Deque Overflow!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1) { // Wrap around
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = val;
}

void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow!\n");
        return;
    }
    printf("Deleted: %d\n", deque[front]);
    if (front == rear) { // Last element
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque Underflow!\n");
        return;
    }
    printf("Deleted: %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) return;
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
```
## Implementation using Linkedlists in c
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Node *front = NULL, *rear = NULL;

void insertFront(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = front;
    newNode->prev = NULL;

    if (front == NULL) {
        front = rear = newNode;
    } else {
        front->prev = newNode;
        front = newNode;
    }
}

void insertRear(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void deleteFront() {
    if (front == NULL) return;
    struct Node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    else front->prev = NULL;
    free(temp);
}

void deleteRear() {
    if (rear == NULL) return;
    struct Node* temp = rear;
    rear = rear->prev;
    if (rear == NULL) front = NULL;
    else rear->next = NULL;
    free(temp);
}

void display() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
```

# Circular Queue
A Circular Queue is an optimized version of a standard Queue that connects the last position back to the first, forming a circle. This allows the reuse of empty slots created by deletions, preventing memory wastage.

### Operations
-	enqueue(x) → Insert an element at the rear end using circular increment: $rear = (rear + 1) \% CAPACITY$.
-	dequeue() → Delete and return the element at the front end using circular increment: $front = (front + 1) \% CAPACITY$.
-	peek() / getFront() → Retrieve (but don't remove) the element at the front end.
-	isFull() → Check if the queue is full; occurs when $(rear + 1) \% CAPACITY == front$ or $size == CAPACITY$.
-	isEmpty() → Check if the queue is empty; occurs when $front == -1$ or $size == 0$.
-	size() → Return the total number of elements currently stored in the queue.

### Key Advantages
-	Memory Efficiency: Unlike a linear queue, it reclaims space from dequeued elements without shifting the entire array.
-	Constant Time: All primary operations (enqueue, dequeue, peek) are $O(1)$ complexity.

## Implenetation Usinng Arrays In C
```c
#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
    if ((rear +1 )% SIZE == front) return 1;
    return 0;
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE; // Circular increment
        items[rear] = element;
        printf("Inserted %d\n", element);
    }
}

int dequeue() {
    int element;
    if (front == -1) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        element = items[front];
        if (front == rear) { // Only one element was present
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE; // Circular increment
        }
        return element;
    }
}

void display() {
    if (front == -1) printf("Empty Queue\n");
    else {
        int i;
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", items[i]);
        }
        printf("%d\n", items[i]);
    }
}

```
## Implementaion Using  Linkelist in C
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    if (front == NULL) {
        front = newNode;
    } else {
        rear->next = newNode;
    }
    rear = newNode;
    rear->next = front; // Point back to front
}

void dequeue() {
    if (front == NULL) {
        printf("Underflow!\n");
        return;
    }
    if (front == rear) { // Only one node
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        front = front->next;
        rear->next = front; // Maintain circle
        free(temp);
    }
}

void display() {
    struct Node* temp = front;
    if (front == NULL) return;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("(Back to Front)\n");
}
```
## Implenetaion of Deque Using Circular Queue in C
```c
#include <stdio.h>
#define CAPACITY 5

int arr[CAPACITY];
int front = 0;
int size = 0;

int isEmpty() {
    return size == 0;
}

int isFull() {
    return size == CAPACITY;
}

// 1. Insert at Front (Already in your screenshot)
void insertFront(int key) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }
    // Move front backwards circularly
    front = (front - 1 + CAPACITY) % CAPACITY;
    arr[front] = key;
    size++;
}

// 2. Insert at Rear
void insertRear(int key) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }
    // Calculate rear position based on front and size
    int rear = (front + size) % CAPACITY;
    arr[rear] = key;
    size++;
}

// 3. Delete from Front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from front: %d\n", arr[front]);
    // Move front forwards circularly
    front = (front + 1) % CAPACITY;
    size--;
}

// 4. Delete from Rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    // Calculate the current rear index
    int rear = (front + size - 1) % CAPACITY;
    printf("Deleted from rear: %d\n", arr[rear]);
    size--;
}

// 5. Display the Queue
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    for (int i = 0; i < size; i++) {
        int index = (front + i) % CAPACITY;
        printf("%d ", arr[index]);
    }
    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display(); // Should show: 5 10 20 

    deleteRear();
    display(); // Should show: 5 10 

    deleteFront();
    display(); // Should show: 10 

    return 0;
}
```

