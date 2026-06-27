// Problem: First Non-repeating Character
// Link: https://leetcode.com/problems/first-unique-character-in-a-string/
// Difficulty: Easy
// Pattern: Hash Map
//
// Approach (2 passes):
// - First pass: build frequency map → count occurrences of every character
// - Second pass: scan string again, return the FIRST index where
//   that character's frequency in the map is exactly 1 (unique)
//
// Why two separate passes instead of one?
// - In a single pass, we wouldn't yet know the FULL frequency of a
//   character (it might appear again later in the string)
// - Need complete counts first (pass 1) before checking uniqueness (pass 2)
//
// Why iterate the string again instead of the map?
// - Maps don't preserve insertion/original order reliably for this use case
// - We need the FIRST occurrence in the original string, so re-scanning
//   the string (not the map) guarantees correct order
//
// Time: O(n) → two linear passes
// Space: O(1) → at most 26 lowercase letters stored in map (or O(k) for
//        k distinct characters in general case)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        unordered_map<char,int>f;
        // formationn of hashmap
        for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        // solve 
        for(int i=0;i<n;i++){
            if(f[s[i]]==1){
                return i;
            }
         }return -1;
    }
};