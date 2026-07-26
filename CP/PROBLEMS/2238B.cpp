/*
After summoning the next boss — The Brain of Cthulhu, you noticed that it surrounds itself with n
 eyes, numbered from 1
 to n
. In one attack, The Brain of Cthulhu chooses a triple of eyes (not necessarily distinct) with numbers (a,b,c)
. The triple of eyes is called crimson if and only if the following property holds:

gcd
∗
(lcm
†
(a,b),lcm(b,c))=gcd(a,c)
,
To defeat the boss, you want to know how many ways The Brain of Cthulhu can choose a crimson triple of eyes. The triples of eyes (a1,b1,c1)
 and (a2,b2,c2)
 are considered different if a1≠a2
, or b1≠b2
, or c1≠c2
.

∗
gcd(x,y)
 denotes the greatest common divisor (GCD) of integers x
 and y
.

†
lcm(x,y)
 denotes the least common multiple (LCM) of integers x
 and y
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤1000
). The description of the test cases follows.

The only line of each test case contains one integer n
 (1≤n≤2⋅105
) — the number of eyes of The Brain of Cthulhu.

It is guaranteed that the sum of n
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output one integer — the number of ways to choose a crimson triple of eyes.

Example
InputCopy
3
1
2
20
OutputCopy
1
5
612
Note
In the first test case, there is 1
 possible crimson triple: (1,1,1)
.

In the second test case, there are 5
 possible crimson triples: (1,1,1)
, (1,1,2)
, (2,1,1)
, (2,1,2)
, (2,2,2)
.



*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long ans = 0;

        for (int i = 1; i <= n; i++) {
            int64 k = n / i;
            ans += k * k;
        }

        cout << ans << '\n';
    }

    return 0;
}