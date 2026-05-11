//Q remove duplicates from a given sorted list
#include <iostream>
using namespace std;

class Node{
public:
    Node* next = NULL;
    int val;
    Node (int data){
        val = data ;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head = NULL;
    LinkedList(){
        head = NULL;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> val << "->";
            temp= temp-> next;    
        }
        
    }

};


void DuplicateDelete( Node* &head , int val){
    Node* curr = head; 
    Node* temp = curr->next ;
    while (curr != temp){
        curr = curr-> next ; 
    }
    curr -> next =  curr -> next -> next;
    delete(temp);

}

int main(){
    

}