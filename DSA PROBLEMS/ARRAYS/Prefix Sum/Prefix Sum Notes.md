 Algorithmic Notes: Prefix Sum1. Core ConceptGoal: Calculate the sum of elements in any contiguous range $[L \dots R]$ of an array in $O(1)$ constant time.Intuition: Precompute a running total. To find a specific range sum, take the total sum up to the end point ($R$) and subtract the unwanted sum before the start point ($L-1$).2. The Golden Math Formulas0-Based Indexing (Standard)If your prefix array $P$ is the same size as original array $A$:Build: $P[i] = P[i-1] + A[i]$Query Range $[L \dots R]$:$$\text{Sum}(L \dots R) = P[R] - P[L - 1]$$(Requires an if (L == 0) check to prevent out-of-bounds error).1-Based Indexing (Recommended Practice)Make the prefix array $P$ of size $N + 1$ with a dummy 0 at the front to avoid boundary checks.Build: $P[i + 1] = P[i] + A[i]$Query Range $[L \dots R]$:$$\text{Sum}(L \dots R) = P[R + 1] - P[L]$$3. Visual Trace ExampleGiven Array $A = [3, 2, -1, 6, 5]$Index012345Array $A$-32-165Prefix $P$03541015Task: Find sum from Index $2$ to $4$ (Elements: $-1, 6, 5$).Calculation: $P[4 + 1] - P[2] = P[5] - P[2] = 15 - 5 = \mathbf{10}$.4. C++ Template Blueprint (1-Based Style)C++#include <vector>

// 1. Initialize original data
std::vector<int> nums = {3, 2, -1, 6, 5};
int n = nums.size();

// 2. Precompute Prefix Sum Array
std::vector<int> pref(n + 1, 0);
for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + nums[i];
}

// 3. Answer any range query [L, R] in O(1)
int L = 2, R = 4;
int rangeSum = pref[R + 1] - pref[L]; 
5. Complexity AnalysisSpace Complexity: $O(N)$ to store the precomputed prefix array.Time Complexity:Preprocessing/Building: $O(N)$ (done exactly once).Per Query: $O(1)$ constant time.6. How to Spot Prefix Sum ProblemsThe problem asks you to calculate sums, averages, or frequencies across multiple contiguous ranges/subarrays.The array is immutable (elements do not change value midway through queries).You see phrasing like "find total count of subarrays matching a condition" or "answer $Q$ range queries quickly".

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> A = {3, 2, -1, 6, 5, 4};
    int n = A.size();
    
    // Create prefix array of size n + 1, filled with zeros
    std::vector<int> P(n + 1, 0);
    
    // Build the running total
    for (int i = 0; i < n; i++) {
        P[i + 1] = P[i] + A[i];
    }
    
    // Now, P becomes: [0, 3, 5, 4, 10, 15, 19]
    
    // Let's query the sum from original index 2 to 4 (elements: -1, 6, 5)
    // Formula changes slightly with 1-based shift: Sum(L...R) = P[R + 1] - P[L]
    int L = 2, R = 4;
    int rangeSum = P[R + 1] - P[L]; // P[5] - P[2] -> 15 - 5 = 10
    
    std::cout << "Sum from index " << L << " to " << R << " is: " << rangeSum << std::endl;
    
    return 0;
}
```