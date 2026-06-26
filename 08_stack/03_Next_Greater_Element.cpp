// Problem: Next Greater Element II
// Link: https://leetcode.com/problems/next-greater-element-ii/
// Difficulty: Medium
// Pattern: Stack (Monotonic Stack) + Circular Array
//
// Approach:
// - Array is CIRCULAR → next greater element can wrap around to the start
// - Trick to simulate circularity: pre-load the stack with the SECOND HALF
//   of the array first (indices n-2 down to 0... wait, actually n-1 down to 0
//   conceptually means we virtually go around the array TWICE)
// - First loop (i = n-2 to 0) pushes elements WITHOUT processing them
//   → this "pre-fills" the stack so that when we do the real pass,
//     elements from the wrap-around portion are already available
// - Second loop (i = n-1 to 0) does the ACTUAL next-greater computation:
//   → pop all elements <= nums[i] (they can't be the answer for current
//     or future elements to the left, since current is greater/equal
//     and would be encountered first in circular order)
//   → if stack empty after popping → no greater element exists → -1
//   → else → stack top is the next greater element
//   → push current element back for use by elements further left
// - Result is built in reverse order, so reverse() at the end fixes it
//
// Why pre-load the stack first instead of doubling the array?
// - Avoids creating a literal doubled array (saves space)
// - Pre-loading achieves the same effect: by the time we reach index i
//   in the real pass, the stack already "knows about" elements that
//   would appear AFTER wrapping around past index i in a circular sense
//
// Time: O(n) → each index pushed/popped a constant number of times
// Space: O(n) for stack and result vector

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>res;
        for(int i=n-2;i>=0;i--){
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                res.push_back(-1);
            }
            else{res.push_back(st.top());}
            st.push(nums[i]);
        }reverse(res.begin(), res.end());
        return res;
    }
};