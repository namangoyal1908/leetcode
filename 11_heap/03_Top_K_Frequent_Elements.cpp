// Problem: Top K Frequent Elements
// Link: https://leetcode.com/problems/top-k-frequent-elements/
// Difficulty: Medium
// Pattern: Heap
//
// Approach:
// - Build frequency map first → f[element] = count
// - Use a MIN heap of size k storing {freq, element} pairs
// - Custom comparator cmp sorts by frequency (ascending for min heap)
//   → heap top is always the LEAST frequent among our k candidates
//
// Custom comparator cmp:
// - Compares pairs by frequency first (a.first vs b.first)
// - If frequencies equal → compare by element value (a.second vs b.second)
// - Returns true when a > b → makes it a MIN heap (smallest freq at top)
//
// Why store {freq, element} pair instead of just element?
// - Need to compare by FREQUENCY not by element value
// - Pairing freq with element lets the heap order by freq naturally
// - Heap top = {min_freq, element} among current k candidates
//
// Heap logic (same pattern as Kth Smallest/Largest):
// - Fill heap with first k elements directly
// - For remaining elements:
//   → if curr.freq < heap top's freq → can't be in top k → skip
//   → otherwise → pop the least frequent, push current
// - At the end heap contains the k most frequent elements
//
// Why MIN heap for TOP k frequent (not MAX heap)?
// - We want to KEEP the k largest frequencies → need to easily REMOVE
//   the smallest among our k candidates when a better one arrives
// - MIN heap gives O(1) access to the smallest → perfect for this
//
// Time: O(n log k) | Space: O(n) for frequency map + O(k) for heap

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct cmp{bool operator()(pair<int,int>& a,pair<int,int>&b){
        if(a.first!=b.first){
            return a.first>b.first;}
        return a.second>b.second;}
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        unordered_map<int,int>f;
        for(int i=0;i<n;i++){
            f[nums[i]]++;
        }
        for(auto i:f){
            int element=i.first;
            int freq=i.second;
            pair<int,int>curr={freq,element};
            if(pq.size()<k){
                pq.push(curr);
                continue;
            }
            if(curr.first<pq.top().first){
                continue;
            }
            pq.pop();
            pq.push(curr);
        }
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }return res;
    }
};