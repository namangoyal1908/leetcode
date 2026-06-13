// Problem: Maximum Subarray Sum
// Link: https://leetcode.com/problems/maximum-subarray/
// Difficulty: Easy
// Pattern: Kadane's Algorithm
//
// Brute Force: O(n²)
// - Two loops → fix start, expand end, track max sum
//
// Kadane's Algorithm:
// - At every index ask: should I extend previous subarray or start fresh?
// - v1 = extend → maxEnding + nums[i]
// - v2 = start fresh → nums[i] alone
// - Pick whichever is bigger → that's best subarray ending at index i
// - Track global maximum across all positions
//
// Why start fresh sometimes?
// - If previous sum is negative → it only drags us down
// - Better to start new subarray from current element
// - Kadane's captures this naturally via max(v1, v2)
//
// Why initialize with nums[0] not 0?
// - Array can have all negatives → answer could be negative
// - Initializing with 0 would give wrong answer
//
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEnding = nums[0];  // best subarray sum ending at current index
        int maxi = nums[0];       // best sum seen anywhere in the array
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            int v1 = maxEnding + nums[i];  // extend previous subarray
            int v2 = nums[i];              // start fresh from current index

            // best subarray ending at i
            maxEnding = max(v1, v2);

            // update global maximum
            maxi = max(maxi, maxEnding);
        }

        return maxi;
    }
};