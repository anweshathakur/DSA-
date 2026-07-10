/*
================================
LC 567 : Permutation in String
================================
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/
#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) return false;

        // Frequency arrays for lowercase English letters (initialized to 0)
        std::vector<int> s1_count(26, 0);
        std::vector<int> window_count(26, 0);

        for (int i = 0; i < n1; i++) {
            s1_count[s1[i] - 'a']++;
            window_count[s2[i] - 'a']++;
        }
        if (s1_count == window_count) return true;
        for (int i = n1; i < n2; i++) {
            window_count[s2[i] - 'a']++;
            window_count[s2[i - n1] - 'a']--;

            
            if (s1_count == window_count) {
                return true;
            }
        }

        return false;
    }
};