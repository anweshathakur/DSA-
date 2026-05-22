/*
Problem Statement: Given a set of numbers, determine if we can partition the set into two subsets such that the sum of elements in both subsets is equal.
Example 1:
Input: arr[] = {1, 5, 11, 5}
Output: True
Explanation: The array can be partitioned as {1, 5, 5} and {11}.

Example 2:
Input: arr[] = {1, 5, 3}
Output: False
Explanation: The array cannot be partitioned into two subsets with equal sum.

Editorial:
The idea is to find if there is a subset of the given set with a sum equal to half of the total 
sum of the elements in the set.
If the total sum is odd, we cannot partition the set into two equal subsets, so we return false.
If the total sum is even, we can use the Subset Sum Problem to determine if there is a subset with a
sum equal to half of the total sum.

*/
#include <bits/stdc++.h>
using namespace std;

bool canPartition(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // If sum is odd, we cannot partition the array into two equal subsets
    if (sum % 2 != 0)
        return false;

    sum /= 2;
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