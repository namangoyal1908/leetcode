// Problem: Reverse a Sub-list
// Link: https://leetcode.com/problems/reverse-linked-list-ii/
// Difficulty: Medium
// Pattern: In-place Reversal of LinkedList
//
// Pointers used and their roles:
// - t        → traversal pointer, walks through the list from head to track position
// - before   → stores the node JUST BEFORE the sublist that needs reversing
//              (needed so we can reconnect it to the new head of reversed sublist later)
// - pos      → counter to track current position while walking, compared against 'left'
// - current  → marks the start of the actual reversal once position reaches 'left'
// - prev     → standard reversal pointer, builds the reversed sublist node by node
// - nxt      → temporary pointer to save current->next before it gets overwritten
// - times    → counts how many reversal steps are needed (right - left + 1 nodes)
//
// Approach:
// - Edge case 1: empty list → return NULL
// - Edge case 2: left == right → only one node to "reverse" → no-op → return head
// - Walk forward using t and pos, tracking 'before' as the last node seen
//   BEFORE reaching the 'left' position (this node stays fixed outside the reversal)
// - Once pos == left, start the actual reversal using the same prev/curr/nxt
//   technique as standard list reversal, but only for (right-left+1) nodes
// - After reversal completes:
//   t->next = current → connects the END of the reversed sublist (t, which was
//   the original 'left' node) to whatever comes AFTER the sublist (current)
// - If 'before' exists (left != 1) → before->next = prev → reconnects the node
//   before the sublist to the NEW head of the reversed sublist (prev)
// - If 'before' is NULL (left == 1) → the reversed sublist's new head (prev)
//   IS the new head of the entire list → return prev directly
//
// Time: O(n) | Space: O(1)

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      ListNode* prev = NULL;
        //if no link list exist
        if(head==NULL){
            return NULL;
        }
        //if you have to reverse only one node
        if(left==right){
            return head;
        }
        ListNode* t = head;
        ListNode* before = NULL; //will be used to track the node just before the reversaal
        int pos = 1; //use to track the position and check on which node u are on
        while(t!=NULL){
            //when no reversal to be done before reaching left
            if(pos<left){
                before=t; //tracking the last node
                t=t->next;
                pos++;
                continue;
            }
            // if u reached hear mean u have to reverse now
            ListNode* current=t;
            prev=NULL;
            int times=right-left+1; // this will tell how many times to reverse
            while(times--){
                ListNode* nxt=current->next; //will use to move current to next node
                current->next=prev; //revesing
                prev=current;
                current=nxt;
            }
            t->next=current;
            //edge case if left = 1 so no before exist
            if(before){
                before->next=prev;
                return head;
            }
            return prev;   // <-- Added this return here
        }
        return head;
    }
};