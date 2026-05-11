// Detecting loop in a linked list
//delete the loop if it is present in the linked list
//return the starting node of linked list
#include <iostream>
#include <map>
using namespace std;
struct Node {
    int data;
    Node* next;
};
//detect loop in linked list
bool detectLoop(Node* head){
    map<Node*, bool> visited;
    Node* temp = head;
    if (head == NULL){
        return false;
    }

    while (temp!= NULL){
        if (visited[temp] == true){
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

//delete loop in linked list
void deleteLoop (Node* head){
    map <Node*, bool> visited ;
    Node* temp = head ;
    if (head == NULL){
        return;
    }
    while (temp != NULL){
        if (visited[temp]== true){
            temp -> next = NULL;
            return;
        }
        visited [temp ] = true;
        temp = temp -> next;
    }
}
//return 1st node of loop
Node* first (Node* head){
    map <Node*, bool> visited ;
    Node* temp = head ;
    if (head == NULL){
        return NULL;
    }
    while (temp != NULL){
        if (visited[temp]== true){
            return temp;
        }
        visited [temp ] = true;
        temp = temp -> next;
    }
    return NULL;
}
