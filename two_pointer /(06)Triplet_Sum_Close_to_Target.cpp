// Problem: Three Sum Closest
// Link: https://leetcode.com/problems/3sum-closest/
// Difficulty: Medium
// Pattern: Two Pointers
//
// How is it different from Three Sum?
// - Three Sum: find ALL triplets that sum to EXACTLY 0
// - Three Sum Closest: find ONE triplet whose sum is CLOSEST to target
//
// Key Differences:
// 1. No duplicate handling needed → only tracking ONE best answer
// 2. Instead of checking sum == 0, we check sum == target
// 3. Every move (p1++ or p2--) we calculate diff = |target - sum|
//    and update closestSum if we found a better (smaller) difference
// 4. No result vector needed → just track minDiff and closestSum
// 5. Early return if exact match found (diff == 0)
//
// Core Idea (same as Three Sum):
// - Sort array
// - Fix nums[i] as first element
// - Use two pointers p1 and p2 for remaining two elements
// - If sum > target → p2-- (decrease sum)
// - If sum < target → p1++ (increase sum)
// - If sum == target → return immediately (can't get closer than 0 diff)
//
// Extra logic added vs Three Sum:
// - Track minDiff = smallest difference seen so far
// - Track closestSum = sum that gave the smallest difference
// - Update both whenever current diff < minDiff
//
// Time: O(n²) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int l = nums.size();
        int sum = 0;
        int closestSum = 0;
        int minDiff = INT_MAX;  // start with max possible difference

        for (int i = 0; i < l - 2; i++) {

            // Skip duplicate fixed elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int* p1 = &nums[i + 1];  // left pointer
            int* p2 = &nums[l - 1];  // right pointer

            while (p1 < p2) {

                sum = nums[i] + *p1 + *p2;

                if (sum == target) {
                    return sum;  // exact match → can't get closer
                }
                else if (sum > target) {
                    // sum too big → track closest and move right pointer left
                    int diff = abs(target - sum);
                    if (diff < minDiff) {
                        minDiff = diff;
                        closestSum = sum;
                    }
                    p2--;
                }
                else {
                    // sum too small → track closest and move left pointer right
                    int diff = abs(target - sum);
                    if (diff < minDiff) {
                        minDiff = diff;
                        closestSum = sum;
                    }
                    p1++;
                }
            }
        }

        return closestSum;
    }
};