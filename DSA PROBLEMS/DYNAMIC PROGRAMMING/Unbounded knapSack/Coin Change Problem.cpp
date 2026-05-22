// COIN CHANGE PROBLEM

/*
Problem Statement :
Given a value N, if we want to make change for N cents, 
and we have infinite supply of each of S = { S1, S2, .. , Sm}
valued coins,
how many ways can we make the change? 
The order of coins doesn’t matter.

Example 1:
Input: N = 4, S = {1,2,3}
Output: 4
Explanation: There are four solutions:
{1,1,1,1}, {1,1,2}, {1,3}, {2,2}.  
So output is 4.

*/
#include <bits/stdc++.h>
using namespace std;
int count(int S[], int m, int n) {
    // We need n+1 rows as the table is constructed in bottom up manner using the base case 0 value case (n = 0)
    // and m+1 columns as the table is constructed in bottom up manner using the base case 0 coin case (m = 0)
    int table[n + 1][m + 1];

    // Fill the entries for 0 value case (n = 0)
    // If n is 0 then there is one solution (do not include any coin)
    for (int i = 0; i <= m; i++)
        table[0][i] = 1;

    // Fill rest of the table entries in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // Count of solutions including S[j-1]
            int x = (i - S[j - 1] >= 0) ? table[i - S[j - 1]][j] : 0;

            // Count of solutions excluding S[j-1]
            int y = table[i][j - 1];

            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m];
}
int main() {
    int arr[] = {1, 2, 3};
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = 4;
    cout << count(arr, m, n);
    return 0;
}