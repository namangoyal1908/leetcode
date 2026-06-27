// Problem: Longest Palindrome
// Link: https://leetcode.com/problems/longest-palindrome/
// Difficulty: Easy
// Pattern: Hash Map
//
// Approach:
// - Build frequency map of all characters in string
// - A palindrome can use character pairs freely from both sides
//   → so any character with an EVEN frequency can be fully used
// - A character with ODD frequency can only contribute (val-1) characters
//   in pairs, with ONE leftover character that could potentially sit
//   in the MIDDLE of the palindrome
//
// First pass over map:
// - For every character with EVEN frequency → add full count to result
// - If ANY character has ODD frequency → set odd flag to true
//   (this means at least one leftover character is available for the center)
//
// Why return early if odd == false?
// - If no character has odd frequency, every character pairs up perfectly
// - Result is already the maximum possible palindrome length
//
// Second pass (only runs if odd == true):
// - For every character with ODD frequency → add (val-1) to result
//   (using all but one occurrence in pairs)
// - After loop, add +1 at the end → accounts for ONE single leftover
//   character that can occupy the center of the palindrome
//
// Why only +1 total (not +1 per odd character)?
// - A palindrome can have AT MOST one unpaired character in the middle
// - Even if multiple characters have odd frequency, only one of their
//   leftovers can actually be placed in the center position
//
// Time: O(n) | Space: O(1) → at most 52 distinct characters (upper+lower case)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;
        int n=s.size();
        for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        bool odd= false;
        int res=0;
        for(auto i: f){
            int val=i.second;
            if(val%2==0){
                res=res+val;
            }
            else{odd=true;}
        }
        if(odd==false){
            return res;
        }
        for(auto i: f){
            int val=i.second;
            if(val%2==1){
                res=res+val-1;
            }
         }return res+1;
    }
};