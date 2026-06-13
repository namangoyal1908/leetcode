// Problem: Maximum Absolute Sum of Any Subarray
// Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
// Difficulty: Medium
// Pattern: Kadane's Algorithm (Extended)
//
// Key Insight (self-discovered ):
// - |sum| is maximum when sum is either maximum positive OR maximum negative
// - So track BOTH maximum subarray sum and minimum subarray sum
// - Answer = max(maxSum, |minSum|)
//
// Two Kadane's running simultaneously:
// - maxStart → best positive subarray ending at i
// - minStart → best negative subarray ending at i
// - maxi → global maximum sum
// - mini → global minimum sum (most negative)
//
// Three candidates at every index:
// - v1 = start fresh → nums[i]
// - v2 = extend max → nums[i] + maxStart
// - v3 = extend min → nums[i] + minStart
//
// At the end:
// - mini = most negative sum → abs value could be answer
// - maxi = most positive sum → could be answer
// - return max(maxi, |mini|)
//
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int minStart = nums[0];  // best negative subarray ending here
        int maxStart = nums[0];  // best positive subarray ending here
        int maxi = nums[0];      // global maximum sum
        int mini = nums[0];      // global minimum sum

        for (int i = 1; i < n; i++) {
            int v1 = nums[i];              // start fresh
            int v2 = nums[i] + maxStart;   // extend max subarray
            int v3 = nums[i] + minStart;   // extend min subarray

            minStart = min(v1, v3);        // best negative ending at i
            mini = min(mini, minStart);

            maxStart = max(v1, v2);        // best positive ending at i
            maxi = max(maxi, maxStart);
        }

        mini = (-1) * mini;  // convert to absolute value

        return max(mini, maxi);
    }
};