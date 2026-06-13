// Problem: Maximum Sum Circular Subarray
// Link: https://leetcode.com/problems/maximum-sum-circular-subarray/
// Difficulty: Hard
// Pattern: Kadane's Algorithm (Extended)
//
// Two cases for circular subarray:
// Case 1: Max subarray does NOT wrap around → normal Kadane's → answer = maxi
// Case 2: Max subarray WRAPS around → elements in middle are minimum subarray
//         → answer = totalSum - minSubarraySum
//
// Why total - mini works for wrap around?
// - Wrapped subarray = all elements EXCEPT the minimum middle subarray
// - So wrapped max = sum - minimum subarray sum
//
// Both Kadane's running simultaneously:
// - bestEnding → max subarray ending at i (Case 1)
// - minEnding  → min subarray ending at i (Case 2)
// - maxi → global max subarray sum
// - mini → global min subarray sum
// - sum → total array sum
//
// Edge case: all elements negative
// - mini = entire array → sum - mini = 0 (wrong!)
// - maxi < 0 means all elements negative → return maxi directly
// - Can't use circular case here
//
// Final answer = max(maxi, sum - mini)
//
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int bestEnding = nums[0];  // max subarray ending at current index
        int minEnding = nums[0];   // min subarray ending at current index
        int maxi = nums[0];        // global max subarray sum
        int mini = nums[0];        // global min subarray sum
        int sum = nums[0];         // total array sum

        for (int i = 1; i < n; i++) {
            sum += nums[i];

            int v1 = nums[i];               // start fresh
            int v2 = nums[i] + bestEnding;  // extend max
            int v3 = nums[i] + minEnding;   // extend min

            bestEnding = max(v1, v2);
            maxi = max(bestEnding, maxi);

            minEnding = min(v1, v3);
            mini = min(minEnding, mini);
        }

        // Edge case: all elements negative → circular case invalid
        if (maxi < 0)
            return maxi;

        // Case 1: maxi (no wrap) vs Case 2: sum - mini (wrap around)
        return max(maxi, sum - mini);
    }
};