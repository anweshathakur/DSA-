//-----------------------------Codeforces Round 1103 (Div. 3)----------------------------------------------------
/*
A. Dabir, Egor, and Arseniy just got on the train and decided to play a game. Dabir has a backpack with an infinite number of cubes. He built n
 towers from them, where the i
-th tower has height hi
 cubes.

Egor and Arseniy must choose an integer xi
 for each tower i
 and increase its height by xi
 exactly once. For example, if h
 = [1,3,2,2
], x
 = [3,2,2,8
], then after increasing h
 it will become [4,5,4,10
]. Their goal is to make the heights of all towers equal.

To make the game more interesting, Dabir wants to choose an integer k
 and add a restriction: each xi
 must satisfy 1≤xi≤k
. Help him find the smallest k
 for which it is possible to finish the game.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

Then t
 test cases follow.

The first line of each test case contains a single integer n
 (1≤n≤5
).

The second line contains n
 integers h1,h2,…,hn
 (1≤hi≤6
).

Output
For each test case, output a single integer — the minimum value of k
 such that it is possible to make all towers have equal height.

Example
InputCopy
4
2
1 3
3
2 6 4
5
5 4 6 6 1
4
3 3 3 3
OutputCopy
3
5
6
1

33

*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int mn = INT_MAX, mx = INT_MIN;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }

    cout << mx - mn + 1 << "\n";
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


/*
B.
During the holidays, Egor came to visit his friend Dabir in the city of Kazan. Out of boredom, Dabir and Egor came up with a new business idea: to make their own TV show.

The format of the show is very simple: in each episode they invite a guest and play a game with them on a binary string.

In today's episode, Egor and Dabir invited Arseniy (aka MAKAN) — the main celebrity of Omsk. For the game, they chose a binary string s
 of length n
 and an integer k
.

Arseniy can make an unlimited number of moves. In one move, he can choose an integer i
 (1≤i≤n−k
) and invert the characters at positions i
 and i+k
, that is, change 0
 to 1
 and 1
 to 0
.

For example, if s=10110
 and k=2
, then by choosing i=2
, Arseniy inverts the characters at positions 2
 and 4
: [10110→11100]

Arseniy wants to get the main prize — 1000000
 tugriks. To do this, he needs to make the entire string s
 equal to zero.

Help Arseniy determine whether he can get his prize, or if he will have to return to Omsk with nothing.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains two integers n
 and k
 (1≤k≤n≤2⋅105
).

The second line of each test case contains a binary string s
 of length n
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output "YES" if Arseniy can make the string entirely zero, and "NO" otherwise.

You can output "YES" and "NO" in any case (for example, "yES", "yes", and "Yes" will be accepted).

Example
InputCopy
5
4 2
1010
3 2
111
3 3
111
3 1
110
1 1
1
OutputCopy
YES
NO
NO
YES
NO

*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for (int start = 0; start < k; start++) {
        int ones = 0;

        for (int i = start; i < n; i += k) {
            if (s[i] == '1') {
                ones++;
            }
        }

        if (ones % 2) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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

/*
C.
An annual programmers fair is taking place on the main square of Omsk. You, as the main programmer of Omsk, decided to take part in this wonderful event and went there. At the entrance, a guard decided to check your skills and gave you a problem:

You are given three integers a
, b
, x
. You want to make a
 and b
 equal. In order to do so, you can apply the following operations:

Choose one of the integers a
 or b
 and add 1
 to it.
Choose one of the integers a
 or b
 and divide it by x
 with rounding down.
You need to find the minimum number of operations after which a
 becomes equal to b
. Can you prove your skills, or will you have to go back home?

Input
The first line contains a single integer t
 (1≤t≤104)
 — the number of test cases.

Then t
 test cases follow.

Each test case consists of a single line containing three integers a
, b
, x
 (1≤a,b≤109
, 2≤x≤109
).

Output
For each test case, output a single integer — the minimum number of operations required to make a
 and b
 equal.

Example
InputCopy
7
1 2 3
2 3 2
7 3 10
17 3 3
10 10 2
4 7 2
1 6 2
OutputCopy
1
1
2
3
0
2
2
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, x;
    cin >> a >> b >> x;
    
    vector<int> va, vb;
    va.push_back(a);
    while (a > 0) {
        a /= x;
        va.push_back(a);
    }
    
    vb.push_back(b);
    while (b > 0) {
        b /= x;
        vb.push_back(b);
    }
    
    int ans = 2e9;
    for (int i = 0; i < va.size(); i++) {
        for (int j = 0; j < vb.size(); j++) {
            ans = min(ans, i + j + abs(va[i] - vb[j]));
        }
    }
    
    cout << ans << "\n";
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

/*
D.Dabir and Egor were not satisfied with the fame from the previous episode, so they decided to make another TV show: the guys play their favorite game on an array a
 with their favorite integer k
.

Dabir moves first. On the first move, any element from the array can be chosen and removed. Let the previous chosen element be equal to x
. Then on the current move, except the very first one, a player must choose an element y
 from the array such that 0≤y−x≤k
 and remove it from the array. The player who cannot make a move loses.

But since this was not just a game, but a real show-match, Arseniy (aka MAKAN) — the main celebrity of Omsk was invited again. As a guest celebrity, Arseniy was given the opportunity to make the first move in this match, that is, to make the very first move in the game instead of Dabir. However, it turns out Arseniy is a fan of Egor, so he wants his first move to guarantee Egor a winning strategy against any response from Dabir.

Determine whether Arseniy can make the first move for Dabir so that, no matter how Dabir plays, Egor wins.

Input
Each test consists of multiple test cases. The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains two integers n
 and k
 (1≤n,k≤2⋅105
) — the length of the array and the favorite integer of Dabir and Egor.

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤n
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, if there exists such a first move that with optimal play by both players Egor wins, output "YES", otherwise output "NO".

You can output "YES" and "NO" in any case (for example, "yES", "yes", and "Yes" will be accepted).

Example
InputCopy
7
5 1
3 3 3 3 3
3 1
1 1 2
2 2
2 1
4 1
3 3 3 3
4 3
2 2 2 1
4 1
1 3 1 1
5 1
5 1 5 1 5
OutputCopy
NO
YES
YES
YES
YES
NO
YES
Note
In the first example, the only possible option is to choose the integer 3
. After that, the array [3,3,3,3
] remains. Then Egor moves, then Dabir, and so on. Dabir will take the last 3
, so Arseniy cannot choose a first move that makes Egor win.

In the second example, Arseniy can choose the integer 1
 as the first move. Then Egor will choose the integer 2
, and Dabir will have no valid moves left, so Egor wins.
*/
#include <bits/stdc++.h>
using namespace std;

void solve (){

}

int main (){

}
