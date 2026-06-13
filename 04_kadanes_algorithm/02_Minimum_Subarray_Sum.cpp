// Problem: Minimum Subarray Sum
// Link: https://www.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1
// Difficulty: Easy
// Pattern: Kadane's Algorithm (Inverted)
//
// How is it different from Maximum Subarray Sum?
// - Maximum: max(v1, v2) → extend if it INCREASES sum
// - Minimum: min(v1, v2) → extend if it DECREASES sum
// - maxi → mini (tracking minimum instead of maximum)
// - Everything else is identical → just flip max to min
//
// Same logic applies:
// - v1 = extend previous subarray → bestEnding + a[i]
// - v2 = start fresh → a[i] alone
// - If previous sum is positive → it only pulls sum up → start fresh
// - If previous sum is negative → extend it → makes sum smaller
//
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestSumSubarray(vector<int>& a) {
        int bestEnding = a[0];  // best (minimum) subarray sum ending at current index
        int mini = a[0];        // best minimum sum seen anywhere in array
        int n = a.size();

        for (int i = 1; i < n; i++) {
            int v1 = bestEnding + a[i];  // extend previous subarray
            int v2 = a[i];               // start fresh from current index

            // best minimum subarray ending at i
            bestEnding = min(v1, v2);

            // update global minimum
            mini = min(mini, bestEnding);
        }

        return mini;
    }
};