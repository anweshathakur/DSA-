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
merging/bursting elements next to each other, 