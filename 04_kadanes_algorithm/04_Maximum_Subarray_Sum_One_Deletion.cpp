// Problem: Maximum Subarray Sum with One Deletion
// Link: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
// Difficulty: Medium
// Pattern: Kadane's Algorithm (Extended)
//
// Two states tracked at every index:
// - nodlt  → max subarray sum ending at i with NO deletion used
// - onedlt → max subarray sum ending at i with ONE deletion used
//
// Transitions:
// - nodlt = max(arr[i], nodlt + arr[i])
//   → standard Kadane's, no deletion involved
//
// - onedlt = max(preonedlt + arr[i], prenodlt)
//   → either extend previous one-deletion subarray with arr[i]
//   → OR delete current arr[i] (take prenodlt, skip current element)
//
// Why store prenodlt and preonedlt?
// - Both nodlt and onedlt update in same iteration
// - Need previous values before update to compute new values correctly
// - Without storing prev → we'd use already-updated values → wrong answer
//
// Edge case: onedlt initialized to INT_MIN
// - At i=0 no deletion has happened yet → onedlt undefined
// - First valid onedlt is at i=1 → either delete arr[1] or delete arr[0]
// - If preonedlt == INT_MIN → can't extend → v3 = arr[i] (delete previous)
//
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int onedlt = INT_MIN;  // max sum ending here with one deletion used
        int nodlt = arr[0];    // max sum ending here with no deletion
        int n = arr.size();
        int res = arr[0];

        for (int i = 1; i < n; i++) {
            int prenodlt = nodlt;    // save before update
            int preonedlt = onedlt;  // save before update

            int v1 = arr[i];          // start fresh
            int v2 = nodlt + arr[i];  // extend no-deletion subarray
            nodlt = max(v1, v2);

            // extend one-deletion subarray OR delete current element
            int v3;
            if (preonedlt == INT_MIN)
                v3 = arr[i];               // no previous one-deletion state
            else
                v3 = preonedlt + arr[i];   // extend one-deletion subarray

            onedlt = max(v3, prenodlt);    // max of extend or delete arr[i]

            res = max(res, max(onedlt, nodlt));
        }

        return res;
    }
};