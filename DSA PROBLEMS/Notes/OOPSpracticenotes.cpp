//oops practice
/*
// user defined data 


#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollno;
    float cgpa;

    // constructor
    Student(string n, int r, float c) {
        name = n;
        rollno = r;
        cgpa = c;
    }

    // default constructor
    Student() {}
};

int main() {
    // default object bana ke values assign karna
    Student s1;
    s1.name = "anwesha thakur";
    s1.rollno = 2;
    s1.cgpa = 9;
    cout << s1.name << " " << s1.rollno << " " << s1.cgpa << endl;

    // constructor ke through direct values dena
    Student s2("anwesha thakur", 2, 9);
    cout << s2.name << " " << s2.rollno << " " << s2.cgpa << endl;

    return 0;
}

*/

//------------------------------------------------------------------------------------------------------------------
/*
//this keyword
// functions inside class

#include <iostream>
#include <string>
using namespace std;

class cricketer{
    public:
    string name;
    int runs;
    float avg;

    cricketer(string name, int runs, float avg){
        this->name = name;
        this->runs = runs;
        this-> avg = avg;

    }

    void display(){
        cout << name << runs << avg << endl;
    }
};

int main(){
    
    cricketer c1("virat" , 2500 , 55.2);
    cricketer c2 ("rohit" , 3000, 60.0);
    
    
    c1.display();
    c2.display();
    return 0;
}
*/

//-----------------------------------------------------------------------------------------------------
/*
// creating vectors
#include <iostream>
using namespace std;

class MyVector {
private:
    int* arr;       // pointer to array
    int capacity;   // total capacity
    int current;    // current size

public:
    // constructor
    MyVector() {
        arr = new int[1];
        capacity = 1;
        current = 0;
    }

    // add element at the end
    void push_back(int data) {
        if (current == capacity) {
            // double the capacity
            int* temp = new int[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }

    // remove last element
    void pop_back() {
        if (current > 0) {
            current--;
        }
    }

    // get element at index
    int get(int index) {
        if (index < current) {
            return arr[index];
        }
        return -1; // invalid index
    }

    // get size
    int size() {
        return current;
    }

    // get capacity
    int getCapacity() {
        return capacity;
    }

    // operator [] overloading
    int operator[](int index) {
        if (index < current) {
            return arr[index];
        }
        return -1;
    }
};

int main() {
    MyVector v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "Elements: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v.get(i) << " ";
    }
    cout << endl;

    v.pop_back();

    cout << "After pop_back, elements: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; // using operator[]
    }
    cout << endl;

    cout << "Size: " << v.size() << ", Capacity: " << v.getCapacity() << endl;

    return 0;
}
*/
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
// inheritence 
#include <iostream>
using namespace std;
class scooty{
    public:
    int topspeed;
    float milage;
    private:
    int bootspace;
};
class bike:public scooty{
    public:
    int gears;

};
*/
//--------------------------------------------------------------------------------------------------------------------------------





