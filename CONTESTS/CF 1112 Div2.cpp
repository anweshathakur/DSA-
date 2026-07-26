// CF 1112 Div2.cpp : 

// =============================================================================
// Problem 1: 
// =============================================================================
/*
There are n+2
 positions numbered from 0
 to n+1
. Initially, position i
 contains an element of weight wi
 for every 1≤i≤n
, while positions 0
 and n+1
 are empty.

You choose an integer k
. Then every element moves exactly once, simultaneously:

If wi<k
, the element at position i
 moves to position i−1
;
If wi>k
, the element at position i
 moves to position i+1
;
If wi=k
, the entire movement process fails immediately.
An integer k
 is perfect if the movement does not fail and, upon completion, every position from 1
 to n
 contains exactly one element.

Determine whether a perfect integer k
 exists.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤500
). The description of the test cases follows.

The first line of each test case contains one integer n
 (1≤n≤100
).

The second line of each test case contains n
 integers w1,w2,…,wn
 (1≤wi≤109
).

Output
For each test case, print "YES" if a perfect integer k
 exists, and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
6
1
7
2
3 1
2
2 1
4
9 1 7 2
4
9 8 7 1
6
1000000000 1 9 2 8 3
OutputCopy
NO
YES
NO
YES
NO
YES
Note
In the first test case, the only element either leaves position 1
 or has weight equal to k
, so no suitable integer exists.

In the second test case, choose k=2
. The element of weight 3
 moves right and the element of weight 1
 moves left, leaving one element in each position.

In the third test case, keeping both positions occupied would require 1<k<2
, which is impossible for an integer k
.

In the fourth test case, k=5
 is suitable: the elements at positions 1
 and 3
 move right, while those at positions 2
 and 4
 move left. Upon completion, every position from 1
 to 4
 contains exactly one element.

In the fifth test case, the element at position 2
 must move left, requiring k>8
, while the element at position 3
 must move right, requiring k<7
. These requirements are incompatible.

In the sixth test case, choose k=4
. All elements at odd positions move right and all elements at even positions move left, so every position from 1
 to 6
 contains one element afterwards.

 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    int min_odd = 2e9;   
    int max_even = -2e9; 
    
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        if (i % 2 == 0) {
            min_odd = min(min_odd, w[i]);
        } else {
            max_even = max(max_even, w[i]);
        }
    }
    if (n % 2 != 0) {
        cout << "NO\n";
        return;
    }
    if (max_even < min_odd - 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// =============================================================================
// Problem 2
// =============================================================================
/*
You are given two integers n
 and k
.

Construct a binary string∗
 s
 of length n
, such that both of the following conditions hold:

The absolute difference between the number of characters 0
 and the number of characters 1
 in s
 is at most 1
.
There are exactly k
 pairs of adjacent equal characters in s
. Formally, there are exactly k
 indices i
 (1≤i≤n−1
) satisfying si=si+1
.
Or determine that no such string exists.

∗
A binary string is a string where each character is either 0
 or 1
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤1000
). The description of the test cases follows.

The only line of each test case contains two integers n
 and k
 (2≤n≤2⋅105
, 0≤k≤n−1
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a binary string s
 of length n
 — the string you constructed. Print −1
 if such a string does not exist.

If there are multiple answers, you may output any of them.

Example
InputCopy
8
5 2
4 3
6 1
5 0
7 3
4 2
3 2
7 4
OutputCopy
01110
-1
101001
01010
0100011
0011
-1
0111000
Note
In the first test case, one possible answer is s=01110
. It contains three characters 1
 and two characters 0
, and there are exactly 2
 adjacent equal pairs in s
: (s2,s3)
 and (s3,s4)
.

In the second test case, k=n−1
. All characters in s
 should be equal, so the numbers of characters 0
 and 1
 could not differ by at most 1
. Thus, the answer is −1
.

In the third test case, note that 010110
 is also a possible answer.

*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k == n - 1) {
        cout << -1 << '\n';
        return;
    }

    int cont = n - k;

    int zeros = (n + 1) / 2;
    int ones  = n / 2;

    int zero_conti = (cont + 1) / 2;
    int one_conti  = cont / 2;

    int extraZeros = zeros - zero_conti;
    int extraOnes  = ones - one_conti;

    string s;
    s.append(extraZeros + 1, '0');
    s.append(extraOnes + 1, '1');
    for (int i = 3; i <= cont; i++) {
        if (i % 2 == 1) {
            s.push_back('0');
        }
        else {
            s.push_back('1');
        }
    }

    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}