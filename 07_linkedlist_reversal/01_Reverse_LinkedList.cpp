// Problem: Reverse a LinkedList
// Link: https://leetcode.com/problems/reverse-linked-list/
// Difficulty: Easy
// Pattern: In-place Reversal of LinkedList
//
// Approach:
// - Use two pointers: curr starts at head, prev starts at NULL
// - At every step:
//   1. Save curr->next FIRST (into nxt) before breaking the link
//      → otherwise we'd lose access to the rest of the list
//   2. Reverse the current node's pointer → curr->next = prev
//      (this is the actual "reversal" step)
//   3. Move prev forward to curr (prev now points to the reversed node)
//   4. Move curr forward to nxt (advance to the next unprocessed node)
// - Loop continues until curr becomes NULL → entire list processed
// - prev now points to the NEW head of the reversed list → return prev
//
// Why initialize prev as NULL?
// - The ORIGINAL head's next pointer should eventually point to NULL
//   (since it becomes the new TAIL after reversal)
// - Starting prev at NULL ensures this happens naturally on the first iteration
//
// Why save nxt before reversing curr->next?
// - Once curr->next = prev executes, the original "next" link is overwritten
// - Without saving it first, we'd lose the ability to traverse forward
//   and the rest of the list would become unreachable
//
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // allocate 2 pointers one at starting of ls and one at null
          ListNode *curr=head;
          ListNode *prev=NULL;
        while(curr!=NULL){
            ListNode *nxt=curr->next;
            curr->next=prev;
         prev=curr;
         curr=nxt;
        }
        return prev;
    }
};