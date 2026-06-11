// Problem: Minimum Size Subarray Sum
// Link: https://leetcode.com/problems/minimum-size-subarray-sum/
// Difficulty: Easy
// Pattern: Sliding Window (Variable Size)
//
// Brute Force: O(n²)
// - Two nested loops → fix left, expand right until sum >= target
// - Track minimum length found
//
// Key Template Difference from previous problems:
// - Previous problems: record answer OUTSIDE while loop (after shrinking)
// - This problem: record answer INSIDE while loop (while condition is MET)
//
// Why answer inside while loop here?
// - We want MINIMUM length → keep shrinking as long as sum >= target
// - Every time condition is still valid → try to shrink more → update ans
// - Previous problems wanted MAXIMUM → record once, then shrink to fix
// - Here condition is: sum >= target → valid → record → try to shrink more
//
// Condition breakdown:
// - EXPAND right → add nums[right] to sum
// - while sum >= target → valid window found
//   → record minimum length       ← answer updated INSIDE while
//   → shrink from left (subtract nums[left], left++)
//   → keep shrinking until sum < target
//
// Edge case:
// - If ans never updated → no valid window exists → return 0
// - ans == INT_MAX means target was never reached
//
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        long long sum = 0;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += nums[right];  // EXPAND → add element to window

            // SHRINK → condition is MET → record and try to minimize
            while (sum >= target) {
                ans = min(ans, right - left + 1);  // record inside while
                sum -= nums[left];
                left++;
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};