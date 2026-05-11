//---------------------------------Insert Element At Bottom Of Stack--------------------------------------

#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& s, int x) {
    // Base case: If stack is empty, push the element
    if (s.empty()) {
        s.push(x);
        return;
    }
    
    // Store the top element
    int temp = s.top();
    s.pop();
    
    // Recursive call to insert at the bottom of the remaining stack
    solve(s, x);
    
    // Push the stored element back on top
    s.push(temp);
}

void insertAtBottom(stack<int>& s, int x) {
    solve(s, x);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    cout << "Original stack: ";
    stack<int> temp = s;
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    
    int x = 5;
    insertAtBottom(s, x);
    
    cout << "Stack after inserting " << x << " at bottom: ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}