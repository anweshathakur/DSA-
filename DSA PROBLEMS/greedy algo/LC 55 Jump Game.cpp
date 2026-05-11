/*
--- EDITORIAL ---
Intuition:
At any point, you want to know the furthest index you can reach. If you are at an index i that is beyond your current farthest reach, you can't proceed.

Approach (Greedy):
1. Track the farthest index reachable so far (initialized to 0).
2. Iterate through the array. If current index i > farthest, return false.
3. Update farthest = max(farthest, i + nums[i]).
4. If farthest reaches or exceeds the last index, return true.

Complexity:
- Time: O(N)
- Space: O(1)
-----------------
*/
/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/
#include <bits/stdc++.h>
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        for (int i = 0; i < n; i++) {
            if (i > farthest) {
                return false;
            }
            farthest = std::max(farthest, i + nums[i]);
            if (farthest >= n - 1) {
                return true;
            }
        }

        return false;
    }
};