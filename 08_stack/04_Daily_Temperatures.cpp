// Problem: Daily Temperatures
// Link: https://leetcode.com/problems/daily-temperatures/
// Difficulty: Easy
// Pattern: Stack (Monotonic Stack)
//
// Approach:
// - Traverse from RIGHT to LEFT
// - Stack stores INDICES of temperatures, maintained such that
//   temperatures at those indices are in DECREASING order from bottom to top
//   → this is a "next greater element" pattern using monotonic stack
// - For current index i, pop all indices from stack whose temperature
//   is <= temperatures[i] → they can never be the "next warmer day"
//   for anything to their left (since current i is warmer/equal and closer)
// - After popping, if stack is NOT empty → st.top() is the index of
//   the nearest day to the RIGHT that's warmer → res[i] = st.top() - i
// - If stack IS empty → no warmer day exists ahead → res[i] stays 0
// - Push current index i onto stack for future comparisons
//
// Why traverse right to left instead of left to right?
// - We need to know the NEXT warmer day relative to each index
// - Going right to left means by the time we process index i,
//   the stack already holds the relevant "future" (right side) info
//
// Why pop elements with temperature <= current?
// - Those indices are now "blocked" — they can never be the answer
//   for any index further left, since current i is both warmer (or equal)
//   AND closer → makes them obsolete for future use
//
// Time: O(n) → each index pushed and popped at most once
// Space: O(n) for stack and result vector

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st; // stores indices
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() &&
                temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            if (!st.empty())
                res[i] = st.top() - i;
            st.push(i);
        }
        return res;
    }
};