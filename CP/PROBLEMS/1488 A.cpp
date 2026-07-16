/*
You are given two positive (greater than zero) integers x
 and y
. There is a variable k
 initially set to 0
.

You can perform the following two types of operations:

add 1
 to k
 (i. e. assign k:=k+1
);
add x⋅10p
 to k
 for some non-negative p
 (i. e. assign k:=k+x⋅10p
 for some p≥0
).
Find the minimum number of operations described above to set the value of k
 to y
.

Input
The first line contains one integer t
 (1≤t≤2⋅104
) — the number of test cases.

Each test case consists of one line containing two integer x
 and y
 (1≤x,y≤109
).

Output
For each test case, print one integer — the minimum number of operations to set the value of k
 to y
.

Example
InputCopy
3
2 7
3 42
25 1337
OutputCopy
4
5
20
Note
In the first test case you can use the following sequence of operations:

add 1
;
add 2⋅100=2
;
add 2⋅100=2
;
add 2⋅100=2
.
1+2+2+2=7
.
In the second test case you can use the following sequence of operations:

add 3⋅101=30
;
add 3⋅100=3
;
add 3⋅100=3
;
add 3⋅100=3
;
add 3⋅100=3
.
30+3+3+3+3=42
.


*/
#include <bits/stdc++.h>
using namespace std;

long long dp[12][100];

void solve() {
    long long x, y;
    cin >> x >> y;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = 1e18;
        }
    }

    dp[0][0] = 0;

    for (int pos = 0; pos < 10; pos++) {
        int d = (y / (long long)pow(10, pos)) % 10;
        int xd = (x / (long long)pow(10, pos)) % 10;

        for (int carry = 0; carry < 100; carry++) {
            if (dp[pos][carry] == 1e18) continue;

            for (int cnt = 0; cnt <= 20; cnt++) {
                long long cur = carry + 1LL * cnt * xd;

                if (cur % 10 != d) continue;

                int ncarry = cur / 10;

                dp[pos + 1][ncarry] =
                    min(dp[pos + 1][ncarry],
                        dp[pos][carry] + cnt);
            }
        }
    }

    cout << dp[10][0] << "\n";
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