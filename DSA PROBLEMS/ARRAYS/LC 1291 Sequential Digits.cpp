
/*
===================================
LC 1291 Sequential Digits
===================================
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9
*/
#include <bits/stdc++.h>

class Solution {
public:
    std :: vector<int> sequentialDigits(int low, int high) {
        std :: vector<int> ans;
        std :: string digits = "123456789";

        int lowLen = std :: to_string(low).length();
        int highLen = std :: to_string(high).length();

        for (int len = lowLen; len <= highLen; len++) {
            for (int start = 0; start + len <= 9; start++) {
                int num = stoi(digits.substr(start, len));

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};