// ----------------------------------------------
// LONGEST COMMON SUBSTRING
// ----------------------------------------------

//-----------------------------------------------
// PROBLEM STATEMENT
//-----------------------------------------------

/*
Given two strings, find the length of longest 
common substring.

Example 1:
Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.

Note: A substring is a contiguous sequence of characters within a string.
*/

//-----------------------------------------------
// SOLUTION
//-----------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int longestCommonSubstring(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    memset(dp, -1, sizeof(dp));
    int maxLength = 0;

    //base case 
    if (m==0 || n==0) {
        return 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return maxLength;
}
int main (){
    string S1 = "ABCDGH";
    string S2 = "ACDGHR";
    memset(dp, -1, sizeof(dp));
    cout << longestCommonSubstring(S1, S2) << endl; // Output: 4
    return 0;
}