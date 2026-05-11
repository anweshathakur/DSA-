//--------------------------------  IMPLEMENTATION OF TWO STACKS IN AN ARRAY-----------------------------
#include <iostream>
using namespace std;

class twoStack{
    //elements
    int *arr;
    int top1;
    int top2;
    int size;
public:
    twoStack (int size){
        this -> size = size;
        top1 = -1 ;
        top2 = size;
        arr = new int[size];
    }

    //push in stack 1
    void push1 (int num){
        //atelast 1 empty space is present
        if (top2-top1 > 1){
            top1 ++;
            arr[top1] = num;
        }
        else {
            cout << "stack overflow" << endl;
        }
    }
    //push in stack 2
    void push2(int num){
        //atelast 1 empty space is present
        if (top2-top1 > 1){
            top2 --;
            arr[top2] = num;
        }
        else {
            cout << "stack overflow" << endl;
        }

    }
    //pop in stacck 1  
    void pop1(){
        if (top1 >= 0 ){
            int ans  = arr[top1];
            top1 --;
        }
        else {
            cout << "STack Underflow"<< endl;
        }
    }
    //pop in stack2  
    void pop2(){
        if (top2 < size ){
            int ans  = arr[top2];
            top2 ++ ;
        }
        else {
            cout << "STack Underflow"<< endl;
        }
    }
};