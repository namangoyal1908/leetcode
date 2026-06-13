// Problem: Maximum Product Subarray
// Link: https://leetcode.com/problems/maximum-product-subarray/
// Difficulty: Medium
// Pattern: Kadane's Algorithm (Modified)
//
// Why can't we just track maxEnding like sum version?
// - Negative × Negative = Positive → minimum can flip to maximum!
// - So current minimum ending could become best if multiplied by negative
// - Must track BOTH minEnding and maxEnding at every index
//
// Three candidates at every index:
// - v1 = minEnding × nums[i] → min flips to max if nums[i] is negative
// - v2 = nums[i]             → start fresh
// - v3 = maxEnding × nums[i] → max stays max if nums[i] is positive
//
// maxEnding = max(v1, v2, v3) → best product ending here
// minEnding = min(v1, v2, v3) → worst product ending here (needed for future)
//
// Key difference from Sum version:
// - Sum: only 2 candidates (extend or start fresh)
// - Product: 3 candidates (min×curr, curr, max×curr)
// - Sum: only track maxEnding
// - Product: track BOTH minEnding and maxEnding
//
// Why track minEnding?
// - If next number is negative → minEnding × negative = large positive
// - Without tracking min → we'd miss this case
//
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int minEnding = nums[0];  // minimum product ending at current index
        int maxEnding = nums[0];  // maximum product ending at current index
        int prod = nums[0];       // global maximum product

        for (int i = 1; i < n; i++) {
            int v1 = minEnding * nums[i];  // min flips if nums[i] negative
            int v2 = nums[i];              // start fresh
            int v3 = maxEnding * nums[i];  // max extends if nums[i] positive

            maxEnding = max(v2, max(v1, v3));  // best product ending at i
            minEnding = min(v2, min(v1, v3));  // worst product ending at i

            prod = max(prod, maxEnding);  // update global maximum
        }

        return prod;
    }
};