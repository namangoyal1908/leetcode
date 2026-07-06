// Problem: Kth Smallest Element
// Link: https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
// Difficulty: Easy
// Pattern: Heap
//
// Approach (Max Heap of size k):
// - Push first k elements into a MAX heap
// - For every remaining element:
//   → if arr[i] >= heap top → it's bigger than or equal to the k-th
//     smallest so far → skip it (can't be in top k smallest)
//   → if arr[i] < heap top → it's smaller than current largest among
//     our k candidates → pop the top (too large), push arr[i]
// - After processing all elements, the MAX heap contains the k SMALLEST
//   elements seen so far, and the TOP of the heap is the LARGEST among
//   them → which is exactly the kth smallest overall
//
// Why MAX heap instead of MIN heap?
// - With a MIN heap you'd need to process all n elements and pop k times
// - With a MAX heap of size k, the top always tells us the CURRENT kth
//   smallest → we only replace when we find something smaller
// - Keeps heap size exactly k throughout → efficient
//
// Why does heap top = kth smallest at the end?
// - Heap holds the k smallest elements seen
// - The largest of those k smallest elements = kth smallest overall
// - MAX heap top = largest in heap = kth smallest
//
// Time: O(n log k) → each insertion/deletion on heap of size k is O(log k)
// Space: O(k) for the heap

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
     priority_queue<int>pq;
     int n= arr.size();
     for(int i=0;i<k;i++){
         pq.push(arr[i]);
     }
      for(int i=k;i<n;i++){
        if(arr[i]>=pq.top()){
            continue;
        }
        else{
            pq.pop();
            pq.push(arr[i]);
            
        }
     }return pq.top();
       
    }
};