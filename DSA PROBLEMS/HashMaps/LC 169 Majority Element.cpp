/*
======================================
LC 169 Majority Element
======================================
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
The input is generated such that a majority element will exist in the array.
 
*/
#include <bits/stdc++.h>
class Solution {
public:
    int majorityElement(std :: vector<int>& nums) {
        int n = nums.size() ;
        
        std :: unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        for (int num : nums){
            if (freq[num] > n/2){
                return num ; 
            }
        }
        return 0 ;
    }
};