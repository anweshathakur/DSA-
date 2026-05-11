/*
--- EDITORIAL ---
Intuition:
Reverse a stack without using any additional data structure (only recursion).

Approach:
1. Recursive Step: Pop the top element and recursively reverse the rest of the stack.
2. Helper (Insert at Bottom): Once the stack is empty, start pushing the elements back in, but each element must be inserted at the very bottom.
3. This effectively uses the recursion call stack to hold the elements temporarily.

Complexity:
- Time: O(N^2)
- Space: O(N)
-----------------
*/
//-------------------------Reverse A stack Using  Recusrion-----------------
//reverse a stack using recursion
#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s, int x);

void solve(stack<int>& s) {
    // Base case: If stack is empty, return
    if (s.empty()) {
        return;
    }
    
    // Store the top element
    int temp = s.top();
    s.pop();
    
    // Recursive call to reverse the remaining stack
    solve(s);
    
    // Insert the stored element at the bottom of the reversed stack
    insertAtBottom(s, temp);
}

void insertAtBottom(stack<int>& s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }
    
    int temp = s.top();
    s.pop();
    
    insertAtBottom(s, x);
    
    s.push(temp);
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
    
    solve(s);
    
    cout << "Reversed stack: ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}