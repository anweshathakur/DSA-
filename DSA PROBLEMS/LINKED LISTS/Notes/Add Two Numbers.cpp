/*
LEETCODE PROBLEM: 2. Add Two Numbers
description:
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/
//-----------------------------CODE -----------------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        /*
        dummy -> head of answer list
        curr -> temp of ans list
        */
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        //loop till any digit or carruy is left
        while (temp1 != NULL || temp2 != NULL || carry != 0){
            //if one of the lists ends then add 0 to continue addition
            int val1 = (temp1 != nullptr) ? temp1->val : 0;
            int val2 = (temp2 != nullptr) ? temp2->val : 0;
            //calculating sum and carry
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            //making ans list
            curr -> next = new ListNode(sum % 10);
            curr = curr -> next;
            //continue
            if (temp1 != nullptr) temp1 = temp1->next;
            if (temp2 != nullptr) temp2 = temp2->next;

        }
        return dummy -> next;
    }
};
//time complexity : O(max(m,n)) where m and n are the lengths of l1 and l2 respectively
//space complexity : O(max(m,n)) for the output list.
//------------------------------------------RECURSIVE APPROACH--------------------------------------
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        // Base case: If everything is null and no carry remains, we're done
        if (!l1 && !l2 && carry == 0) return nullptr;

        // Calculate current sum
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        
        // Create the node for the current digit
        ListNode* result = new ListNode(sum % 10);
        
        // Recursive step: solve for the next nodes
        result->next = addTwoNumbers(
            l1 ? l1->next : nullptr, 
            l2 ? l2->next : nullptr, 
            sum / 10
        );
        
        return result;
    }
};

//smaller code using recursion
//time complexity : O(max(m,n)) where m and n are the lengths of l1 and l2 respectively
//space complexity : O(max(m,n)) for the recursion stack and output list.
//------------------------------ IN PLACE ADDITION --------------------------------------------------
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2, *prev = nullptr;
        int carry = 0;

        while (temp1 || temp2 || carry) {
            // If temp1 is null but we still have work (temp2 or carry),
            // attach a new node to the end of the l1 chain.
            if (!temp1) {
                prev->next = new ListNode(0);
                temp1 = prev->next;
            }

            int val2 = temp2 ? temp2->val : 0;
            int sum = temp1->val + val2 + carry;
            
            temp1->val = sum % 10; // Update l1 in-place!
            carry = sum / 10;

            prev = temp1;
            temp1 = temp1->next;
            if (temp2) temp2 = temp2->next;
        }
        return l1;
    }
};
//Saves space by modifying l1 directly, but be cautious if l1 is shared or should not be altered.
//time complexity : O(max(m,n)) where m and n are the lengths of l1 and l2 respectively
//space complexity : O(1) if we ignore the output list, otherwise O(max(m,n)) for the output list.