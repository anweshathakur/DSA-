/*
--- EDITORIAL ---
Intuition:
Reverse a string by utilizing the LIFO property of a stack.

Approach:
1. Push all characters of the string into a stack.
2. Pop each character and append it to a new string. Since the last character pushed is the first one popped, the string will be reversed.

Complexity:
- Time: O(N)
- Space: O(N)
-----------------
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseString(string S) {
    stack<char> st;
    
    // Push all characters of the string onto the stack
    for(int i = 0; i < S.length(); i++) {
        st.push(S[i]);
    }
    
    string ans = "";
    // Pop characters from the stack and append to the answer
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}

int main() {
    string str = "Anwesha";
    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << reverseString(str) << endl;
    return 0;
}