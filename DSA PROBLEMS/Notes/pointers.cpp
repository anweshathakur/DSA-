#include <iostream>
using namespace std;
int main(){
    int X[5]= {1,2,3,4,5};
    cout << "second element :" << *(X+1) << endl;
    *(X+2)= 10;
    cout << "third element:" << *(X+2) << endl;
    return 0;

}

// passing a address as function arguememt
void change_value (int *p){
    *p= 100;
}

int main(){
    int n= 5;
    cout << "number before:" << n << endl;
    change_value(&n);
    cout << "number after " << n << endl;
    return 0;

}

//types of pointers
// 1. void  : we dont know the type of data
//2. dangling :pointing at deallocated/ non existing memory ( to avoid assign NULL))


