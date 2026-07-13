# Kadanes Algorithm
---

As you look through the numbers from left to right , you maintain a running total of your current streak.
each time  you have tow choices, 
1. Add current element to the streak 
2. Abandon and start a new streak.

Never carry a negative running total into a new element, if it goes below 0 , reset the sum to zero and start fresh. 

## How to identify 
1. "Contiguous" or "Subarray": The problem explicitly demands that the elements must be right next to each other. You cannot pick and choose random elements from across the array.

2. "Maximize" or "Largest Sum": You are looking for an optimal total value.

3. Presence of Negative Numbers: If an array only contains positive numbers, the maximum subarray is always just the entire array. The problem only becomes interesting and requires Kadane's when negative numbers threaten to break your streaks.

## basic structure 
```cpp
// 1. Initialize variables
int max_so_far = INT_MIN;  // Tracks the ultimate highest sum we've ever found
int current_max = 0;       // Tracks our current running streak sum

// 2. Loop through the array exactly once
for (int i = 0; i < nums.size(); i++) {
    
    // Step A: Add the current element to our running streak
    current_max += nums[i];
    
    // Step B: If this makes our current streak the best we've seen, update our record
    if (current_max > max_so_far) {
        max_so_far = current_max;
    }
    
    // Step C: If our running streak drops below 0, it is dead weight. Reset it!
    if (current_max < 0) {
        current_max = 0;
    }
}

// 3. Return the ultimate highest sum found
return max_so_far;
```