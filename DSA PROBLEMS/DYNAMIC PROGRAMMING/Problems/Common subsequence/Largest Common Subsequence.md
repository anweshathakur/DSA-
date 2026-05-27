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
depends upon - ``` size of strings - n+ 1 ; m + 1 ```
so that the max value that can be stored be n, m .

we initialize the matrix with ``` -1 ```

now, storing the values in the matrix will help avoid repetative calculation.

before calculation we check with the table created , and move on with it if the value is -1, else we return the value present in the table.


### How does it work ?

### Memorized code
```cpp
#include <iostream>
using namespace std;

int static t[1001][1001]
int lcs (X , Y , m, n ){
    if (n == 0 || m ==  0){
        return 0;
    }
    if (t[m][n]!= -1){
        return t[m][n];
    }
    if (X[m-1] == Y [n-1]){
        return t[m][n] = (1 + lcs(X , Y , m-1 ,n-1))
    }
    return t[m][n] = max(lcs(X, Y, m-1 , n), lcs (X , Y , m , n-1));
}
int main (){
    int string X ;
    int string Y ; 
    cin >> X >> Y ; 

    memset(t ,-1 , sizeof(t))

    lcs (X , Y , X.lenght() , Y.lenght());
}
```

## Top-Down 
### why do we need it ? 
We try to omit the recursive call completely.

The recursive calls get stored in a stack, hence there remains risk of stack overflow.
### Code variation
```cpp
int lcs (string X , string Y, int n, int m){
    if (m == 0 || n == 0 ){
        return 0;
    }

    // ans : t[m][n]
    for (int i = 1 ; i < n ; i++){
        for (int j = 1 ; j < m ; j ++){
            if (X[i+1] == Y[j+1]){
                return t[i][j] = 1+ t[i - 1 ][j-1];
            }
            return t[i][j] = max (t[i-1][j] , t[i][j-1]);
        }
    }
    return t[m][n];
}
```
