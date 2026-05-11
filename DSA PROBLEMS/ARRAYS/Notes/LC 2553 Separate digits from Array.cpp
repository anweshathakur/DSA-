/*
Given an array of positive integers nums, return an array answer that consists of the digits of each integer in nums after separating them in the same order they appear in nums.

To separate the digits of an integer is to get all the digits it has in the same order.

For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].
 

Example 1:

Input: nums = [13,25,83,77]
Output: [1,3,2,5,8,3,7,7]
Explanation: 
- The separation of 13 is [1,3].
- The separation of 25 is [2,5].
- The separation of 83 is [8,3].
- The separation of 77 is [7,7].
answer = [1,3,2,5,8,3,7,7]. Note that answer contains the separations in the same order.
Example 2:

Input: nums = [7,1,3,9]
Output: [7,1,3,9]
Explanation: The separation of each integer in nums is itself.
answer = [7,1,3,9].
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 105
*/

//using modulo and division to separate digits
#include <bits/stdc++.h>
class Solution {
public:
    std :: vector<int> separateDigits(std :: vector<int>& nums) {
        std :: vector<int> output;
        int n = nums.size();
        for (int i = 0 ; i < n ; i++){
            std :: string s = std :: to_string(nums[i]);
            int m = s.size();
            int j = std :: pow(10, m-1) ; 
            int temp = nums[i];
            while (j > 1){
                output.push_back(temp / j);
                temp -= j * (temp / j);
                j /= 10 ;
                
            }
            output.push_back(temp % 10);
        }
        return output;
    }
};

// externally using string conversion to separate digits
class Solution {
public:
    std :: vector<int> separateDigits(std :: vector<int>& nums) {
        std :: vector<int> output;
        for (int val : nums) {
            std :: string s = std :: to_string(val);
            for (char c : s) {
                output.push_back(c - '0'); // Convert char '1' to int 1
            }
        }
        return output;
    }
};