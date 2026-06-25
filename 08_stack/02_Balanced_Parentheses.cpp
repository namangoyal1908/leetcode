// Problem: Balanced Parentheses
// Link: https://leetcode.com/problems/valid-parentheses/
// Difficulty: Easy
// Pattern: Stack
//
// Approach:
// - Push every OPENING bracket onto the stack
// - When a CLOSING bracket appears, check if stack's top matches
//   the correct corresponding opening bracket
//   → if yes, pop (pair matched)
//   → if no, return false (mismatched brackets)
// - If a closing bracket appears but stack is EMPTY → no opening
//   bracket exists for it → invalid → return false
// - At the end, if stack is NOT empty → some opening bracket never
//   got closed → invalid → return false
// - Otherwise all brackets matched correctly → return true
//
// Why use a stack specifically?
// - Brackets must close in REVERSE order of how they opened (LIFO)
// - Stack naturally gives access to the MOST RECENT unmatched
//   opening bracket → exactly what's needed to validate nesting
//
// Time: O(n) | Space: O(n) for stack in worst case (all opening brackets)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            //push opening to stack
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {st.push(s[i]);
            continue;}
            //after all pushing if stack is empyt mean no opening 
            if(st.empty())
            {return false;}
            //check all permutations
            else{
                if(st.top()=='('&&s[i]==')' ){
                st.pop();
                continue;
                 }
                else if(st.top()=='['&&s[i]==']' ){
                st.pop();
                continue;
                 }
                else if(st.top()=='{'&&s[i]=='}' ){
                st.pop();
                continue;
                 }
                else{return false;}
            }
        }//if still opning bracket exist in stack
        if(!st.empty()){return false;}
        return true;
    }
};