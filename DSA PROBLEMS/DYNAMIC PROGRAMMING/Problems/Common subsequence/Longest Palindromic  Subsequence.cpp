//------------------------------------------------
//Longest Palindromic Subsequence
//------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int longestPalindromeSubseq(string s) {
    int n = s.size();
    memset(dp, -1, sizeof(dp));

    //base case 
    if (n==0) {
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1; // A single character is a palindrome of length 1
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            if (s[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[1][n];
}
int main() {
    string s = "bbbab";
    cout << longestPalindromeSubseq(s) << endl; // Output: 4
    return 0;
}