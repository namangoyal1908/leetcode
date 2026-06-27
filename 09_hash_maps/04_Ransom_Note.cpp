// Problem: Ransom Note
// Link: https://leetcode.com/problems/ransom-note/
// Difficulty: Easy
// Pattern: Hash Map
//
// Approach:
// - Build TWO frequency maps:
//   need → frequency of each character REQUIRED (from ransomNote)
//   have → frequency of each character AVAILABLE (from magazine)
// - For ransomNote to be constructible, every character in 'need'
//   must have AT LEAST that many occurrences in 'have'
// - fun() checks this by iterating over 'need' map and comparing
//   each character's count against what's available in 'have'
// - If any character's available count < required count → return false
// - If all characters satisfy the requirement → return true
//
// Why iterate over 'need' map instead of 'have' map in fun()?
// - We only care about characters that ransomNote ACTUALLY needs
// - Magazine might have extra characters that are irrelevant —
//   checking 'have' would waste time on characters not even required
//
// Why have[c] works even if c doesn't exist in 'have'?
// - unordered_map returns 0 (default int value) for a missing key
//   when accessed with [] → safely treated as "0 occurrences available"
//
// Time: O(n + m) → n = ransomNote length, m = magazine length
// Space: O(1) → at most 26 lowercase letters in each map

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool fun (unordered_map<char,int>have,unordered_map<char,int>need){
        for(auto i: need){
            char c = i.first;
            int fneed=i.second;
            int fhave=have[c];
            if(fhave<fneed){
                return false;
            }
        }return true;
    }
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>have;
        unordered_map<char,int>need;
        for(int i=0;i<ransomNote.size();i++){
            need[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.size();i++){
            have[magazine[i]]++;
        }
        return fun(have,need);
    }
};