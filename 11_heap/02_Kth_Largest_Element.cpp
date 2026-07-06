// Problem: Kth Largest Element
// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Difficulty: Medium
// Pattern: Heap
//
// How is it different from Kth Smallest?
// - Kth Smallest: MAX heap of size k → top is the largest of k smallest
// - Kth Largest:  MIN heap of size k → top is the smallest of k largest
// - Literally mirror image logic — just flip heap type and comparison
//
// Approach (Min Heap of size k):
// - Push first k elements into a MIN heap
// - For every remaining element:
//   → if nums[i] <= heap top → it's smaller than or equal to the current
//     kth largest → skip it (can't be in top k largest)
//   → if nums[i] > heap top → it's larger than current smallest among
//     our k candidates → pop the top (too small), push nums[i]
// - After processing all elements, MIN heap contains the k LARGEST
//   elements, and TOP of heap is the SMALLEST among them
//   → which is exactly the kth largest overall
//
// Why MIN heap top = kth largest at the end?
// - Heap holds the k largest elements seen
// - The smallest of those k largest elements = kth largest overall
// - MIN heap top = smallest in heap = kth largest
//
// Time: O(n log k) | Space: O(k)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,greater<int>>pq;
        int n= nums.size();
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
     }
        for(int i=k;i<n;i++){
            if(nums[i]<=pq.top()){
                continue;
        }
            else{
                pq.pop();
                pq.push(nums[i]);
        }
     }return pq.top();
    }
};