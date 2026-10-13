/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/
#include <bits/stdc++.h>
#include <unordered_map>
class Solution {
public:
    bool isAnagram(std:: string s, std :: string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, int>charCount;
        for (char c : s) {
            charCount[c]++;
        }

        for (char c : t) {
            if (charCount.find(c) == charCount.end() || charCount[c] == 0) {
                return false;
            }
            charCount[c]--;
        }

        return true;
    }
};