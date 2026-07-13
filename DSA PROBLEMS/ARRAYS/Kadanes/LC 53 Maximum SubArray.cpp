/*
=================================
LC 53 Maximum SubArray
=================================
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int n = nums.size(); 
        int maxSubArray = INT_MIN; // Correctly tracks global max
        int cur_max = 0;           // Tracks our current streak

        for (int i = 0; i < n; i++) {
            cur_max += nums[i]; // 1. Add current element to current streak

            if (cur_max > maxSubArray) {
                maxSubArray = cur_max; // 2. Update global max if this streak is the best
            }

            if (cur_max < 0) {
                cur_max = 0; // 3. Cut losses if streak drops below 0
            }
        } // <--- The loop closes here, wrapping ALL the steps together!

        return maxSubArray;
    }
};