# Dynamic Programming 
Dynamic Programming is a method for solving complex problems by breaking them down into simpler 
subproblems. 
It is mainly used when a problem has:

- **Overlapping Subproblems** → the same subproblem is solved multiple times.
- **Optimal Substructure** → the optimal solution can be built using optimal solutions of smaller subproblems.

Most Dynamic Programming problems are built on the concept of ```Recursion```.


## Identifying DP Problems
1. The problem will provide a choice of either choosing or not choosing an element.
2. Optimal Solution (min / max / smallest / largest) will be expected as output.

## Steps for Solving 

Recursion --> Memorization--> Top-Down

## Knap-Sack Problems 

A typical Knap-Sack problem provides two arrays ``` weight ``` & ``` value ``` . Often times both are a part of one array. 
Next, we are given a ``` sack ``` , a container in which elements can be stored . The maximum capacity of this sack can be called ``` C ```. 
We are then asked to maximize or minimize a variable by choosing the correct elements from the given arrays.

for eg :
the given arrays are : 

| Items | I1 | I2  | I3 | I4 |
|---------|-----|--------|--------|-------|
| weight array | w1 | w2  |  w3 | w4 |
| value array  | v1 | v2 |  v3 | v4 |

the Sack has a maximum capacity of : 10
Find the items to put int the sack to have maximum profit.

### Types of Knap-Sack Problems

| Fractional Knapsack | 0/1 Knapsack | Unbounded Knapsack |
|---------------------|--------------|--------------------|
| Items can be taken fractionally | Item is either taken or not taken | Items can be taken multiple times |
| Greedy approach works | Greedy fails, DP is used | DP is commonly used |
| Time Complexity: O(n log n) due to sorting | Time Complexity: O(n × W) | Time Complexity: O(n × W) |
| Example: Cutting gold into parts | Example: Selecting whole objects | Example: Unlimited coins/rod cutting |
| Based on value/weight ratio | Based on optimal subproblems | Based on repeated usage of items |

### 0/1 Knap-Sack 

**Problem**
| Items | I1 | I2  | I3 | I4 | I5  |
|---------|-----|--------|--------|-------|------- |
| Input | 1 | 3  |  4 | 5 | 6 |
| Value | 1 | 5 |  7 | 9 | 3 |

C -> 9
FInd the max profit.

**Choice Diagram**
```text
                     w1
                   /      \
              w1 > C       w1 <= C               
               |            /    \
            exclude    include   exclude
                      
                             
```
**Basic Structure**
```cpp
int knapsack(int wt[], int val[], int w, int n){
    //base condition

    // choice diagram
}
```

--> **Base Condition** 
Condition for the smallest valid Input.

for eg : in the above given problem ; 
if the lenght of either of the arrays is 0 , the max profit would be 0.
```cpp
if (n == 0 || w == 0 ){
    return 0;
}
```

--> **Choice Logic**
```cpp
// If the current item can fit inside the remaining capacity
if(weight[n-1] <= capacity){

    // Choice 1 : Include the current item
    // Add its value and reduce the remaining capacity
    include = value[n-1] +
              solve(n-1, capacity - weight[n-1]);

    // Choice 2 : Exclude the current item
    // Move to the next item without changing capacity
    exclude = solve(n-1, capacity);

    // Return the maximum profit from both choices
    return max(include, exclude);
}

// If the current item cannot fit in the sack
else{

    // Skip the current item
    return solve(n-1, capacity);
}
```

**Knap Sack Memorization**
# 0/1 Knapsack using Memoization (Top-Down DP)

Memoization is an optimization technique used in Dynamic Programming where we store already computed recursive results to avoid repeated calculations.

In the recursive solution of Knapsack, many states repeat multiple times.

Example:

```text
f(3,4)
f(2,3)
f(2,3)   ← repeated state
```

Instead of solving the same state again and again, we store its answer in a DP table.

---

# State Representation

```text
dp[n][C]
```

Where:

- ```n``` → number of items remaining
- ```C``` → remaining capacity

The value stored in:

```text
dp[n][C]
```

represents the maximum profit possible using:

- first ```n``` items
- with capacity ```C```

---

# Steps of Memorization

1. Create a DP table initialized with ```-1```
2. Before solving a state, check if it is already computed
3. If already computed, return the stored answer
4. Otherwise compute and store the result

---

# Recursive Relation

At every item, we have two choices:

1. Include the item
2. Exclude the item

---

# Memorization Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>& weight,
             vector<int>& value,
             int n,
             int capacity,
             vector<vector<int>>& dp)
{

    // Base Condition
    if(n == 0 || capacity == 0){
        return 0;
    }

    // If already computed, return stored value
    if(dp[n][capacity] != -1){
        return dp[n][capacity];
    }

    // If current item can fit inside the sack
    if(weight[n-1] <= capacity){

        // Include current item
        int include =
            value[n-1] +
            knapsack(weight,
                     value,
                     n-1,
                     capacity - weight[n-1],
                     dp);

        // Exclude current item
        int exclude =
            knapsack(weight,
                     value,
                     n-1,
                     capacity,
                     dp);

        // Store and return maximum profit
        dp[n][capacity] = max(include, exclude);
    }

    // If current item cannot fit
    else{

        // Skip the current item
        dp[n][capacity] =
            knapsack(weight,
                     value,
                     n-1,
                     capacity,
                     dp);
    }

    return dp[n][capacity];
}

int main(){

    vector<int> weight = {1, 3, 4, 5};
    vector<int> value  = {1, 4, 5, 7};

    int capacity = 7;
    int n = weight.size();

    // DP table initialized with -1
    vector<vector<int>> dp(n + 1,
                           vector<int>(capacity + 1, -1));

    cout << knapsack(weight,
                     value,
                     n,
                     capacity,
                     dp);
}
```

---

# Time Complexity

```text
O(n × C)
```
---

# Space Complexity

```text
O(n × C)
```


---

# Why Memoization is Faster

Recursive solutions recompute the same states many times.

Memoization avoids this by storing answers in:

```text
dp[n][capacity]
```

Thus each state is solved only once.

# Unbounded Knapsack

multiple occurences of the same item is allowed in Unbiunded Knapsack.
logic- 
if the item is already included we consider it to be unprocessed , so that it can be considered for repetition as well.
but if we exclude an item , it is considered to be processed. It will not be repeated again in the process , it becomes unelligible.

## Code and Logic
```cpp
#include <iostream>
//initialization remains same as before 
int knapsack(int wt[], int val[], int w, int n){
    //base condition
    if(n == 0 || capacity == 0){
        return 0;
    }

    // choice 
    // If the current item can fit inside the remaining capacity
    if(weight[n-1] <= capacity){

        // Choice 1 : Include the current item
        // Add its value and dont reduce the remaining capacity
        include = value[n-1] +
                solve(n , capacity - weight[n-1]);

        // Choice 2 : Exclude the current item
        // Move to the next item without changing capacity
        exclude = solve(n-1, capacity);

        // Return the maximum profit from both choices
        return max(include, exclude);
    }

    // If the current item cannot fit in the sack
    else{

        // Skip the current item
        return solve(n-1, capacity);
    }
}

```
