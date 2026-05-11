//----------------- Remove The Middle Element -------------------------
//by recursion
#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& s, int k) {
    // Base case: If k becomes 0, we are at the middle element
    if (k == 0) {
        s.pop();
        return;
    }
    
    // Store the top element
    int temp = s.top();
    s.pop();
    
    // Recursive call for the remaining stack
    solve(s, k - 1);
    
    // Push the stored element back (after the middle is deleted)
    s.push(temp);
}

void deleteMiddle(stack<int>& s) {
    int n = s.size();
    int k = n / 2; // Calculate the index of the middle element (0-based)
    solve(s, k);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    cout << "Original stack: ";
    stack<int> temp = s;
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    
    deleteMiddle(s);
    
    cout << "Stack after deleting middle element: ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}



