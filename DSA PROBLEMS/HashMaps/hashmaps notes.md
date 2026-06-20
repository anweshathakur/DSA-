# Hash Maps

## Why Hash Maps?

Suppose we have:

```cpp
string s = "abcdabcdaabbccc";
```

Typical questions:

* Find the maximum occurring character.
* Count frequency of words.
* Store key-value pairs efficiently.

Hash Maps are used when we need:

```text
Key -> Value
```

Example:

```cpp
"Alice" -> 95
"Bob"   -> 87
"Cat"   -> 3
```

---

# Internal Implementation

Hash Maps are generally implemented using:

```text
Bucket Array + Hash Function + Collision Handling
```

In C++:

```cpp
map<Key, Value>
unordered_map<Key, Value>
```

---

# map vs unordered_map

| Feature        | map            | unordered_map |
| -------------- | -------------- | ------------- |
| Implementation | Red Black Tree | Hash Table    |
| Order          | Sorted         | Unordered     |
| Insert         | O(log n)       | O(1) average  |
| Search         | O(log n)       | O(1) average  |
| Delete         | O(log n)       | O(1) average  |

---

# STL Usage

```cpp
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    map<string, int> m;

    // insertion

    pair<string, int> p = make_pair("anwhee", 19);
    m.insert(p);

    pair<string, int> p2("Abhi", 12);
    m.insert(p2);

    m["Ked"] = 20;

    // update

    m["anwhee"] = 20;

    // access

    cout << m["anwhee"] << endl;
    cout << m.at("Abhi") << endl;

    // size

    cout << m.size() << endl;

    // count

    cout << m.count("anwesha") << endl;

    // erase

    m.erase("anwhee");

    // traversal

    map<string, int>::iterator it = m.begin();

    while(it != m.end()) {
        cout << it->first << " "
             << it->second << endl;
        it++;
    }
}
```

---

# Bucket Array

Think of an array:

```text
Index : 0 1 2 3 4 5 6 7
Value : _ _ _ _ _ _ _ _
```

Keys are converted into indices.

Example:

```cpp
"Alice" -> 5
"Bob"   -> 2
"Cat"   -> 7
```

The process:

```text
Key
 ↓
Hash Function
 ↓
Hash Code (Integer)
 ↓
Compression Function
 ↓
Bucket Index
```

---

# Hash Function

Converts a key into an integer.

Example:

```cpp
123 -> 123
```

For strings:

```cpp
"abc"
```

may become

```text
97 + 98 + 99 = 294
```

(Conceptually; actual STL uses better methods.)

---

# Compression Function

Hash code may be huge:

```text
29483927492
```

Need an index within bucket range.

Example:

```cpp
index = hashCode % bucketCount
```

If:

```cpp
bucketCount = 10
```

then

```cpp
29483927492 % 10 = 2
```

Store at bucket 2.

---

# Collision

Collision occurs when multiple keys map to the same bucket.

Example:

```text
abc
bca
cab
cba
bac
acb
```

If hash code = sum of ASCII values:

```text
97 + 98 + 99 = 294
```

All produce the same hash code.

Therefore:

```text
Same bucket
```

This is called a collision.

---

# Collision Handling

## 1. Separate Chaining (Open Hashing)

Store all collided keys in a linked list.

Example:

```text
Bucket 5

Head
 ↓
key1 -> key2 -> key3
```

Visualization:

```text
Bucket Array

0
1
2
3
4
5 ----> key1 -> key2 -> key3
6
7
```

### Complexity

Average:

```cpp
O(1)
```

Worst:

```cpp
O(n)
```

if all keys fall into the same bucket.

---

## 2. Open Addressing

Instead of linked lists:

```text
Find another empty position.
```

Formula:

```text
Hi(key) = h(key) + F(i)
```

where

```text
h(key) = original hash index
F(i)   = probing function
```

---

### Linear Probing

```text
F(i) = i
```

Try:

```text
h
h+1
h+2
h+3
...
```

