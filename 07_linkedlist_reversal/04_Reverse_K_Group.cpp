// Problem: Reverse every K-element Sub-list
// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
// Difficulty: Hard
// Pattern: In-place Reversal of LinkedList
//
// How is it different from "Reverse List in Pairs"?
// - Literally the EXACT same code, just size=k instead of size=2 (hardcoded 2)
// - Pairs problem is just the special case of this problem where k=2
// - Same pointers, same logic, same edge case handling — fully generalized
//
// Pointers used (same as Pairs version):
// - left          → marks START of current k-group being reversed
// - right         → walks (size-1) steps from left to find END of the
//                   group, used to verify a FULL group of k nodes exists
// - previousleft  → original head of the PREVIOUS k-group (before reversal)
//                   needed to reconnect it to current reversed group
// - res           → final answer's head, set once on first successful group
// - size          → now equals k (variable group size) instead of fixed 2
//
// Approach (identical logic to Pairs, generalized):
// - Walk 'right' forward k-1 steps from 'left' to check if a FULL group
//   of k nodes exists
// - If yes (right is valid):
//   → save nextleft before reversing (preserve rest of list)
//   → reverse(left, k) → reverses this k-sized group
//   → connect previousleft to 'right' (new head of this reversed group)
//   → update previousleft to 'left' (new tail of this reversed group)
//   → set res once, on the first group
//   → move left to nextleft for next group
// - If no (right hit NULL → leftover nodes < k):
//   → per LeetCode's rule, leftover nodes that don't form a full group
//     of k should NOT be reversed, left as-is
//   → connect previousleft directly to this leftover chunk (left)
//   → break
//
// Time: O(n) | Space: O(1)

class Solution {
public:
    void reverse ( ListNode * head,int times ){
             ListNode*current=head;
            ListNode*prev=NULL;
        while(times--){
               ListNode*nxt=current->next;
                current->next=prev;
                prev=current;
                current=nxt;
            }
        return ;
        }
    ListNode* reverseKGroup(ListNode* head, int k) {
     // if 0 nodes
        if(head==NULL){
            return head;
        }
     ListNode*left=head;
     ListNode*right;
     ListNode*previousleft=NULL;
     ListNode*res=NULL;
        int size=k;
        while (true){
        // initializing 2 points which needs to be reversed 
        right=left;
        for(int i=0;i<size-1;i++){
            // bound check 
            if(right == NULL){
                break;
            }
            right=right->next;
        }
        if(right)//right left mil chuka hai
        {
             ListNode*nextleft=right->next;// storing next left for next reversal
            reverse(left,size);// reversing the nodes 
            if(previousleft){
                previousleft->next=right;}
                previousleft=left;
            if(res==NULL){
                res=right;}
                left=nextleft;//moving to next pair for reversal
        }
        else{
            if(previousleft){
                previousleft->next=left;
            }
            if(res==NULL){
                res=left;
            }
            break;
        }
    }return res;
    }
};