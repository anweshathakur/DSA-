// LC Biweekly contest 183

// =============================================================================
// Problem 1: Minimum Operations to Move All Zeros to End
// =============================================================================
/*
 * Problem:
 *   Given an integer array nums, in one operation you can swap any two distinct
 *   indices i and j. Return the minimum number of swaps to move all 0s to the end.
 *
 * Editorial Note:
 *   The key observation is that each swap moves exactly one 0 to the "zero zone"
 *   (the last `total_zeroes` positions). So the answer equals the number of
 *   non-zero elements already sitting in the zero zone — those are the only cells
 *   that need to be displaced. Counting total zeros first lets us identify the
 *   zone boundary in O(n), making the overall solution O(n) time, O(1) space.
 *
 * Examples:
 *   [0,1,0,3,12] → 2
 *   [0,1,0,2]    → 1
 *   [1,2,0]      → 0
 *
 * Constraints: 1 <= nums.length <= 100, 0 <= nums[i] <= 100
 */
#include <bits/stdc++.h>

class Solution {
public:
    int minimumSwaps(std::vector<int>& nums) {
        int count = 0 ;
        int n = nums.size() ; 

        for (int i = 0 ; i < n ; i++){
            if (nums[i]== 0 ){
                count++ ;
            }
        }
        int numsRight = 0 ;
        for (int i = n - count ; i < n ; i++){
            if (nums[i] != 0){
                numsRight ++ ;
            }
        }
        return numsRight ;
    }
};
// =============================================================================
// Problem 2: Minimum Operations to Make Array Modulo Alternating
// =============================================================================
/*
 * Problem:
 *   Given an integer array nums and integer k, in one operation you can
 *   increment or decrement any element by 1. An array is "modulo alternating"
 *   if there exist two DISTINCT values x, y (0 <= x, y < k) such that every
 *   even-indexed element satisfies nums[i] % k == x and every odd-indexed
 *   element satisfies nums[i] % k == y. Return the minimum operations needed.
 *
 * Editorial Note:
 *   For each element, the cost to shift its remainder from `r` to target `t`
 *   on a circular modulo-k wheel is min(|r - t|, k - |r - t|). We enumerate
 *   all k^2 - k valid (x, y) pairs (x != y) and pick the pair with minimum
 *   total cost. With k, n <= 100 this is at most 100*100*100 = 10^6 operations,
 *   well within limits. A faster O(n + k^2) approach precomputes frequency
 *   tables but is unnecessary here given the constraints.
 *
 * Examples:
 *   nums = [1,4,2,8], k = 3 → 2
 *   nums = [1,1,1],   k = 3 → 1
 *
 * Constraints: 1 <= nums.length <= 100, 1 <= nums[i] <= 10^9, 2 <= k <= 100
 */
#include <bits/stdc++.h>


class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        std::vector<int> velmorqati = nums;
        int n = velmorqati.size();
        
        int ans = INT_MAX;
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) continue; 
                
                int currops = 0;
                for (int i = 0; i < n; i++) {
                    int rem = velmorqati[i] % k;
                    int target = (i % 2 == 0) ? x : y;
                    int diff = std::abs(rem - target);
                    currops += std::min(diff, k - diff);
                }
                
                ans = std::min(ans, currops);
            }
        }
        
        return ans;

    }
};

