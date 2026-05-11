//----------------------------
// Remove Nth Node From End of List
//-------------------------------------------DESCRIPTION--------------------------------------
/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

Follow up: Could you do this in one pass?
*/ 
//-------------------------------------------BRUTE FORCE (TWO PASS)--------------------------------------

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //deletion at nth position 
        /*
        brute force approach 
        1. count number of nodes
        2. traverse till count-n +1 
        3.delete the node 
        */
        ListNode* temp = head;
        ListNode* prev = NULL;
        //count the number of nodes
        int count = 0;
        while (temp != NULL){
            temp = temp -> next ;
            count ++;
        }
        
        //delete at head
        if (n == count){
            ListNode* nodeToDelete = head;
            head = head->next; // Shift the head
            delete nodeToDelete; 
            return head;
        }
        //traverse till count-n +1
        temp = head;
        for (int i = 1; i < (count - n); i++) {
            temp = temp->next;
        }
        //delete
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next; // Skip the target node
        delete nodeToDelete;
        return (head);
    }
};
//time complexity : O(n) where n is the number of nodes in the list
//space complexity : O(1) as we are using only constant space

//-------------------------------------------OPTIMIZED APPROACH (ONE PASS)--------------------------------------
/* We can use two pointers to achieve this in one pass.
 The first pointer will be moved n steps ahead, and then both pointers will be moved together until 
 the first pointer reaches the end of the list. At that point, the second pointer will be at the node
just before the target node, allowing us to easily remove it.*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Create a dummy node that points to the head of the list
        // This points to head so we can easily delete the head node if needed.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Step 2: Create the gap of 'n' nodes between fast and slow
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Step 3: Move both together until 'fast' hits the last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 4: The Skip 
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Step 5: Clean up memory 
        delete nodeToDelete;

        // Step 6: Return the actual head
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node too!
        return newHead;
    }
};
//time complexity : O(n) where n is the number of nodes in the list
//space complexity : O(1) as we are using only constant space