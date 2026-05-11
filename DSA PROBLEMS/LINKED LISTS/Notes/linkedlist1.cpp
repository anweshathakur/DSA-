//Q. delete every alternate element from the list starting frm second 
#include <iostream>
using namespace std;
class Node{
public:    
    Node* next;   //pointer to the next node
    int val;    //data part of the node
    Node (int data){
        val = data;
        next = NULL; 
    }
};

class LinkedList{
public:
    Node* head;
    LinkedList(){
        head = NULL;
    }

    void InsertAtTail(int val){
        Node* NewNode = new Node(val);
        if (head = NULL){
            head = NewNode;
            return;
        }
        Node* temp = head;
        while (temp -> next != NULL){
            temp = temp-> next;
        }
        temp-> next = NewNode;
    } 
    
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> val << "->";
            temp= temp-> next;    
        }
        }

};

void DeleteAlternate(Node* &head , int val){
    Node* curr = head ;
    while (curr != NULL && curr->next != NULL){
        Node* temp = curr -> next;
        curr-> next = curr -> next -> next;
        free(temp);
    }

}
int main (){

}