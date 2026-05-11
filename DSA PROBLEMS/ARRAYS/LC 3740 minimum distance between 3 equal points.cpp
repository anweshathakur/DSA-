/*
--- EDITORIAL ---
Intuition:
The problem asks for the "tightest" cluster of three identical values. The distance formula simplifies to 2(k-i) for i < j < k.

Approach (Brute Force):
1. Triple loop to find all combinations of i, j, k.
2. Check if nums[i] == nums[j] == nums[k].
3. Calculate distance and track the minimum.

Complexity:
- Time: O(N^3)
- Space: O(1)
-----------------
*/
/*
You are given an integer array nums.

A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].

The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.

Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.

 

Example 1:

Input: nums = [1,2,1,1,3]

Output: 6

Explanation:

The minimum distance is achieved by the good tuple (0, 2, 3).

(0, 2, 3) is a good tuple because nums[0] == nums[2] == nums[3] == 1. Its distance is abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6.

Example 2:

Input: nums = [1,1,2,3,2,1,2]

Output: 8

Explanation:

The minimum distance is achieved by the good tuple (2, 4, 6).

(2, 4, 6) is a good tuple because nums[2] == nums[4] == nums[6] == 2. Its distance is abs(2 - 4) + abs(4 - 6) + abs(6 - 2) = 2 + 2 + 4 = 8.

Example 3:

Input: nums = [1]
Output: -1

Explanation:
There are no good tuples. Therefore, the answer is -1.

Constraints:
1 <= n == nums.length <= 100
1 <= nums[i] <= n
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int min_dist = -1; 

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] == nums[j] && nums[j] == nums[k]) {
                        int current_dist = abs(i - j) + abs(j - k) + abs(k - i);
                        if (min_dist == -1 || current_dist < min_dist) {
                            min_dist = current_dist;
                        }
                    }
                }
            }
        }
        return min_dist;
    }
};
