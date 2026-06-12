// Problem: Middle of the LinkedList
// Link: https://leetcode.com/problems/middle-of-the-linked-list/
// Difficulty: Easy
// Pattern: Fast & Slow Pointers
//
// Brute Force:
// - Traverse full list → count n nodes
// - Traverse again to n/2 → O(n) but 2 passes
//
// Why Fast & Slow Pointers?
// - Single pass → O(n) with 1 traversal
// - When fast reaches end → slow is exactly at middle
// - Fast moves 2x speed of slow → when fast covers n steps
//   slow has covered n/2 steps → middle!
//
// Even vs Odd length:
// - Odd length [1,2,3,4,5] → fast hits NULL at end → slow at 3 
// - Even length [1,2,3,4] → fast->next hits NULL → slow at 3 (second middle) 
//
// Time: O(n) | Space: O(1)


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;  // moves 2 steps
        ListNode* slow = head;  // moves 1 step

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;  // 2 steps
            slow = slow->next;        // 1 step
        }

        // fast at end → slow at middle
        return slow;
    }
};