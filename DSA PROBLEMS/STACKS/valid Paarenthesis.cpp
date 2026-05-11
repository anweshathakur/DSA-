/*
--- EDITORIAL ---
Intuition:
Brackets must be closed in the reverse order they were opened. This "Last-In, First-Out" (LIFO) behavior perfectly matches the Stack data structure.

Approach:
1. Iterate through the string.
2. If it's an opening bracket, push it onto the stack.
3. If it's a closing bracket, check if it matches the top of the stack. If it does, pop; otherwise, it's invalid.
4. After the loop, the stack must be empty for the string to be valid.

Complexity:
- Time: O(N)
- Space: O(N)
-----------------
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    
    for(char ch : s) {
        // If it's an opening bracket, push to stack
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else {
            // If it's a closing bracket, check for matching opening bracket at top
            if(st.empty()) return false;
            
            char top = st.top();
            if((ch == ')' && top == '(') || 
               (ch == '}' && top == '{') || 
               (ch == ']' && top == '[')) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    // If stack is empty, all brackets were matched
    return st.empty();
}

int main() {
    string s = "{[()]}";
    if(isValid(s)) {
        cout << s << " is balanced." << endl;
    } else {
        cout << s << " is not balanced." << endl;
    }
    return 0;
}
