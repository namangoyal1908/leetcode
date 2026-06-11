// Problem: Longest Subarray with Ones after Replacement
// Link: https://leetcode.com/problems/max-consecutive-ones-iii/
// Difficulty: Hard
// Pattern: Sliding Window (Variable Size) + Frequency Array
//
// Problem in simple terms:
// - You can flip at most k zeros to ones
// - Find longest subarray with all ones after flipping
//
// Key Insight:
// - Track count of zeros in window → f[0]
// - If f[0] > k → too many zeros → need more than k flips → invalid
// - Shrink until f[0] <= k
//
// Why int f[2] instead of HashMap?
// - Array only has 0s and 1s → only 2 possible values
// - f[0] = count of zeros in window
// - f[1] = count of ones in window
// - Simple array f[2] is faster and cleaner than unordered_map
//
// How is it different from previous problems?
// - Fruits into Baskets: f.size() > 2 → too many distinct types
// - K Distinct: f.size() > k → too many distinct chars
// - This: f[0] > k → too many zeros specifically
// - We don't care about distinct count → just zero count
//
// Invalid condition:
// - f[0] > k → zeros in window exceed flip limit → shrink
//
// Answer updates every iteration:
// - After while → window always valid (f[0] <= k)
// - Every valid window is candidate for max length
//
// Time: O(n) | Space: O(1) → fixed size array of 2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int high = 0;
        int low = 0;
        int f[2] = {0};  // f[0] = zero count, f[1] = one count
        int res = INT_MIN;
        int n = nums.size();

        for (high = 0; high < n; high++) {
            f[nums[high]]++;  // EXPAND → add element to window

            // SHRINK → too many zeros (exceeds flip limit k)
            while (f[0] > k) {
                f[nums[low]]--;
                low++;
            }

            // Valid window → update result
            int len = high - low + 1;
            res = max(len, res);
        }

        return res;
    }
};