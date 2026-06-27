// Problem: Maximum Number of Balloons
// Link: https://leetcode.com/problems/maximum-number-of-balloons/
// Difficulty: Easy
// Pattern: Hash Map
//
// Approach:
// - Build 'have' map → frequency of each character in input text
// - Build 'need' map → required count of each letter to spell "balloon" ONCE
//   b=1, a=1, l=2, o=2, n=1
// - For each required character, calculate how many times we COULD spell
//   "balloon" using just that character → times = fhave / fneed
// - The actual answer is limited by the SCARCEST character → take the
//   MINIMUM of all these "times" values across every required letter
//
// Why take the minimum instead of average or max?
// - We can only build as many "balloon" words as our most LIMITING
//   character allows — even if we have tons of 'a's, if we only have
//   1 'l' (needing 2 per word), we can build 0 complete balloons from l's
//
// Why integer division (fhave/fneed) works here?
// - Naturally rounds DOWN → gives the maximum WHOLE number of times
//   that character's available count can satisfy the required count
//
// Time: O(n) → n = length of text, plus O(1) for fixed-size need map (5 keys)
// Space: O(1) → at most 26 lowercase letters in 'have' map

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n= text.size();
        unordered_map <char,int>have;
        for(int i=0;i<n;i++){
            have[text[i]]++;
        }
         unordered_map <char,int>need;
         need['b']=1;
         need['a']=1;
         need['l']=2;
         need['o']=2;
         need['n']=1;
         int res=INT_MAX;
         for(auto i:need)
         {
            char c=i.first;
            int fneed=i.second;
            int fhave=have[c];
            int times=fhave/fneed;
            res=min(res,times);
         }
        return res;
    }
};