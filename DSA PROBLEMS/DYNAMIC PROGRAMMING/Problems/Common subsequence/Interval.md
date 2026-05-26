# Interval DP (or sometimes Matrix DP / Substring DP).
The defining feature of Interval DP is that you are evaluating the optimal solution for a contiguous segment or "window" of a single sequence (like a string or an array) from a starting index $i$ to an ending index $j$.

---

## How to recognize Interval DP instantly:
The State is a Window: 
Your DP table is almost always 2D: 
dp[i][j], where i is the start of the window and j is the end of the window.Dependent on Smaller Sub-intervals:


---


## Solve
To solve the window [i, j], you must first know the answer to a smaller window inside it (like [i+1, j-1], [i+1, j], or [i, j-1]).
The Loop Order: Instead of looping through items from 0 to n, you usually loop by the length of the interval (starting with length 1, then length 2, then length 3, etc.), because larger windows depend on the smaller windows already being solved.

---


## examples : 
substrings
palindromes within a single string
merging/bursting elements next to each other

# Longest Common Subsequence 

### Types :

1. Largest Common Substring 
2. Print LCS
3. Shortest Common supersequence 
4. Print  SCS 
5. Min # of insertion and Deletion a -> b 
6. Largest Repeating subsequences 
7. lenght of largest subsequence of a substring
8. subsequnce for pattern matching 
9. count the number of times a appears as a substring 
10. Largest palindrome subsequence 
11. Largest Palindromic substring
12. Count of palindromic substring 
13. min # of a deletion in a strting to make it palindrome 
14. min # insertions in a string to make it palindrome

---

recursive -> memorization -> top - down 