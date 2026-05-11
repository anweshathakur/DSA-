//-----------------------------Codeforces Round 1090 (Div. 4)----------------------------------------------------
/*
A. The 67th Integer Problem
Welcome to the New World, O Esteemed Earthly Visitor. You've been summoned by Macaque, a primate with four legs, a god complex and a terminal addiction to the word "trivial". You are Undertaking a Journey of Great Importance. Such Incredible Importance. No Journey Will EVER be as IMPORTANT as this one (and nothing this narrator says will sound so distinctly... orange again). You are implored to cooperate with Macaque, for his wrath (and joblessness) are unending. There is no room for error or incompetence. Lousiness shall be met with the full force of the law.

Macaque is given an integer x
. Your task is to choose an integer y
 such that the value of min(x,y)
∗
 is maximized.
If there are multiple valid y
, you may output any of them.
∗
min(x,y)
 is defined as the minimum of integers x
 and y
.
Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤6767
). The description of the test cases follows.

The only line of each test case contains a single integer x
 (−67≤x≤67
).
Output
For each test case, output one integer y
 (−67≤y≤67
) such that min(x,y)
 is maximized.

Example
Input
3
1
3
5
Output
2
4
6
Note
In the first case, 2
 is a possible answer because min(1,2)=1
, which can be shown to be maximal.
*/
#if 0
#include <iostream>
using namespace std;
int solve(int x) {
    if (x < 67) {
        return x + 1;
    } else {
        return x;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}
#endif
/*
So, Macaque has passed his first challenge (and is not acknowledging your help whatsoever). After all, it was only given to him so he could engage in his greatest pleasure — crunching on desiccated freezedried hamburgers and yelling 'trivial' at the screen. However, he has another, much more important task ahead of him, and he has once again enlisted you to help him.

You are given 7
 integers a1,a2,…,a7
.

You must negate 6
 out of the 7
 integers (that is, multiply them by −1
). Over all possible ways to negate 6
 out of the 7
 integers, find the maximum possible sum of a
.
Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤6767
). The description of the test cases follows.

The first and only line of each test case contains 7
 space-separated integers a1,a2,…,a7
 (−67≤ai≤67
).
Output
For each test case, output the maximum sum of a
 after negating 6
 out of the 7
 integers, on a new line.

Example
Input
4
41 41 41 41 41 41 41
6 9 4 20 6 7 67
1 2 3 4 5 6 7
6 7 6 7 6 7 6
Output
-205
15
-14
-31
*/
#if 0
#include <iostream>
using namespace std;
int solve(int a[]) {
    int total_sum = 0;
    int max_val = a[0];
    int max_idx = 0;

    for (int i = 0; i < 7; i++) {
        total_sum += a[i];
        if (a[i] > max_val) {
            max_val = a[i];
            max_idx = i;
        }
    }
    return 2 * max_val - total_sum;
}
int main (){
    int t;
    cin >> t;
    while (t--) {
        int a[7];
        for (int i = 0; i < 7; i++) {
            cin >> a[i];
        }
        cout << solve(a) << endl;   
    }
    return 0;
}
#endif
/*
Upon arriving at school, Macaque was rather brusquely greeted by his friend, AG-88301, the latter having skived off his homework due to spending the entire night yapping to an unsuspecting stranger about his groundbreaking work on a proof of the Collatz conjecture and his 67
-th unreciprocated love interest. So, as had become customary, AG-88301, with ever decreasing levels of gratitude or appreciation, made Macaque do his homework for him. At this point, Macaque had had enough, and turned to his minions (you guys!) to solve AG-88301's homework task.

You are given an integer n
. You must construct a permutation∗
 of length 3n
 such that, if you partition the permutation into n
 contiguous blocks with 3
 elements, the sum of the medians†
 of these blocks is maximised.

More formally, you must construct a permutation p
 of length 3n
 such that ∑n−1i=0median(a3i+1,a3i+2,a3i+3)
 is maximised. If there are multiple possible p
, output any.

∗
A permutation of length n
 is an array consisting of n
 distinct integers from 1
 to n
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (n=3
 but there is 4
 in the array).

†
The median of an array b
 containing 3
 elements is the 2
-nd element after b
 is sorted in non-decreasing order.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first and only line of each test case contains an integer n
 (1≤n≤105
).

It is guaranteed that the sum of 3n
 does not exceed 3⋅105
 over all test cases.

Output
For each test case, output a permutation p
 such that the sum of the medians of the contiguous blocks is maximised. If there are multiple possible p
, output any.

Example
InputCopy
3
2
1
3
OutputCopy
1 3 4 2 5 6 
3 1 2
5 2 4 8 3 9 7 1 6
Note
In the first test case, [1,3,4,2,5,6]
 is a possible answer because median(1,3,4)+median(2,5,6)=3+5=8
, and it can be shown that 8
 is the maximal possible sum of medians.
In the second test case, [3,1,2]
 is a possible answer because the only achievable sum of medians when n=1
 is 2
.
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> solve(int n) {
    vector<int> result(3 * n);
    int idx = 0;
    for (int i = 1; i <= 3 * n; i += 3) {
        result[idx++] = i + 1; 
        result[idx++] = i;     
        result[idx++] = i + 2; 
    }
    return result;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> result = solve(n);
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

