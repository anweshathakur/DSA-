# 4A Watermelon


### Problem

https://codeforces.com/problemset/problem/4/A

the Problem simply asks if or not 'w' can be  written as a sum of two even numbers.
---
### Thought
- sum of two even numbers is always even , hence w should also be even only.
- the only case w is  even and cannot be expressed as a sum of even numbers is the number 2.

- So to return 'YES' (w%2 = 0 && w > 2) 
---

### Code
just take the input and check for the condition

```cpp
#include <iostream>
using namespace std;
int main() {
    int w;
    cin >> w;
    if (w % 2 == 0 && w > 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
```