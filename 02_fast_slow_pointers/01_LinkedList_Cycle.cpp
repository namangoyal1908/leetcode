// Problem: LinkedList Cycle
// Link: https://leetcode.com/problems/linked-list-cycle/
// Difficulty: Easy
// Pattern: Fast & Slow Pointers


// Why Fast & Slow Pointers?
// - No extra space needed → O(1) space
// - Circular Track Analogy:
//   Imagine 2 runners on a circular track
//   Slow runner moves 1 step, fast runner moves 2 steps
//   If track is circular (cycle exists) → fast will eventually
//   lap slow and they will MEET at same point
//   If no cycle → fast reaches end (NULL) without meeting slow
//
// Why check fast->next && fast->next->next?
// - fast moves 2 steps at a time
// - Must check both next AND next->next before moving
// - If only 1 node left → fast->next->next doesn't exist → stop
// - Without this check → NULL pointer dereference → crash
// - slow only moves 1 step → only needs slow->next to exist
//   but that's guaranteed by fast's condition being stricter
//
// Why check slow==fast AFTER moving?
// - Both start at head → if checked before moving → always true
// - Move first → then check if they met
//
// Time: O(n) | Space: O(1)


class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL) return false;

        ListNode* slow = head;  // moves 1 step at a time
        ListNode* fast = head;  // moves 2 steps at a time

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;        // 1 step
            fast = fast->next->next;  // 2 steps

            // runners met → cycle exists
            if (slow == fast)
                return true;
        }

        // fast reached end → no cycle
        return false;
    }
};