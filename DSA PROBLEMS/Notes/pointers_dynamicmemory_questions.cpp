
//swap two numbers- pointers
#include <iostream>
using namespace std;

void swap( int* a, int* b){
    int temp;

    temp = *a;
    *a =*b;
    *b = temp;

}
int main(){
    int x=5 , y=10;
    cout << "before swap, x=" << x << "y=" << y << endl;

    swap(&x , &y);
    cout << " after swap, x=" << x << "y=" << y << endl;

    return 0;

}
// largest number- dynamic allocation
#include <iostream>




