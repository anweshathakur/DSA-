/*
=============================================
LC 187. Repeated DNA Sequences
=============================================
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.
*/
#include <bits/stdc++.h>
#include <vector>
#include <string>
class Solution {
public:
    std :: vector<std :: string> findRepeatedDnaSequences(std :: string s) {
         std :: vector<std :: string> ans;
         std :: unordered_map<std :: string,int>mpp;

         int n=s.length();

         if (n<10) return ans;

          for(int i=0;i<=n-10;i++){
            std :: string sub=s.substr(i,10);
            mpp[sub]++;
          }
          
          for(auto it:mpp){
            if(it.second>1){
                ans.push_back(it.first);
            }
          }
          return ans;
        }

};