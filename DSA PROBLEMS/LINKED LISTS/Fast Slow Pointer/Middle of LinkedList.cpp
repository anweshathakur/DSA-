/*
--- EDITORIAL ---
Intuition:
You can either count the total nodes first or find the middle in a single pass.

Approaches:
1. Brute Force: Traverse to count N nodes, then traverse again to the N/2-th node.
2. Two Pointers (Slow & Fast): Use two pointers, slow and fast. Move slow one step and fast two steps at a time. When fast reaches the end, slow will be at the middle.

Complexity:
- Time: O(N)
- Space: O(1)
-----------------

PROBLEM STATEMENT:
 PROBLEM 876. Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Constraints:
The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/
/*
--- EDITORIAL ---
Intuition:
Since we don't have access to the head, we can't traverse to the previous node. However, we can copy the value of the next node into the current node and then bypass the next node.

Approach:
1. Copy the value from the next node to the current node: `node->val = node->next->val`.
2. Skip the next node by pointing the current node's `next` to the next node's `next`: `node->next = node->next->next`.

Complexity:
- Time: O(1)
- Space: O(1)
-----------------

PROBLEM STATEMENT:
Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.
It is guaranteed that the node to be deleted is not a tail node in the list.
*/
//------------------------------------------SOLUTION------------------------------------------
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//------------------------------------------BRUTE FORCE APPROACH------------------------------------------
class BruteForceSolution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        
        // Count the total number of nodes in the linked list
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        
        // Calculate the index of the middle node
        int middleIndex = count / 2; // This works for both odd and even counts
        
        // Traverse again to reach the middle node
        temp = head;
        for (int i = 0; i < middleIndex; i++) {
            temp = temp->next;
        }
        
        return temp; // This will be the middle node
    }
};
//------------------------------------------TWO POINTER APPROACH------------------------------------------

class OptimalSolution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};