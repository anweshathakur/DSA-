//-----------------------------------------QUESTION --------------------------------------------------
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that 
they add up to target.You may assume that each input would have exactly one solution,and you may not
use the same element twice. You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/

//-----------------------------------------BRUTE FORCE--------------------------------------------------
#include <iostream>
#include <vector>

using namespace std;
//calculate all pairs 
for (int i = 0 ; i < arr.size() ; i++){
    for (int j = i + 1 ; j < arr.size() ; j++){
        if (arr[i] + arr[j] == target){
            return {i, j};
        }
    }
}

//-----------------------------------------Better Approach--------------------------------------------------
#include <iostream>
#include <vector>
/*
take start and end and check if the sum is equal to target then return the indices if the sum
is less than target then move start forward and if the sum is greater than target then
 move end backward
*/
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while (start < end){
        if (nums[start] + nums[end] == target){
            return {start, end};
        }
        else if (nums[start] + nums[end] < target){
            start++;
        }
        else{
            end--;
        }
    }
    return {};
}

//-----------------------------------------Optimal Approach--------------------------------------------------
/*
use a hash map to store the elements and their indices.
For each element, check if the complement (target - current element) 
exists in the hash map. If it does, return the indices of the current element and the complement. 
If it doesn't, add the current element and its index to the hash map.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashMap; // value -> index
    for (int i = 0; i < nums.size(); i++){
        int complement = target - nums[i];
        if (hashMap.find(complement) != hashMap.end()){
            return {hashMap[complement], i};
        }
        hashMap[nums[i]] = i;
    }
    return {};
}

/*
NOTE: we use unordered_map instead of map because it provides average O(1) time complexity for lookups,
while map provides O(log n) time complexity.
Since we only need to check for the existence of the complement and retrieve its index,
unordered_map is more efficient for this use case.
*/