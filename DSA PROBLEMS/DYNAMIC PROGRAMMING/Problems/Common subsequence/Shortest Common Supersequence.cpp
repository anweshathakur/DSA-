//----------------------------------------------
// Shortest Common Supersequence
//-----------------------------------------------


//-----------------------------------------------
// Problem Statement
//-----------------------------------------------
/*
Given two strings, find the length of shortest 
common supersequence.

Example 1:
Input: S1 = "AGGTAB", S2 = "GXTXAYB"
Output: 9
Explanation: The shortest common supersequence is
 "AGGTABGXTXAYB" which has length 9.

 Example 2:
 Input: S1 = "geek", S2 = "eke"
 Output: 5
 Explanation: The shortest common supersequence is
"geeke" which has length 5.
Note: A supersequence of a string is a string that
*/

//-----------------------------------------------
// Solution
//-----------------------------------------------

#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int ShortestCommonSupersequence(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    memset(dp, -1, sizeof(dp));

    //base case 
    if (m==0) {
        return n;
    }
    if (n==0) {
        return m;
    }
    //lenght of both the strings add - length of longest common subsequence
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return m + n - dp[m][n];
}
int main (){
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    memset(dp, -1, sizeof(dp));
    cout << ShortestCommonSupersequence(S1, S2) << endl; // Output: 9
    return 0;
}
