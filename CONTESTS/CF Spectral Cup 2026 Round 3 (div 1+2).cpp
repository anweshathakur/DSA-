/*
======================================================================
Spectral::Cup 2026 Round 3 (Codeforces Round 1110, Div. 1 + Div. 2)
======================================================================
*/

/*
===========================================
Problem : 1 , A. Who Watches the Watchpig?
===========================================
There are n
 piggies standing in a line, numbered from 1
 to n
 from left to right. Each piggy is either facing left or right.

Two piggies x
 and y
 are called a watchpig pair if x<y
, x
 is facing right, and y
 is facing left.

You are given an integer k
 such that 1≤k<n
. A piggy is called safe if it belongs to at least k
 watchpig pairs.

Your task is to make all piggies safe. To achieve this, you can choose any number of piggies and flip their directions (changing left to right or vice versa).

Compute the minimum number of piggies you need to turn around so that every piggy becomes safe, or report that it is impossible to do so.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤500
). The description of the test cases follows.

The first line of each test case contains two integers n
 and k
 (1≤k<n≤100
), representing the number of piggies and the number of watchpig pairs a piggy needs to belong to, respectively.

The second line contains a string s
 of length n
 consisting only of the characters L
 and R
. For every 1≤i≤n
, if si=L
, piggy i
 is facing left; otherwise, if si=R
, piggy i
 is facing right.

Output
For each test case, if it is impossible to make every piggy safe, output −1
. Otherwise, output the minimum number of piggies you need to turn around so that every piggy becomes safe.

Example
InputCopy
4
3 1
LLL
4 3
LRLR
6 2
RLLRRL
12 4
LRLLRRLRLRLR
OutputCopy
1
-1
2
5
Note
In the first test case, one optimal solution is to turn piggy 1
 around. Both piggy 1
 and piggy 3
 now belong to the watchpig pair (1,3)
, and piggy 2
 belongs to the watchpig pair (1,2)
. Every piggy belongs to at least k=1
 watchpig pairs, hence every piggy is safe.

In the second test case, it can be proven that it is impossible to make every piggy safe.

In the third test case, one optimal solution is to turn piggies 2
 and 5
 around. For example, piggy 2
 is now safe, as it belongs to both (2,3)
 and (2,5)
. Piggy 4
 is also safe, as it belongs to both (4,5)
 and (4,6)
. The rest of the piggies are all safe.
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, const string& s) {
    if (n < 2 * k) {
        return -1;
    }
    int flips = 0;

    for (int i = 0; i < k; i++) {
        if (s[i] != 'R') {
            flips++;
        }
    }

    for (int i = n - k; i < n; i++) {
        if (s[i] != 'L') {
            flips++;
        }
    }
    return flips;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            int n, k;
            cin >> n >> k;
            string s;
            cin >> s;
            cout << solve(n, k, s) << "\n";
        }
    }
    return 0;
}
/*
======================================
Problem : 2 , Delete and Concatenate
======================================
You are given an array a
 of n
 integers. Your initial score is 0
.

You can perform the following two types of operations any number of times until the array becomes empty:

Choose a single element. Add its value to your score, and remove it from the array.
Choose two adjacent elements. Add the maximum of their values to your score, and remove both elements from the array. (This operation requires the array to have at least 2
 elements.)
After each operation, the remaining elements are concatenated without changing their relative order.

You are also given an integer c
, which represents the cost of performing one operation. Every time you perform an operation (regardless of the type), c
 is subtracted from your score.

Compute the maximum possible final score you can achieve.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains two integers n
 and c
 (1≤n≤2⋅105
, 0≤c≤109
), representing the length of a
 and the cost of performing one operation, respectively.

The second line contains n
 integers a1,a2,…,an
 (−109≤ai≤109
), representing the elements of a
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output an integer representing the maximum possible score you can achieve.

Example
InputCopy
5
1 0
-1
3 0
1 3 1
3 2
1 3 1
6 6
3 1 4 1 5 9
4 1000000000
-1000000000 -1000000000 -1000000000 -1000000000
OutputCopy
-1
5
0
0
-4000000000
Note
In the first test case, your only possible choice is to perform the first operation once. Your score is a1−c=−1−0=−1
.

In the second test case, one optimal sequence of operations is:

Choose 3
. Your score becomes 0+3−0=3
, and the array becomes [1,1]
.
Choose the first 1
. Your score becomes 3+1−0=4
, and the array becomes [1]
.
Choose 1
. Your score becomes 4+1−0=5
, and the array becomes empty.
In the third test case, one optimal sequence of operations is:

Choose 3
 and the second 1
. Your score becomes 0+max(3,1)−2=1
, and the array becomes [1]
.
Choose 1
. Your score becomes 1+1−2=0
, and the array becomes empty.


*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int64 NEG = -(1LL << 60);

void solve() {
    int n;
    int64 c;
    cin >> n >> c;
    vector<int64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int64> dp(n + 1, NEG);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 1] + a[i - 1] - c);

        if (i >= 2) {
            dp[i] = max(dp[i], dp[i - 2] + max(a[i - 1], a[i - 2]) - c);
        }
    }

    cout << dp[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}