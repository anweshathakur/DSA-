/*
--- EDITORIAL ---
Intuition:
The area is limited by the shorter of the two lines. To find a larger area, we need to either increase the distance between lines or find taller lines.

Approach (Two Pointers):
1. Place pointers at the start (left) and end (right).
2. Calculate area: min(height[left], height[right]) * (right - left).
3. To potentially find a larger area, move the pointer pointing to the shorter line inwards. Moving the taller line wouldn't help because the height is restricted by the shorter one.

Complexity:
- Time: O(N)
- Space: O(1)
-----------------
*/
/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/
#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        
        while (left < right) {
            int currentArea = std::min(height[left], height[right]) * (right - left);
            maxArea = std::max(maxArea, currentArea);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }
};