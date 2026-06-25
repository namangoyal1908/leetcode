// Problem: Remove All Adjacent Duplicates in String
// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Difficulty: Easy
// Pattern: Stack
//
// Approach:
// - Use a stack to track characters as we scan left to right
// - If stack is empty → push current character (nothing to compare yet)
// - If top of stack == current character → it's an adjacent duplicate
//   → pop the stack instead of pushing (cancels the pair out)
// - Otherwise → push current character normally
//
// Why does this remove ALL adjacent duplicates, not just one pair?
// - After popping a matched pair, the new top of stack becomes
//   adjacent to whatever comes next in the string
// - So if removing a pair creates a NEW adjacent duplicate
//   (e.g. "abba" → pop 'b','b' → top becomes 'a', next char 'a' → pops again)
//   it gets handled automatically in the next iterations
//
// Why build result by popping stack and reversing at the end?
// - Stack only gives elements in LIFO order (top to bottom)
// - Popping everything into res gives REVERSED order of final string
// - reverse(res) at the end restores correct left-to-right order
//
// Time: O(n) | Space: O(n) for stack and result string

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        stack<char>st;
        int i=0;
        string res;
        for(i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(st.top()==s[i]){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};