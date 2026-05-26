// Count the number of Special Characters in a String

/*
You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

Return the number of special letters in word.

 

Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters in word are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

No character in word appears in uppercase.

Example 3:

Input: word = "abBCab"

Output: 1

Explanation:

The only special character in word is 'b'.

 

Constraints:

1 <= word.length <= 50
word consists of only lowercase and uppercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int specCount = 0; 
        unordered_set<char> counted;
        for (int i = 0; i < word.length(); i++) {
            for (int j = 0; j < word.length(); j++) {
                if (islower(word[i]) && word[j] == toupper(word[i])) {
                    if (counted.find(word[i]) == counted.end()) {
                        specCount++; 
                        counted.insert(word[i]); // Mark this letter as counted
                    }
                }
                
            }
        }
        return specCount; 
    }
};

/*
This problem can also be approached by bitmasking and hashing ; 
*/