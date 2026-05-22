/*
Problem Statement: Given an array of non-negative integers and a sum, 
determine if there is a subset of the given set with a sum equal to the given sum.
Example 1:
Input: arr[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True
Explanation: There is a subset (4, 5) with sum 9.

EDITORIAL :
The idea is to use Dynamic Programming. 
We create a 2D boolean array subset[][] of size (n+1) x (sum+1) where n is the number of elements 
in the given set. The value of subset[i][j] will be true if there is a subset of the first i elements 
of the given set with sum equal to j, otherwise false.
*/
#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum) {
    bool subset[n + 1][sum + 1];
    // Initialize the first column as true
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    // Initialize the first row (except subset[0][0]) as false
    for (int j = 1; j <= sum; j++)
        subset[0][j] = false;

    // Fill the subset table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j)
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - arr[i - 1]];
            else
                subset[i][j] = subset[i - 1][j];
        }
    }
    return subset[n][sum];
}