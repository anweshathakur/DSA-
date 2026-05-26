# Largest Common Subsequence (LCS)

## Problem Statement 

Input strings -
String X : a b c d g h 
String Y : a b e d f h 

Here , the longset common subsequence - 
a b d h 
(common elements)

As output , return the lenght of the subsequence.
output : 4

## Recursive Approach 

### Base Condition 
- Think of the smallest valid input 
- for example in this case : the size of both the strings X and Y are 0. 
output = 

```cpp
if (n == 0 || m == 0 ){
    return 0 ;
}
```

### Choice Diagram 
![alt text](image.png)

code 
```cpp
if (X[n-1] == Y[m-1]){
    return 1+ lcs (X , Y , n-1 , m-1);
}
return max (lcs (X , Y , n , m-1) , lcs (X , Y , n-1 , m-1 ));
```

### Reduce Input
- Start from the last element
- choose if or not to consider it 
- the next time , the size gets reduced -> the element has been processed

## Recursive Code
```cpp
#include <iostream>
using namespace std; 

int lcs (X , Y , n , m){
    if (n == 0 || m == 0 ){
    return 0 ;
    }
    else if (X[n-1] == Y[m-1]){
    return 1+ lcs (X , Y , n-1 , m-1);
    }
    return max (lcs (X , Y , n , m-1) , lcs (X , Y , n-1 , m-1 ));
}
```

## Memorization
### Why  is it needed ? 
If the values getting repeated after calculation , unrequired working can be avoided by storing the previously computed values. we check if the we have already computed the value and carry on only if not.

### Deciding upon the matrix
size of matrix - ``` n * m ```


### How does it work ?

### Memorized code

## Top-Down 

## Code