// Longest Palindromic Substring

/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"

Output: "bab"

Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"

Output: "bb"

 

Constraints:

1 <= s.length <= 1000
s consists of only digits and English letters.
*/

/*
EDITORIAL : 

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string LongestPallindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        
        int start = 0;      
        int maxLength = 1;  
        
        // Case 1: Single character substrings
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        // Case 2: Substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }
        
        // Case 3: Substrings of length 3 to n
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; 
                
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    
                    if (len > maxLength) {
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }
        
        return s.substr(start, maxLength);
    }
};
