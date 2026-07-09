// Problem: K Closest Points to Origin
// Link: https://leetcode.com/problems/k-closest-points-to-origin/
// Difficulty: Medium
// Pattern: Heap
//
// How distance is measured:
// - Euclidean distance = sqrt(x²+y²) but sqrt is expensive
// - Since we only COMPARE distances (not need actual values),
//   we can use SQUARED distance (x²+y²) directly → avoids sqrt
// - Comparison result stays the same: if d1 < d2 then d1² < d2²
//
// Why store index instead of the point itself in the pair?
// - pair = {squared_distance, index} not {squared_distance, point}
// - Storing index is lighter and lets us retrieve the full point
//   from the original array at the end
// - Avoids copying vector<int> into the heap on every push
//
// Approach (MAX heap of size k):
// - MAX heap keeps the LARGEST distance at the top
// - Fill first k points directly into heap
// - For remaining points:
//   → if new point's distance >= heap top → farther than all k current
//     candidates → skip (can't be in k closest)
//   → if new point's distance < heap top → closer than the current
//     farthest among k → pop farthest, push new point
// - At the end heap contains k closest points → extract and return
//
// Why MAX heap for CLOSEST k (not MIN heap)?
// - We want to REMOVE the farthest among k candidates when a closer
//   point arrives → MAX heap gives O(1) access to the farthest
// - Same pattern as Kth Largest: MIN heap for top k largest,
//   MAX heap for top k smallest/closest
//
// Time: O(n log k) | Space: O(k)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq; 
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            int squared_distance = (x * x) + (y * y);
            pair<int, int> curr = {squared_distance, i}; 
            if (pq.size() < k) {
                pq.push(curr);
            } 
            else if (squared_distance < pq.top().first) {
                pq.pop(); 
                pq.push(curr); 
            }
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            int index = pq.top().second; 
            res.push_back(points[index]); 
            pq.pop();
        }
        return res;
    }
};