// Problem: IPO
// Link: https://leetcode.com/problems/ipo/
// Difficulty: Hard
// Pattern: Heap (Greedy + Sort + Max Heap)
//
// Problem in simple terms:
// - You have initial capital w and can do at most k projects
// - Each project requires minimum capital to START and gives a profit
// - Pick projects to MAXIMIZE final capital
//
// Approach (Sort + Max Heap):
// - Pair each project as {capital_required, profit} and SORT by capital
//   → so projects we can afford are always at the front of the sorted list
// - Use a MAX heap to always pick the MOST PROFITABLE available project
//
// Two pointer style logic inside while(k--):
// - Inner while: push ALL projects we can currently AFFORD (capital[i] <= w)
//   into the MAX heap → these are our "available" choices right now
//   → use idx to avoid re-processing already seen projects
//   → break as soon as we hit a project we can't afford (sorted by capital)
// - After inner while: pq contains all currently affordable projects
//   → pick the most profitable (pq.top()) → add profit to w → pop
// - If pq is empty after inner while → no affordable project exists
//   → can't do anything even with remaining k turns → return w early

// Why sort by capital and use idx (not re-scan every turn)?
// - Re-scanning all n projects every turn = O(kn) → slow
// - Since projects sorted by capital and w only INCREASES, any project
//   affordable before is still affordable → idx never goes back
//   → idx only moves forward → O(n) total across all k iterations

// Why MAX heap for profits?
// - Always want to pick the HIGHEST profit available project
// - More profit now = more capital = unlocks more projects next turn
//   (greedy: maximize current gain to maximize future options)
//
// Time: O(n log n) sort + O((n+k) log n) heap operations
// Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n= profits.size();
        vector <pair<int,int>>proj;
        for (int i=0;i<n;i++){
            proj.push_back({capital[i],profits[i]});
        }
        sort(proj.begin(),proj.end());
        priority_queue<int>pq;
        int idx=0;

        while(k--){
            while(idx<n){
                if(proj[idx].first>w){
                    break;
                }
                pq.push(proj[idx].second);
                idx++;
            }
            if(pq.empty()){
                return w;
            }
            w=w+pq.top();
            pq.pop();
        }
        return w;
    }
};