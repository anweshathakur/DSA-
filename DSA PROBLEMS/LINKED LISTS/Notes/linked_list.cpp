                                        //singly linked list 

#include <iostream>
using namespace std;

                        //implementation of list node in a singly linked list
class Node{
public:
    Node* next;   //pointer to the next node
    int val;    //data part of the node
    Node (int data){
        val = data;
        next = NULL; 
    }

};


                                      //inserion at head

void insertAtHead( Node* &head , int val){
    Node* n = new Node(val);  //create new node
    n -> next = head;  //point new node  towards the current head ( n ka next = purana head )
    head = n; //updating head to the new node ( head pointer now points to n )
}



                                      //insertion at tail,

void InsertAtTail(Node* &head, int val){
    Node* new_node  = new  Node(val);
    Node* temp = head;
    while (temp-> next != NULL){
        temp = temp -> next;
    }
    temp -> next = new_node;
    free (temp); 

}

                                  //insertion at any position (k)
void InsertAtPosition (Node* &head , int val , int pos){
    if (pos == 0){
        insertAtHead(head , val);
        return;
    }
    Node* temp = head;

    //traversing till ( k-1)th position 

    Node* new_node  = new  Node(val);
    Node* temp = head; 
    int cur_pos = 0;
    while (temp != NULL && cur_pos < pos -1){
        temp = temp -> next;
        cur_pos ++;
    }
    temp -> next = new_node;

}

                                      //update at position k 

void UpdateAtPosition(Node* &head , int k , int val){
    Node* temp = head;
    int cur_pos = 0; 
    while (cur_pos != k && temp != NULL){
        temp = temp -> next;
        cur_pos++;
    }
    if (temp != NULL) {
        temp->val = val; // update the value at position k
    }
}


                                  // deletion at head 

void DeleteAtHead(Node* &head){
    if (head == NULL) return;
    Node* temp = head;
    head = head -> next;
    free (temp);

}

                                    // delete at tail 
void DeleteAtTail(Node* &head){
    Node* sec_last = head;
    while (sec_last-> next -> next != NULL) {
        sec_last = sec_last -> next;
    }
    Node* temp = sec_last -> next;
    sec_last -> next = NULL;
    free(temp);

}
                                   //delete at any postion k
void DeleteAtPosition(Node* head , int pos){
    if (pos==0){
        DeleteAtHead(head);
        return;
    }
    int cur_pos = 0;
    Node* prev = head;
    while (cur_pos != pos -1 && prev != NULL){
        prev = prev-> next;
        cur_pos ++;
    }
    Node* temp = prev->next;
    free (temp);

}                                   

                                          //print 

void display( Node* head){
    Node* temp = head;   //temp pointer to traverse the list
    while (  temp != NULL){
        cout << temp -> val << "->" ;
        temp = temp -> next;   //move to the next node
    }


}





int main(){
    Node* head = NULL;
    Node* n = new Node(5);  // new node  with value 5
    cout << n -> val << endl; //print node
    
    insertAtHead(head,2);
    display(head);

    return 0;

}
