// Problem: Minimum Size Subarray Sum
// Link: https://leetcode.com/problems/minimum-size-subarray-sum/
// Difficulty: Easy
// Pattern: Sliding Window (Variable Size)
//
// Brute Force: O(n²)
// - Two nested loops → fix left, expand right until sum >= target
// - Track minimum length found
// - For every left position, scan all possible right positions
// - Too slow for large inputs
//
// Variable Sliding Window - Microsoft Hiring Analogy 
//
// Imagine Microsoft has a project that needs sum >= target work done:
// - They keep HIRING employees one by one from right (right++)
//   until total work done >= target → project complete 
//
// - Once project is complete → start FIRING from the oldest hire (left++)
//   to minimize team size (find smallest subarray)
//
// - Keep firing as long as remaining team can still finish the project
//   (sum >= target) → record team size each time
//
// - The moment firing breaks the project (sum < target) →
//   stop firing → start hiring again from right
//
// - Answer = smallest team size that ever completed the project
//
// right++ = hire a new employee (expand window)
// left++  = fire oldest employee (shrink window)
// sum >= target = project is complete (valid window)
// ans = minimum team size that completed the project
//
// Key difference from Fixed Window:
// - Fixed: hire exactly k people always, just rotate
// - Variable: hire/fire dynamically based on whether project is done
//
// Time: O(n) | Space: O(1)
// Each employee is hired once (right++) and fired once (left++) → O(2n) = O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;       // oldest employee (firing starts here)
        long long sum = 0;  // total work done by current team
        int ans = INT_MAX;  // smallest team that completed the project

        for (int right = 0; right < n; right++) {
            sum += nums[right];  // HIRE → new employee joins team

            while (sum >= target) {
                // Project complete → record current team size
                ans = min(ans, right - left + 1);

                sum -= nums[left];  // FIRE → oldest employee leaves
                left++;
            }
            // Project incomplete → hire more (right++ in for loop)
        }

        return (ans == INT_MAX) ? 0 : ans;  // 0 if project never completed
    }
};