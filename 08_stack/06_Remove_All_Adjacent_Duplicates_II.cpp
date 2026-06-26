// Problem: Remove All Adjacent Duplicates in String II
// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// Difficulty: Medium
// Pattern: Stack (Pair Stack)
//
// How is it different from "Remove Adjacent Duplicates" (k=2 fixed)?
// - That problem only removed PAIRS (exactly 2 adjacent duplicates)
// - This problem removes groups of EXACTLY k adjacent duplicates, where k
//   can be any value → can't just check top of stack once, need to COUNT
//
// Why stack of pairs <char, int> instead of just stack<char>?
// - Need to track BOTH the character AND how many times it has
//   consecutively appeared so far (its running count)
// - A plain stack<char> can't store this count alongside the character
//
// Approach (4 cases per character):
// - Case 1: stack empty → push {char, 1} (first occurrence)
// - Case 2: top character != current char → push {char, 1} (new streak starts)
// - Case 3: top character == current char but count < k-1 → increment
//   count by popping and re-pushing with count+1 (streak continues, not yet k)
// - Case 4: top character == current char and count == k-1 → this character
//   COMPLETES the streak of k → just pop (the whole group of k gets removed,
//   nothing pushed back)
//
// Why does popping in Case 4 handle removal correctly?
// - Once k duplicates are found, they're discarded entirely (matches
//   problem's removal rule) → and whatever was below in the stack becomes
//   adjacent to future characters, just like the simpler duplicate problem
//
// Building the result:
// - Stack holds (char, count) pairs in LIFO order after all processing
// - Pop each pair and push the character 'count' times into res
// - Since popping is reverse order → reverse(res) restores correct order
//
// Time: O(n) | Space: O(n) for stack and result string

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n= s.size();
        //make a stack which stores a pair of char and int 
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){
            char c=s[i];
            // case 1 when stack is empty 
            if(st.empty()){
                st.push({c,1});
                continue;
            }
            // case 2 if stack is not empty but character doesnt match 
            if(st.top().first!=c){
                st.push({c,1});
                continue;
            }
            // case 3 if stack is not empty but character matched but less thaan k times 
            if(st.top().second<(k-1)){
                pair<char,int>p=st.top();
                st.pop();
                st.push({p.first,p.second+1});
                continue;
            }
            //case 4 if stack is not empty but character matched but equals thaan k times
            st.pop();
        }
        // making result
        string res;
        while(!st.empty()){
             pair<char,int>p=st.top();
             st.pop();
             while(p.second--){
                res.push_back(p.first);
             }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};