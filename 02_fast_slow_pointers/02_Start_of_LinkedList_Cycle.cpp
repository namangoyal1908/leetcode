// Problem: Start of LinkedList Cycle
// Link: https://leetcode.com/problems/linked-list-cycle-ii/
// Difficulty: Medium
// Pattern: Fast & Slow Pointers
//
// Phase 1: Detect meeting point (same as Cycle Detection)
// Phase 2: Find START of cycle using math
//
// Math behind Phase 2:
// Let:
//   l1 = distance from head to cycle start
//   l2 = distance from cycle start to meeting point
//   c  = total cycle length
//
// When they meet:
//   slow travelled = l1 + l2
//   fast travelled = l1 + l2 + n*c (fast did extra loops)
//   fast = 2 * slow → 2(l1+l2) = l1+l2+nc
//   → l1 = nc - l2 = c - l2 (for n=1)
//
// Meaning:
//   distance from HEAD to cycle start = distance from MEETING POINT to cycle start
//   → reset slow to head, keep fast at meeting point
//   → both move 1 step at a time → they meet exactly at cycle start!
//
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: find meeting point
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Phase 2: find cycle start
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;  // cycle start
            }
        }

        return nullptr;  // no cycle
    }
};