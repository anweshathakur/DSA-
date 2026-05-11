//------------------------------------PROBLEM STATEMENT----------------------------------------------------------------
/*
--- EDITORIAL ---
Intuition:
A median divides a sorted array into two equal-length halves. For two sorted arrays, we want to find a partition such that the left half of both combined arrays has the same number of elements as the right half, and all elements in the left half are less than or equal to elements in the right half.

Approach (Binary Search):
1. Partition the smaller array nums1 at index i.
2. Automatically partition the second array nums2 at j = (m+n+1)/2 - i.
3. Check if the elements around the partition satisfy: L1 <= R2 and L2 <= R1.
4. If L1 > R2, move the partition in nums1 to the left. If L2 > R1, move it to the right.
5. Once valid, calculate median based on even or odd total elements.

Complexity:
- Time: O(log(min(M, N)))
- Space: O(1)
-----------------

PROBLEM STATEMENT:
Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 10
*/

//--------------------------------- BRUTE FORCE SOLUTION --------------------------------------------------------------------
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class BruteForceSolution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        std::vector<int> merged;
        for (int i = 0; i < n; i++) merged.push_back(nums1[i]);
        for (int i = 0; i < m; i++) merged.push_back(nums2[i]);
        sort(merged.begin(), merged.end());
        int total = merged.size();
        if (total % 2 == 1) return static_cast<double>(merged[total / 2]);
        return (static_cast<double>(merged[total / 2 - 1]) + static_cast<double>(merged[total / 2])) / 2.0;
    }
};

//------------------------------ OPTIMISED BINARY SEARCH-------------------------------------------------------------
class OptimalSolution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        while (low <= high) {
            int i = (low + high) / 2;
            int j = (m + n + 1) / 2 - i;
            int L1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int R1 = (i == m) ? INT_MAX : nums1[i];
            int L2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int R2 = (j == n) ? INT_MAX : nums2[j];
            if (L1 <= R2 && L2 <= R1) {
                if ((m + n) % 2 != 0) return max(L1, L2);
                return (max(L1, L2) + min(R1, R2)) / 2.0;
            } else if (L1 > R2) high = i - 1;
            else low = i + 1;
        }
        return 0.0;
    }
};