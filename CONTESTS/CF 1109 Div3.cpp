//-----------------------------Codeforces Round 1103 (Div. 3)----------------------------------------------------
/*
A. 
During a geometry lesson, Iskander got very bored, so he decided to draw in Yura's notebook. To do this, he took a row and drew horizontal lines on it. Some lines are long, some are short, and some parts of the page remain empty.

The page is represented by a string s
, where the character '*' denotes an empty part of the paper, and the character '#' denotes one centimeter of a drawn line. A continuous sequence of '#' characters forms a single line.

Yura decided to erase all the lines and made Iskander help him: they will erase one of the lines from both ends simultaneously.

Each second, Iskander erases 1
 centimeter from the right end of the line, and Yura erases 1
 centimeter from the left end.
If the current length of the line is 1
 or 2
 centimeters, then in the next second it is erased completely, and the process ends.
Yura wants to choose a line so that, together with Iskander, they erase it for as long as possible. Help him determine this maximum time. If there are no lines on the page, the answer is 0
 seconds.

Input
The first line contains a single integer t
 (1≤t≤2500
) — the number of test cases.

The first line of each test case contains an integer n
 (1≤n≤10
) — the length of the string s
.

The second line of each test case contains a string s
 of length n
, consisting of characters '#' and '*'.

Output
For each test case, output a single integer — the maximum time required to erase a line.

Example
InputCopy
5
7
#*##*##
8
########
8
********
8
#*****##
6
*#####
OutputCopy
1
4
0
1
3



*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n ; 
    cin >> n ; 
    string s ;
    cin >> s ; 
    

    int mx = 0;
    int cnt = 0;
    for (char c : s) {
        if (c == '#')
            cnt++;
        else {
            mx = max(mx, cnt);
            cnt = 0;
        }
    }
    mx = max(mx, cnt);  

    cout << (mx + 1) / 2 << '\n';
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
As is well known, Nikita loves reading. Today, he made a mess in his room and arranged his books into n
 stacks in a row, numbered from 1
 to n
 from left to right. The i
-th stack contains ai
 books. This arrangement is called neat if, in every stack except the rightmost one, the number of books is strictly less than in the stack to its right; that is, the array a
 is strictly increasing.

Yura wants to make the arrangement neat by performing the following operation any number of times:

Choose a stack i
 such that 1≤i<n
 and ai>1
.
Take 1
 book from the top of stack i
, so ai
 decreases by 1
.
Put this book on top of stack i+1
, so ai+1
 increases by 1
.
Determine whether Yura can make the arrangement neat.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
) — the number of stacks.

The second line of each test case contains n
 integers ai
 (1≤ai≤109
) — the initial number of books in each stack.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output "YES" if Yura can make the arrangement neat, and "NO" otherwise.

You may output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted.

Example
InputCopy
7
3
1 2 3
3
1 1 2
3
10 1 1
3
2 2 2
4
1 4 2 2
5
8 2 8 1 8
4
1 1 3 5
OutputCopy
YES
NO
YES
YES
NO
YES
NO
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n ;
    cin >> n ;
    vector<long long> a(n);
    for (int i = 0 ; i < n ; i++){ 
        cin >> a[i] ;
    }
    long long need = 1;

    for (int i = 0; i < n; i++) {
        if (a[i] < need) {
            cout << "NO\n";
            return;
        }

    long long extra = a[i] - need;
    if (i + 1 < n) a[i + 1] += extra;

    need++;
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
