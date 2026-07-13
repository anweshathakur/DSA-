/*
========================================
LC 918 Maximum Sum Circular SubArray
========================================
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
*/
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int total_sum = 0;
        
        int max_so_far = INT_MIN;
        int current_max = 0;
 
        int min_so_far = INT_MAX;
        int current_min = 0;
        
        for (int x : nums) {
            total_sum += x;

            current_max += x;
            max_so_far = std::max(max_so_far, current_max);
            if (current_max < 0) current_max = 0;

            current_min += x;
            min_so_far = std::min(min_so_far, current_min);
            if (current_min > 0) current_min = 0;
        }
        if (max_so_far < 0) {
            return max_so_far;
        }
        
        
        return std::max(max_so_far, total_sum - min_so_far);
    }
};