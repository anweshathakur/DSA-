# Stacks
- LIFO -> Last in First out 

### Using STL
```cpp
#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
s.push(2);
s.push(3);r̥
s.pop ();
cout << s.top() << endl;

```
### Operations
- push
- pop
- peak / top
- is empty

### Implementation Using Arrays 
```cpp
#include <iostream>
using namespace std;
class Stack {
    public:
        int *arr;
        int top;
        int size;

    //behaviour 
    Stack (int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
        }
    //push
    void push (int element){
        if (size - top > 1){
            top ++;
            arr[top]  = element ;
        }
        else {
            cout << "stack overflow" << endl;
        }
    }
    //pop
    void pop ( ){
        if (top >= 0){
            top --;
        }
        else{
            cout << "stack underflow"<< endl;
        }
    }
    //peek
    int peek (){
        if (top >= 0 && top < size){
            return arr[top];
        }
        else {
            cout << "Stack is empty" << endl;
            return -1;
        }   
    }
    //is empty 
    bool isEmpty(){
        if (top  ==  -1){
            return true;
        }
        else {
            return false;
        }
    }
};

int main(){
    Stack st(5);
    st.push(10);
    st.push(20);
    cout << "Top element: " << st.peek() << endl;
    st.pop();
    return 0;
}


```
###  Stack Implementation using Linked List

- when size of stack is not known in advance 

```cpp
#include <iostream>
using namespace std;

// Definition of the Node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top; // Equivalent to the 'head' of a linked list

public:
    Stack() : top(nullptr) {}

    // Add an element to the top
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top; 
        top = newNode;       
        cout << val << " pushed to stack\n";
    }

    // Remove the top element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        Node* temp = top;
        top = top->next;     // Move top to the next node
        cout << temp->data << " popped from stack\n";
        delete temp;         // Free the memory
    }

    // Return the top element without removing it
    int peek() {
        if (!isEmpty()) return top->data;
        return -1; // Or throw an exception
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    cout << "Top element is: " << s.peek() << endl;
    return 0;
}
```

### Check Valid Parenthesis
- create an empty stack.
- scan symbols of expression from left to right.
- if the symbol is a left bracket -> push in the stack
- if stack is empty-> invalid expression.
- mismatched -> invalid syntax
code :
```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') || 
                (c == ']' && top != '[') || 
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s;
    cout << "Enter Parenthesis: ";
    cin >> s;
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;
    return 0;
}
```
### Infix , Postfix , Prefix


Infix :
```
(A+B) * C
```

Postfix :
```
AB+C*
```

Prefix :
```
*+ABC
```

Algorithm : Infix to Postfix conversion
- scan the infix operation
- operand-> append to output string
- ( -> push to operator
- operator -> while stack is not empty & top is not ( and the top operator has greater precedency than -> pop from stack and append to output string
- ) -> pop from stack and append to output string until ( is encountered
- pop remaining elements from stack. 

example : 
```
Infix: A + B * C
1. Read A: Output = "A"
2. Read +: Push + onto stack. Stack = [+]
3. Read B: Output = "A B"
4. Read *: Push * onto stack. Stack = [+, *]
5. Read C: Output = "A B C"
6. End of string: Pop stack.
   - Pop *: Output = "A B C *"
   - Pop +: Output = "A B C * +"
Final Postfix: A B C * +
```
Algorithm : Infix to Prefix conversion

- scan the infix operation from right to left
- operand-> append to output string
- ) -> push to operator
- operator -> while stack is not empty & top is not ) and the top operator has greater precedency than -> pop from stack and append to output string
- ( -> pop from stack and append to output string until ) is encountered
- pop remaining elements from stack. 

OR
- Reverse the infix expression
- Convert the reversed expression to postfix
- Reverse the postfix expression to get the prefix expression

example : 
```
Infix: A + B * C
1. Reverse: C * B + A
2. Convert to Postfix:
   - Read C: Output = "C"
   - Read *: Push * onto stack. Stack = [*]
   - Read B: Output = "C B"
   - Read +: Push + onto stack. Stack = [*, +]
   - Read A: Output = "C B A"
   - End of string: Pop stack.
     - Pop +: Output = "C B A +"
     - Pop *: Output = "C B A + *"
   Final Postfix: C B A + *
3. Reverse: * + A B C
Final Prefix: * + A B C
```
code 
code 
```cpp
//infix to postfix
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove '('
        } else {
            while (!s.empty() && s.top() != '(' && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
```
code for infix to prefix
```cpp
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPrefix(string infix) {
    // 1. Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // 2. Swap '(' and ')'
    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    // 3. Convert to Postfix (using the same logic as before)
    stack<char> s;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && s.top() != '(' && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    // 4. Reverse the result to get Prefix
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;
    cout << "Prefix: " << infixToPrefix(infix) << endl;
    return 0;
}
```




