// ROD CUTTING PROBLEM

/*
Problem Statement : 
Given a rod of length n inches and an array of prices 
that contains prices of all pieces of size smaller than n.
the table for prices is indexed from 1 to n. 
Determine the maximum value obtainable by cutting up the rod 
and selling the pieces.

Example 1:
Input: price[] = {1, 5, 8, 9, 10, 17, 17, 20}, n = 8
Output: 22

Explanation: The maximum obtainable value is 22 by cutting 
in two pieces of lengths 2 and 6, i.e., 5+17=22.
*/
#include <bits/stdc++.h>
using namespace std;
int cutRod(int price[],int length[], int n) {
// choice 
    // If the current item can fit inside the remaining capacity
    if(length[n-1] <= n){

        // Choice 1 : Include the current item
        // Add its value and dont reduce the remaining capacity
        int include = price[n-1] +
                cutRod(price, length, n - length[n-1]);

        // Choice 2 : Exclude the current item
        // Move to the next item without changing capacity
        int exclude = cutRod(price, length, n-1);

        // Return the maximum profit from both choices
        return max(include, exclude);
    }

    // If the current item cannot fit in the sack
    else{

        // Skip the current item
        int exclude = cutRod(price, length, n-1 );
        return exclude;
    }
}
int main() {
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum Obtainable Value is " << cutRod(price,length , n);
    return 0;
}   