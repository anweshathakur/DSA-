/*
=============================
LC 49 Group Anagrams
=============================
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/
#include <bits/stdc++.h>
class Solution {
public:
    std :: vector<std :: vector<std :: string>> groupAnagrams(std :: vector<std :: string>& strs) {
        std :: unordered_map<std :: string, std :: vector<std :: string>> mp;
        for (std  :: string s : strs) {
            std :: string key = s;
            std :: sort(key.begin(), key.end()); 
            
            mp[key].push_back(s); 
        }
        
        std :: vector<std :: vector<std :: string>> ans;
        for (auto& pair : mp) {
            ans.push_back(pair.second); 
        }
        
        return ans;
    }
};