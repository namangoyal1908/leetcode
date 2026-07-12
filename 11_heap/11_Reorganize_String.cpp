// Problem: Reorganize String
// Link: https://leetcode.com/problems/reorganize-string/
// Difficulty: Medium
// Pattern: Heap (Greedy + Max Heap)

// Approach:
// - Build frequency map for all characters
// - Push all {freq, char} pairs into a MAX heap → most frequent char
//   always at the top
// - Greedily place the most frequent character at each position
//   → ensures no two adjacent characters are same as long as possible

// Two cases per iteration:
// - Case 1: heap top character != last placed character (res[seat-1])
//   → safe to place it → push, decrement freq, re-push if freq > 0
// - Case 2: heap top character == last placed character (would be adjacent)
//   → can't place it → take the SECOND most frequent (pq.top() after pop)
//   → place that instead → re-push both back to heap
//   → if no second character exists (pq.empty()) → impossible → return ""
//
// Why MAX heap?
// - Always want to place the MOST frequent character first
// - Reduces the chance of running out of room for that character
// - Greedy: most frequent first minimizes adjacency conflicts
//
// Why track 'seat' (current position)?
// - Used to check res[seat-1] (last placed character)
// - Also doubles as result string length tracker
//
// When to return ""?
// - If the most frequent character is stuck (same as last placed) AND
//   no other character is available → impossible to reorganize → ""
// - This happens when one character's frequency > ceil(n/2)
//
// Time: O(n log k) where k = distinct characters | Space: O(k)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int seat =0;
        int n= s.size();
        string res ;
         unordered_map<char,int> f;
         priority_queue<pair<int,char>>pq;
        for(int i=0;i<n;i++){
            f[s[i]]++;
         }
        for (auto i : f) {
            pq.push({i.second, i.first});   
        }
        while(!pq.empty()){
            pair<int,char> p = pq.top();
            pq.pop();
            if(seat==0||res[seat-1]!=p.second){
                res.push_back(p.second);
                seat++;
                p.first--;
                if(p.first>0){
                    pq.push(p);}
            }
        // if (a,1 ) and (b,1 )
        // same frequency
            else {
                if(pq.empty()){
                    return "";
                }
                pair<int ,char>p2=pq.top();
                pq.pop();
                res.push_back(p2.second);
                seat++;
                p2.first--;
                if(p2.first>0){
                    pq.push(p2);}
                pq.push(p);
            }
        }return res;
    }
};