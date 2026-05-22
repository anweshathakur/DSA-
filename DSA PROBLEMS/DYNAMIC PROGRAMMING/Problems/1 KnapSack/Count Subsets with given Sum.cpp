/*
Problem Statement: 
Given an array of non-negative integers and a sum, determine number of subsets of 
the given set with a sum equal to the given sum.
Example 1:
Input: arr[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: 2
Explanation: There are two subsets with sum 9, one is {4, 5} and other is {3, 4, 2}.
Example 2:
Input: arr[] = {1, 2, 3, 4, 5}, sum = 10
Output: 1   
Explanation: There is only one subset with sum 10, which is {1, 4, 5}.
EDITORIAL :
The idea is to use Dynamic Programming.
We create a 2D integer array count[][] of size (n+1) x (sum+1) where n is the number of elements
in the given set. The value of count[i][j] will be the number of subsets of the first i elements
of the given set with sum equal to j.
*/
#include <bits/stdc++.h>
using namespace std;
int countSubsets(int arr[], int n, int sum) {
    int count[n + 1][sum + 1];
    // Initialize the first column as 1
    for (int i = 0; i <= n; i++)
        count[i][0] = 1;

    // Initialize the first row (except count[0][0]) as 0
    for (int j = 1; j <= sum; j++)
        count[0][j] = 0;

    // Fill the count table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j)
                count[i][j] = count[i - 1][j] + count[i - 1][j - arr[i - 1]];
            else
                count[i][j] = count[i - 1][j];
        }
    }
    return count[n][sum];
}