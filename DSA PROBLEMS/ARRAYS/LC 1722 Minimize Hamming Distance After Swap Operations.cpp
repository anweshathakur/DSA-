/*
--- EDITORIAL ---
Intuition:
The key insight is that if you can swap index a with b, and b with c, you can essentially move any element from index a, b, or c to any of these positions. This forms connected components of indices. Within each component, you can rearrange the elements in any way you want. To minimize the Hamming distance, you should match as many elements as possible from the source with the target within each component.

Approach:
1. Use Disjoint Set Union (DSU) to group indices into connected components based on allowedSwaps.
2. For each component, count the frequency of each element in the source at those indices.
3. Iterate through the same indices in the target and check if the element exists in the frequency map of the source. If it does, it's a match.
4. Total matches = sum of matches in all components.
5. Minimum Hamming distance = Total elements - Total matches.

Complexity:
- Time: O((N + S) α(N))
- Space: O(N)
-----------------

PROBLEM STATEMENT:
You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.

The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).

Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.

 

Example 1:

Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
Output: 1
Explanation: source can be transformed the following way:
- Swap indices 0 and 1: source = [2,1,3,4]
- Swap indices 2 and 3: source = [2,1,4,3]
The Hamming distance of source and target is 1 as they differ in 1 position: index 3.
Example 2:

Input: source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
Output: 2
Explanation: There are no allowed swaps.
The Hamming distance of source and target is 2 as they differ in 2 positions: index 1 and index 2.
Example 3:

Input: source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
Output: 0
 

Constraints:

n == source.length == target.length
1 <= n <= 105
1 <= source[i], target[i] <= 105
0 <= allowedSwaps.length <= 105
allowedSwaps[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
*/
#include <bits/stdc++.h>

class Solution {
    std::vector<int> parent;
    int find(int i) {
        return parent[i] == i ? i : parent[i] = find(parent[i]);
    }
    
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }

public:
    int minimumHammingDistance(std::vector<int>& source, std::vector<int>& target, std::vector<std::vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for (auto& s : allowedSwaps) {
            unite(s[0], s[1]);
        }
        std::unordered_map<int, std::vector<int>> components;
        for (int i = 0; i < n; i++) {
            components[find(i)].push_back(i);
        }
        
        int totalMatches = 0;
        
        for (auto& p : components) {
            int root = p.first;
            auto& indices = p.second;
            std::unordered_map<int, int> sourceCounts;
            for (int idx : indices) {
                sourceCounts[source[idx]]++;
            }
            
            for (int idx : indices) {
                if (sourceCounts[target[idx]] > 0) {
                    totalMatches++;
                    sourceCounts[target[idx]]--;
                }
            }
        }
        
        return n - totalMatches;
    }
};