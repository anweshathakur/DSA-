                   //doubly linked  list
//bi directional

#include<iostream>
using namespace std;

class  Node {
    public:
    int val;
    Node* next;
    Node* prev;

    Node (int data){        
        val = data;
        Node* next = NULL;
        Node* prev = NULL;

    }
};


class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;

    DoublyLinkedList(){
        head= NULL;
        tail= NULL;
    }

    void display(){
        Node* temp = head;
        while (temp != NULL){
            cout << temp -> val << "<->";
            temp = temp-> next;


        }


    }

    void InsertAtHead(int val){
    Node* NewNode = new  Node(val);

    if (head== NULL){
        head= NewNode;
        tail = NewNode;
    }
    NewNode -> next = head;
    head -> prev = NewNode;
    head = NewNode;


    } 
    void InsertAtTail(int val){
        Node* NewNode = new Node(val);
        // checking if the node is empty

        if (head== NULL){
            head = NewNode;
            tail = NewNode;
            return;
        }
        tail -> next = NewNode;
        NewNode -> prev = tail;
        tail= NewNode;

    }

    void  InsertAtPosition(int val , int k  ){
        Node* NewNode = new Node(val);

        if (head == NULL){
            head = NewNode;
            tail = NewNode;
            return;

        }
        int  k;
        cin >> k;
        Node* temp = head;
        int count=1;
        while(count < (k -1)){
            temp = temp-> next;
            count ++;

        }
        temp -> next = NewNode;
        NewNode -> prev = temp;

        NewNode -> next = temp-> next ;
        temp -> next -> prev = NewNode;

        temp-> next = NewNode;
        return;
        

    }

    void RemoveHead(){

        if (head == NULL){
            return;
        }
        Node* temp = head;
        head-> next = head;
        if (head == NULL){
            tail = NULL;
        }
        else {
            head -> prev == NULL;
        }
        delete (temp);
    }

    void RemoveTail(){

        if (tail == NULL){
            return;
        }
        Node* temp = tail;
        tail -> prev = tail;
        if (tail ==  NULL){
            head == NULL;
        }
        else {
            tail -> next = NULL;

        }
    
    }
    void RemovePosition(int k, int count ){
        cin >> k;
        count == 1;
        Node* temp = head;

        while (count < k ){
            temp = temp-> next;
            count ++;
        }
        temp -> next -> prev = temp-> prev;
        temp -> prev -> next = temp -> next;
        delete (temp);
    }
};

    
int main(){
    Node* NewNode= new Node(1);

    DoublyLinkedList dll;
    dll.head =  NewNode;
    dll.tail = NewNode;

}