// =============================================================================
// Problem 3: Maximum Sum of Shared Cells Between Two Grid Paths
// =============================================================================
/*
 * Problem:
 *   Player 1 travels (0,0) → (m-1,n-1) moving only right or down.
 *   Player 2 travels (m-1,0) → (0,n-1) moving only right or up.
 *   A "shared" cell appears on both paths. Maximize the sum of shared cell values.
 *
 * Editorial Note:
 *   Any shared region on a single row must be a contiguous horizontal segment
 *   [l, r] — both players can only move right on a given row. This lets us use
 *   a sweep-line over each row with four DP tables:
 *
 *     dp1[i][j] — best path cost from (0,0)     to (i,j)   [right/down]
 *     dp2[i][j] — best path cost from (i,j)     to (m-1,n-1) [right/down]
 *     dp3[i][j] — best path cost from (m-1,0)   to (i,j)   [right/up]
 *     dp4[i][j] — best path cost from (i,j)     to (0,n-1) [right/up]
 *
 *   For a shared segment [l, r] on row i, the combined score is:
 *     (dp1[i][l] + dp3[i][l] - mat[l])   ← both players arrive at l
 *   + sum(mat[l..r])                      ← shared segment counted once
 *   + (dp2[i][r] + dp4[i][r] - mat[r])   ← both players leave from r
 *
 *   Rearranging for a left-to-right sweep:
 *     maxLeft(l) = dp1[i][l] + dp3[i][l] - mat[i][l] - pref[l]
 *     right(r)   = dp2[i][r] + dp4[i][r] - mat[i][r] + pref[r]
 *     answer     = max over all (l <= r): maxLeft(l) + right(r)
 *
 *   Time: O(m*n), Space: O(m*n).
 *
 * Examples:
 *   grid = [[1,2,0,-3],[1,-2,1,0],[-4,2,-1,3],[3,-3,3,-2],[-1,-5,0,1]] → 4
 *   grid = [[4,-2,-3],[-1,-3,-1],[-4,2,-1]]                             → 3
 *
 * Constraints: 2 <= m,n <= 1000, 4 <= m*n <= 5*10^5, -100 <= grid[i][j] <= 100
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        
        auto mat = grid;
        int m = mat.size();
        int n = mat[0].size();
        const int NEG_INF = -1e8;
        
        
        vector<vector<int>> dp1(m, vector<int>(n, NEG_INF));
        vector<vector<int>> dp2(m, vector<int>(n, NEG_INF));
        vector<vector<int>> dp3(m, vector<int>(n, NEG_INF));
        vector<vector<int>> dp4(m, vector<int>(n, NEG_INF));
        
        
        dp1[0][0] = mat[0][0];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (i > 0 && dp1[i-1][j] > NEG_INF)
                    dp1[i][j] = max(dp1[i][j], dp1[i-1][j] + mat[i][j]);
                if (j > 0 && dp1[i][j-1] > NEG_INF)
                    dp1[i][j] = max(dp1[i][j], dp1[i][j-1] + mat[i][j]);
            }
        
        
        dp2[m-1][n-1] = mat[m-1][n-1];
        for (int i = m-1; i >= 0; i--)
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) continue;
                if (i < m-1 && dp2[i+1][j] > NEG_INF)
                    dp2[i][j] = max(dp2[i][j], dp2[i+1][j] + mat[i][j]);
                if (j < n-1 && dp2[i][j+1] > NEG_INF)
                    dp2[i][j] = max(dp2[i][j], dp2[i][j+1] + mat[i][j]);
            }
        
        
        dp3[m-1][0] = mat[m-1][0];
        for (int i = m-1; i >= 0; i--)
            for (int j = 0; j < n; j++) {
                if (i == m-1 && j == 0) continue;
                if (i < m-1 && dp3[i+1][j] > NEG_INF)
                    dp3[i][j] = max(dp3[i][j], dp3[i+1][j] + mat[i][j]);
                if (j > 0 && dp3[i][j-1] > NEG_INF)
                    dp3[i][j] = max(dp3[i][j], dp3[i][j-1] + mat[i][j]);
            }
        
        
        dp4[0][n-1] = mat[0][n-1];
        for (int i = 0; i < m; i++)
            for (int j = n-1; j >= 0; j--) {
                if (i == 0 && j == n-1) continue;
                if (i > 0 && dp4[i-1][j] > NEG_INF)
                    dp4[i][j] = max(dp4[i][j], dp4[i-1][j] + mat[i][j]);
                if (j < n-1 && dp4[i][j+1] > NEG_INF)
                    dp4[i][j] = max(dp4[i][j], dp4[i][j+1] + mat[i][j]);
            }
        
        int maxSum = NEG_INF;
        
        for (int i = 0; i < m; i++) {
            vector<int> pref(n, 0);
            pref[0] = mat[i][0];
            for (int j = 1; j < n; j++)
                pref[j] = pref[j-1] + mat[i][j];
 
            int maxLeft = NEG_INF;
            
            for (int j = 0; j < n; j++) {
                if (dp1[i][j] > NEG_INF && dp3[i][j] > NEG_INF) {
                    int leftVal = dp1[i][j] + dp3[i][j] - mat[i][j] - pref[j];
                    maxLeft = max(maxLeft, leftVal);
                }
                if (maxLeft > NEG_INF && dp2[i][j] > NEG_INF && dp4[i][j] > NEG_INF) {
                    int rightVal = dp2[i][j] + dp4[i][j] - mat[i][j] + pref[j];
                    maxSum = max(maxSum, maxLeft + rightVal);
                }
            }
        }
        
        return maxSum;
    }
};