---

### Quadratic Probing

```text
F(i) = i²
```

Try:

```text
h+1²
h+2²
h+3²
...
```

Example:

```text
5
6
9
14
...
```

Reduces clustering.

---

# Load Factor

## Definition

```text
Load Factor = n / b
```

where

```text
n = number of elements
b = number of buckets
```

Example:

```text
n = 70
b = 100
```

Load Factor:

```text
70 / 100 = 0.7
```

---

# Rehashing

As load factor increases:

```text
Collisions increase
Performance decreases
```

When load factor crosses a threshold:

```text
~0.7
```

Hash table size is increased.

Example:

```text
100 buckets
↓
200 buckets
```

All existing elements are inserted again.

This process is called:

```text
Rehashing
```

---

# Complexity Analysis

Suppose:

```text
"Anwhee ball cat dog elephant ..."
```

Let

```text
n = number of words
k = average word length
```

Hashing one word:

```cpp
O(k)
```

Insertion:

```cpp
O(k)
```

For n words:

```cpp
O(nk)
```

If k is small and constant:

```cpp
O(n)
```

---

# LeetCode 49 - Group Anagrams

## Problem

```cpp
["eat","tea","tan","ate","nat","bat"]
```

Output:

```cpp
[
 ["eat","tea","ate"],
 ["tan","nat"],
 ["bat"]
]
```

---

## Observation

All anagrams have the same sorted form.

```cpp
eat -> aet
tea -> aet
ate -> aet
```

Use:

```cpp
unordered_map<string, vector<string>>
```

---

## Solution

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(string s : strs) {

            string key = s;
            sort(key.begin(), key.end());

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto &p : mp) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
```

### Complexity

```cpp
Time  : O(n * k log k)
Space : O(n * k)
```

where:

* n = number of strings
* k = average length of string

---

# LeetCode 560 - Subarray Sum Equals K

## Problem

```cpp
nums = [1,1,1]
k = 2
```

Output:

```cpp
2
```

Subarrays:

```cpp
[1,1]
[1,1]
```

---

## Prefix Sum + Hash Map

Maintain:

```cpp
prefixSum
```

If:

```text
currentPrefix = sum

and

(sum - k) existed before
```

then a valid subarray exists.

---

## Walkthrough

Input:

```cpp
nums = [1,1,1]
k = 2
```

Initialize:

```cpp
mp[0] = 1;
```

### Index 0

```cpp
sum = 1;
sum-k = -1;
```

Not found.

Store:

```cpp
mp[1]++;
```

---

### Index 1

```cpp
sum = 2;
sum-k = 0;
```

Found once.

```cpp
ans += 1;
```

Store:

```cpp
mp[2]++;
```

---

### Index 2

```cpp
sum = 3;
sum-k = 1;
```

Found once.

```cpp
ans += 1;
```

Answer:

```cpp
2
```

---

## Solution

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        mp[0] = 1;

        int sum = 0;
        int ans = 0;

        for(int x : nums) {

            sum += x;

            if(mp.count(sum - k))
                ans += mp[sum - k];

            mp[sum]++;
        }

        return ans;
    }
};
```

### Complexity

```cpp
Time  : O(n)
Space : O(n)
```

---

# Important HashMap Patterns

## 1. Frequency Map

```cpp
unordered_map<int,int> freq;
```

Used in:

* Two Sum
* Top K Frequent Elements
* Majority Element
* Valid Anagram

---

## 2. Grouping

```cpp
unordered_map<string, vector<string>>
```

Used in:

* Group Anagrams
* Group Shifted Strings

---

## 3. Prefix Sum + HashMap

```cpp
unordered_map<int,int>
```

Used in:

* Subarray Sum Equals K
* Continuous Subarray Sum
* Binary Subarray Sum

---

## 4. HashSet Style

```cpp
unordered_set<int>
```

Used in:

* Longest Consecutive Sequence
* Contains Duplicate
* Happy Number

```
```
