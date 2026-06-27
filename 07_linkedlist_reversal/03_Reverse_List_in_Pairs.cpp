// Problem: Reverse List in Pairs
// Link: https://leetcode.com/problems/swap-nodes-in-pairs/
// Difficulty: Medium
// Pattern: In-place Reversal of LinkedList
//
// Helper function reverse():
// - Standard prev/curr/nxt reversal, but reverses only 'times' nodes
//   starting from 'head' (not the whole list)
//
// Main pointers used:
// - left          → marks the START of the current pair being reversed
// - right         → walks forward (size-1) steps to find the END of the
//                   current pair, used to check if a full pair actually exists
// - previousleft  → the ORIGINAL head of the PREVIOUS pair (before it got
//                   reversed) → needed to reconnect it to the next reversed pair
// - res           → stores the FINAL answer's head (set only once, on the
//                   very first successful pair)
// - size          → fixed at 2 (pair size), controls how many nodes get
//                   reversed together and how far 'right' walks
//
// Approach:
// - Loop runs indefinitely (while true) until manually broken
// - For each iteration: walk 'right' forward (size-1) steps from 'left'
//   to locate the end of the current pair-to-be-reversed
// - If 'right' is valid (a full pair exists):
//   → save nextleft = right->next BEFORE reversing (so we don't lose
//     access to the rest of the list after this pair gets reversed)
//   → call reverse(left, size) → reverses this pair in place
//   → if previousleft exists → connect it to 'right' (which is now the
//     NEW head of this just-reversed pair, since reversal flips order)
//   → update previousleft to 'left' (which is now the TAIL of this
//     reversed pair, will connect to NEXT reversed pair later)
//   → if res hasn't been set yet → this is the very first pair →
//     res = right (the new overall head of the result)
//   → move left forward to nextleft to process the next pair
// - If 'right' is NULL (no full pair left, list has odd length or ended):
//   → this means whatever remains (pointed to by 'left') is a leftover
//     single node that should NOT be reversed
//   → connect previousleft to this leftover node directly
//   → if res still NULL (meaning list had only 1 node total) → res = left
//   → break out of the loop, we're done
//
// Why check 'res == NULL' instead of just always overwriting res?
// - res should only ever be set ONCE — to whatever node ends up being
//   the very FIRST node of the final answer. Every iteration after
//   that would otherwise incorrectly overwrite it with a later pair's head
//
// Time: O(n) | Space: O(1)

class Solution {
public:
   // making function for reverse 
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
    ListNode* swapPairs(ListNode* head) {
    // if 0 nodes
        if(head==NULL){
            return head;
        }
     ListNode*left=head;
     ListNode*right;
     ListNode*previousleft=NULL;
     ListNode*res=NULL;
        int size=2;
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