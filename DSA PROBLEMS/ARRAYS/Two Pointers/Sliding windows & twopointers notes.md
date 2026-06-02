# Sliding Windows & Two Pointers Notes

---

## 1. Constant Window

arr = [1 , 2, 3 , 4, 5 , -1]
pick 4  elements consecutively to get the maximum sum.

take two pointers l and r , run a loop from 
(l -> r)
where l is at index 0 and r at k-1.
k= 4 (constant size of window)

```cpp
maxsum = loop from l -> r --> find the sum 
while (r < n ){
    sum = sum - arr[l];
    l++;
    r++; 
    sum = sum + arr[r];

    maxSum = max (maxsum , sum);
}
```
---

## 2.Longest Subarray or Substring

longest subarray with sum =< k 
subarray -> consectutive group

arr = [2 , 5, 1, 7, 10]
k = 14

**Brute force**
generate all the subarrays and check with the condition.
```
maxlen = 0 ;
for (i = 0 , i < n-1 ; i++){
    sum = 0 ;
    for (j = i ; i < n-1 ; j++){
        sum = sum+ arr[j];
        if (sum <=k){
            maxlen = max(maxlen , j - i + 1);
        }
        //optimization
        elseif (sum > k ) break ;
    }
}
print (maxlen);
```

**Optimal Solution**

-> two pointers & sliding windows
-> take a window of size 1 
-> l &r 
-> sum = 0 
-> expand -> r / shrink -> l
-> lenght of window l - r - 1
-> expand till the time the condition is satisfied 
-> when it doesnt satisfy , shrink till it does.

```
for eg - 
arr [2 ,  5, 1, 7, 10]

initial 
arr[l] = 2
arr[r] = 2
sum = 2
lenght = 1 

expand 
arr[l] = 2
arr[r] = 5
sum = 7
lenght = 2

expand
arr[l] = 2
arr[r] = 1
sum = 8
lenght = 3

expand
arr[l] = 2
arr[r] = 7
sum = 15
lenght = 4 

shrink
arr[l] = 5
arr[r] = 7
sum = 13
lenght = 3 

ans -> 5 , 1 , 7
```

```cpp
l = 0 
r = 0
sum = 0
while (r < n){
    sum = sum + arr[r];
    while (sum> k) {
        if (sum > k){
            sum = sum- arr[l];
            l = l+ 1;
        }
    }

    if (sum <= k){
        maxlen = max (maxlen , r-l-1);
    }
    r = r+1
}

```
if only the max lenght is asked , the more optimal solution for it would be -

```cpp
l = 0 
r = 0
sum = 0
if (r < n){
    sum = sum + arr[r];
    while (sum> k) {
        if (sum > k){
            sum = sum- arr[l];
            l = l+ 1;
        }
    }

    if (sum <= k){
        maxlen = max (maxlen , r-l-1);
    }
    r = r+1
}
```

## 3. Number of Subarrays
using the pattern 2

Figure out the ```number of subarrays``` of ```sum = k```

1. x= find the number of subarrays , where sum < k 
2. y = find the number of subarrays , where sum < k-1
 ans = x-y

## 4. Find the Shortest window 
ans -> shortest shrinked window, 
